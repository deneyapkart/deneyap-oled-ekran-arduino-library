# Deneyap OLED Display Module SSD1306 Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap OLED Display Module SSD1306

## :mag_right:Specifications 
- `Product ID` **M09**, **mpv1.0** 
- `MCU` SSD1306 
- `Weight` 
- `Module Dimension`
- `I2C address` 0x7A, 0x78 

| Address |  | 
| :---      | :---     |
| 0x7A | default address |
| 0x78 | address when ADR1 pad is shorted |

## :closed_book:Documentation
Deneyap OLED Display Module SSD1306

[SSD1306-datasheet](https://www.digimax.it/media_import/DISPLAY/RAYSTAR%20OPTRONICS/DISPLAY%20OLED/REX012864DWPP3N00003/REX012864DWPP3N00003_DS_001.pdf)

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap OLED Display Module SSD1306
This Arduino library allows you to use Deneyap OLED SSD1306 0.96" 128x64 pixel black blue display module with I2C peripheral. You can print string, int, float type data with this library. You can use this library in your projects with any Arduino compatible board with I2C peripheral.

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.0.0 - initial release

1.0.1 - update library.properties file

## :rocket:Hardware Connections
- Deneyap OLED Display module and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

| OLED Display | Function | Board pins |
| :---:      |   :---  | :---      |
| 3.3V       | Power   | 3.3V      |
| GND        | Ground  | GND       |
| SDA        | I2C Data  |SDA pin  |
| SCL        | I2C Clock |SCL pin  |
| NC         | no connection|         |

## :bookmark_tabs:License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library/blob/master/LICENSE) file for license information.