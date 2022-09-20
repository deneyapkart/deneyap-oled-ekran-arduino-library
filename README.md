# Deneyap OLED Display Arduino Library
[FOR TURKISH VERSION || TÜRKÇE İÇİN TIKLAYIN](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap OLED Display Module SSD1306

## :mag_right:Specifications 
- `Product ID` **M09**, **mpv1.0** 
- `MCU` SSD1306 display
- `Weight`
- `Module Dimension` 25,4 mm x 38,1 mm
- `I2C address` 0x7A, 0x78 

| Address |  | 
| :---      | :---     |
| 0x7A | default address |
| 0x78 | address when ADR1 pad is shorted |

## :closed_book:Documentation
[Deneyap OLED Display](https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-oled-ekran-m09)

[Deneyap OLED Display Mechanical Drawing](https://cdn.deneyapkart.org/media/upload/userFormUpload/wT6dViZ5y4WdwdZkzbxM9t2vsJTwDkks.pdf)

[SSD1306-datasheet](https://www.wisechip.com.tw/en/product-609620/0-96%E2%80%9D-OLED-Display.html)

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap OLED Display
This Arduino library allows you to use Deneyap OLED SSD1306 0.96" 128x64 pixel black blue display module with I2C peripheral. You can use this library in your projects with any Arduino compatible board with I2C peripheral.

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.0.3 - update function(`begin`), add new functions(`init`, `setHorizontalScrollProperties`) and sketches(`EkranParlakligiDegistirme`, `KayanYazi`, `T3Logo`)

1.0.2 - change function name from `putNumber` to `putInt` and update text info

1.0.1 - update library.properties file

1.0.0 - initial release

## :rocket:Hardware Connections
- Deneyap OLED Display module and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

| OLED Display | Function | Board pins |
| :---:      |   :---  | :---      |
| 3.3V       | Power   | 3.3V      |
| GND        | Ground  | GND       |
| SDA        | I2C Data  |SDA pin  |
| SCL        | I2C Clock |SCL pin  |
| NC         | no connection||

## :bookmark_tabs:License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library/blob/master/LICENSE) file for license information.