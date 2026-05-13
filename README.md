# ESP32 Alarm Clock with LCD Display

An ESP32-based alarm system that displays time/date and triggers alerts at specific minutes.

## Features
- Real-time clock (RTC) with manual time setting
- 16x2 LCD display for time/date
- Customizable alert window (minutes 5-7)
- Serial monitor support for debugging

## Hardware Required
- ESP32 Development Board
- 16x2 LCD (compatible with Hitachi HD44780)
- Jumper wires

## Wiring
| LCD Pin | ESP32 Pin |
|---------|-----------|
| RS      | 15        |
| EN      | 4         |
| D4      | 5         |
| D5      | 18        |
| D6      | 19        |
| D7      | 21        |

## Circuit Diagram
![Circuit Diagram](circuit.png)

## Usage
The system shows current time and date. Between minutes 5-7 of each hour, it triggers an alert.

## Future Improvements
- Add buzzer for audio alerts
- Make alert time configurable via buttons
- Store time in EEPROM to survive reboots
---
**made by amiraligrr** https://amiraligrr.ir
**see also https://zp.amiraligrr.ir**
