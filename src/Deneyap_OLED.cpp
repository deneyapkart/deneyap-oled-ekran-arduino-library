/*
*****************************************************************************
@file         Deneyap_OLED.cpp
@mainpage     Deneyap OLED Display Module SSD1306 Arduino library source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.0.3
@date         September 20, 2022
@brief        Includes functions to control Deneyap OLED Display Module SSD1306
              Arduino library

Library includes:
--> Configuration functions
--> Data manipulation functions
--> I2C communication functions

*****************************************************************************
*/

#include "Deneyap_OLED.h"

/**
 * @brief  I2C initialization and read check
 * @param  adress: Device adress
 * @retval None
 **/
bool OLED::begin(uint8_t address, TwoWire &wirePort) {
  _address = address >> 1;
  Wire.begin();
  init();
  if (!Wire.endTransmission())
    return true;
  return false;
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::init(void) {
  sendCommand(0xAE); // display off
  sendCommand(0xA6); // Set Normal Display (default)
  sendCommand(0xAE); // DISPLAYOFF
  sendCommand(0xD5); // SETDISPLAYCLOCKDIV
  sendCommand(0x80); // the suggested ratio 0x80
  sendCommand(0xA8); // SSD1306_SETMULTIPLEX
  sendCommand(0x3F);
  sendCommand(0xD3);       // SETDISPLAYOFFSET
  sendCommand(0x0);        // no offset
  sendCommand(0x40 | 0x0); // SETSTARTLINE
  sendCommand(0x8D);       // CHARGEPUMP
  sendCommand(0x14);
  sendCommand(0x20); // MEMORYMODE
  sendCommand(0x00); // 0x0 act like ks0108
  sendCommand(0xA1); // SEGREMAP   Mirror screen horizontally (A0)
  sendCommand(0xC8); // COMSCANDEC Rotate screen vertically (C0)
  sendCommand(0xDA); // 0xDA
  sendCommand(0x12); // COMSCANDEC
  sendCommand(0x81); // SETCONTRAST
  sendCommand(0xCF); //
  sendCommand(0xd9); // SETPRECHARGE
  sendCommand(0xF1);
  sendCommand(0xDB); // SETVCOMDETECT
  sendCommand(0x40);
  sendCommand(0xA4); // DISPLAYALLON_RESUME
  sendCommand(0xA6); // NORMALDISPLAY
  clearDisplay();
  sendCommand(0x2E); // Stop scroll
  sendCommand(0x20); // Set Memory Addressing Mode
  sendCommand(0x00); // Set Memory Addressing Mode ab Horizontal addressing mode
  setFont(font8x8);
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::setFont(const uint8_t *font, bool inverse) {
  m_font = font;
  m_inverse = inverse;
  m_font_width = pgm_read_byte(&m_font[0]);
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::clearDisplay() {
  unsigned char i, j;
  sendCommand(SSD1306_Display_Off_Cmd); // display off
  for (j = 0; j < 8; j++) {
    setTextXY(j, 0); {
      for (i = 0; i < 16; i++) { // clear all columns
        putChar(' ');
      }
    }
  }
  sendCommand(SSD1306_Display_On_Cmd); // display on
  setTextXY(0, 0);
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::sendCommand(unsigned char command) {
  Wire.beginTransmission(_address); // begin I2C communication
  Wire.write(SSD1306_Command_Mode); // Set OLED Command mode
  Wire.write(command);
  Wire.endTransmission(); // End I2C communication
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::readCommand(unsigned char Data) {
  Wire.beginTransmission(_address); // begin I2C transmission
  Wire.write(SSD1306_Data_Mode);    // data mode
  Wire.write(Data);
  Wire.endTransmission(); // stop I2C transmission
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::setBrightness(unsigned char Brightness) {
  sendCommand(SSD1306_Set_Brightness_Cmd);
  sendCommand(Brightness);
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::setHorizontalMode() {
  addressingMode = HORIZONTAL_MODE;
  sendCommand(0x20); // set addressing mode
  sendCommand(0x00); // set horizontal addressing mode
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::setPageMode() {
  addressingMode = PAGE_MODE;
  sendCommand(0x20); // set addressing mode
  sendCommand(0x02); // set page addressing mode
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::setTextXY(unsigned char row, unsigned char col) {
  sendCommand(0xB0 + row);                                // set page address
  sendCommand(0x00 + (m_font_width * col & 0x0F));        // set column lower addr
  sendCommand(0x10 + ((m_font_width * col >> 4) & 0x0F)); // set column higher addr
}

/**
 * @brief
 * @param
 * @retval
 **/
bool OLED::putChar(unsigned char ch) {
  if (!m_font)
    return 0;
  // Ignore non-printable ASCII characters. This can be modified for
  // multilingual font.
  if (ch < 32 || ch > 127) {
    ch = ' ';
  }
  for (unsigned char i = 0; i < m_font_width; i++) {
    // Font array starts at 0, ASCII starts at 32
    readCommand(pgm_read_byte(&m_font[(ch - 32) * m_font_width + m_font_offset + i]));
  }
  return 1;
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::putString(const char *string) {
  unsigned char i = 0;
  while (string[i]) {
    putChar(string[i]);
    i++;
  }
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::putString(String string) {
  char char_array[string.length() + 1];
  string.toCharArray(char_array, sizeof(char_array));
  putString(char_array);
}

/**
 * @brief
 * @param
 * @retval
 **/
unsigned char OLED::putInt(long long_num) {
  unsigned char char_buffer[10] = "";
  unsigned char i = 0;
  unsigned char f = 0;

  if (long_num < 0) {
    f = 1;
    putChar('-');
    long_num = -long_num;
  }
  else if (long_num == 0) {
    f = 1;
    putChar('0');
    return f;
  }

  while (long_num > 0) {
    char_buffer[i++] = long_num % 10;
    long_num /= 10;
  }

  f = f + i;
  for (; i > 0; i--) {
    putChar('0' + char_buffer[i - 1]);
  }
  return f;
}

/**
 * @brief
 * @param
 * @retval
 **/
unsigned char OLED::putNumber(long long_num) {
  unsigned char char_buffer[10] = "";
  unsigned char i = 0;
  unsigned char f = 0;

  if (long_num < 0) {
    f = 1;
    putChar('-');
    long_num = -long_num;
  }
  else if (long_num == 0) {
    f = 1;
    putChar('0');
    return f;
  }

  while (long_num > 0) {
    char_buffer[i++] = long_num % 10;
    long_num /= 10;
  }

  f = f + i;
  for (; i > 0; i--) {
    putChar('0' + char_buffer[i - 1]);
  }
  return f;
}

/**
 * @brief
 * @param
 * @retval
 **/
unsigned char OLED::putFloat(float floatNumber, unsigned char decimal) {
  unsigned int temp = 0;
  float decy = 0.0;
  float rounding = 0.5;
  unsigned char f = 0;
  if (floatNumber < 0.0) {
    putString("-");
    floatNumber = -floatNumber;
    f += 1;
  }
  for (unsigned char i = 0; i < decimal; ++i) {
    rounding /= 10.0;
  }
  floatNumber += rounding;

  temp = floatNumber;
  f += putInt(temp);
  if (decimal > 0) {
    putChar('.');
    f += 1;
  }
  decy = floatNumber - temp;                  // decimal part,
  for (unsigned char i = 0; i < decimal; i++) { // 4
    decy *= 10;  // for the next decimal
    temp = decy; // get the decimal
    putInt(temp);
    decy -= temp;
  }
  f += decimal;
  return f;
}

/**
 * @brief
 * @param
 * @retval
 **/
unsigned char OLED::putFloat(float floatNumber) {
  unsigned char decimal = 2;
  unsigned int temp = 0;
  float decy = 0.0;
  float rounding = 0.5;
  unsigned char f = 0;
  if (floatNumber < 0.0) {
    putString("-");
    floatNumber = -floatNumber;
    f += 1;
  }
  for (unsigned char i = 0; i < decimal; ++i) {
    rounding /= 10.0;
  }
  floatNumber += rounding;

  temp = floatNumber;
  f += putInt(temp);
  if (decimal > 0) {
    putChar('.');
    f += 1;
  }
  decy = floatNumber - temp;                  // decimal part,
  for (unsigned char i = 0; i < decimal; i++) { // 4 
    decy *= 10;  // for the next decimal
    temp = decy; // get the decimal
    putInt(temp);
    decy -= temp;
  }
  f += decimal;
  return f;
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::drawBitmap(unsigned char *bitmaparray, int bytes) {
  char localAddressMode = addressingMode;
  if (addressingMode != HORIZONTAL_MODE) {
    // Bitmap is drawn in horizontal mode
    setHorizontalMode();
  }

  for (int i = 0; i < bytes; i++) {
    readCommand(pgm_read_byte(&bitmaparray[i]));
  }

  if (localAddressMode == PAGE_MODE) {
    // If pageMode was used earlier, restore it.
    setPageMode();
  }
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::setHorizontalScrollProperties(bool direction, unsigned char startPage, unsigned char endPage, unsigned char scrollSpeed) {
  if (Scroll_Right == direction) {
    // Scroll right
    sendCommand(0x26);
  } else {
    // Scroll left
    sendCommand(0x27);
  }
  sendCommand(0x00);
  sendCommand(startPage);
  sendCommand(scrollSpeed);
  sendCommand(endPage);
  sendCommand(0x00);
  sendCommand(0xFF);
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::activateScroll() {
  sendCommand(SSD1306_Activate_Scroll_Cmd);
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::deactivateScroll() {
  sendCommand(SSD1306_Dectivate_Scroll_Cmd);
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::setNormalDisplay() {
  sendCommand(SSD1306_Normal_Display_Cmd);
}

/**
 * @brief
 * @param
 * @retval
 **/
void OLED::setInverseDisplay() {
  sendCommand(SSD1306_Inverse_Display_Cmd);
}