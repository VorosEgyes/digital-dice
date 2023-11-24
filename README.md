# ATtiny13 Digital Dice

## Overview
This repository contains the Arduino code for a digital dice project using an ATtiny13 microcontroller. The digital dice simulates a rolling dice effect with LEDs and enters a power-saving mode when not in use.

## Features
- Dice rolling effect using LEDs.
- Power efficiency with ATtiny13 sleep mode.
- Button debouncing for reliable operation.
- Randomized dice results.

## Hardware Requirements
- ATtiny13 microcontroller
- LEDs (x4)
- Tactile pushbutton
- 100 ohm Resistors for LEDs
- 10K ohm Resistor for pullup reset
- 2xAAA Power supply (2.4-3V)
- (Optional) USBASP Programmer for ATtiny13
- (Optional) a 100nF ceramic condensator between VCC and GND

## Wiring

<img width="281" alt="Screenshot 2023-11-24 at 22 39 49" src="https://github.com/VorosEgyes/digital-dice/assets/69361851/ae5dc22b-e800-4465-bd64-4f9b8bfa3590">

## Software Setup
1. Use platformio
2. Connect the ATtiny13 to your computer via an USBASP Programmer.
3. Upload the code to the ATtiny13.

## Usage
Press the button to "roll" the dice. The LEDs will display a random number from 1 to 6. After displaying the result, the device will enter sleep mode to conserve power.

## Contributing
Contributions to this project are welcome! Please fork the repository and submit a pull request with your improvements.

## License
This project is licensed under the MIT License

## Acknowledgements
- Thanks to the Arduino and AVR communities for support and resources.
- Project inspired by http://www.avr-asm-tutorial.net/avr_en/apps/dice/dice_tn13/dice.html

