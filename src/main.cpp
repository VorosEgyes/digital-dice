#include <Arduino.h>
#include <avr/sleep.h>

// Pin numbers for PORTB registers
#define LED_PIN0 PB0
#define LED_PIN1 PB1
#define LED_PIN2 PB2
#define LED_PIN3 PB3
#define BUTTON_PIN PB4

const uint8_t dicePatterns[7] = {
  0b0000, // All LEDs off
  0b0001, // Number 1: Only PB0
  0b0010, // Number 2: Only PB1
  0b0011, // Number 3: PB0 and PB1
  0b0110, // Number 4: PB1 and PB2
  0b0111, // Number 5: PB0, PB1 and PB2
  0b1110, // Number 6: PB1, PB2 and PB3
};

volatile bool buttonPressed = false;
volatile bool debounceInProgress = false;

void showResult() {
  int number = random(1, 7); // Random number between 1 and 6
  PORTB = (PORTB & 0xF0) | dicePatterns[number]; // Update only the lower 4 bits
}

void goToSleep() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();

  // MCU wakes up here after interrupt
  sleep_disable();
}

void setup() {
  DDRB |= (1 << LED_PIN0) | (1 << LED_PIN1) | (1 << LED_PIN2) | (1 << LED_PIN3);
  DDRB &= ~(1 << BUTTON_PIN);
  PORTB |= (1 << BUTTON_PIN); // Enable internal pull-up for button

  GIMSK |= (1 << PCIE); // Pin Change Interrupt Enable
  PCMSK |= (1 << BUTTON_PIN); // Enable interrupt for the button pin
  sei(); // Enable global interrupts

  PORTB &= 0xF0; // Ensure all LEDs are off at start
}

void loop() {
  if (buttonPressed) {
    for (int i = 0; i <= random(5,12); i++) {
      showResult();
      delay(60-i*4);
    }
    showResult();
    buttonPressed = false;
    delay(450); // Display result for 3 seconds
    PORTB &= 0xF0; // Turn off all LEDs
  }

  goToSleep(); // Go to sleep mode
}

ISR(PCINT0_vect) {
  if (!(PINB & (1 << BUTTON_PIN)) && !debounceInProgress) {
    debounceInProgress = true;
    delay(50); // Debounce delay
    debounceInProgress = false;
    buttonPressed = true;
  }
}
