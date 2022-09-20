/*
*****************************************************************************
@file         Deneyap_OLED.h
@mainpage     Deneyap OLED Display Module SSD1306 Arduino library header file
@version      v1.0.3
@date         September 20, 2022
@brief        This file contains all function prototypes and macros
              for Deneyap OLED Display Module SSD1306 Arduino library
*****************************************************************************
*/

#ifndef __DENEYAP_OLED_H
#define __DENEYAP_OLED_H

#include <Wire.h>

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifdef __AVR__
#include <avr/pgmspace.h>
#define OLEDFONT(name) static const uint8_t __attribute__((progmem)) _n[]
#elif defined(ESP8266)
#include <pgmspace.h>
#define OLEDFONT(name) static const uint8_t name[]
#else
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#define OLEDFONT(name) static const uint8_t name[]
#endif

#include "fonts/font8x8.h"
#include "fonts/font5x7.h"

#define SSD1306_Max_X   127 // 128 Pixels
#define SSD1306_Max_Y   63  // 64  Pixels

#define PAGE_MODE       01
#define HORIZONTAL_MODE 02

#define SSD1306_Command_Mode          0x80
#define SSD1306_Data_Mode             0x40
#define SSD1306_Display_Off_Cmd       0xAE
#define SSD1306_Display_On_Cmd        0xAF
#define SSD1306_Normal_Display_Cmd    0xA6
#define SSD1306_Inverse_Display_Cmd   0xA7
#define SSD1306_Activate_Scroll_Cmd   0x2F
#define SSD1306_Dectivate_Scroll_Cmd  0x2E
#define SSD1306_Set_Brightness_Cmd    0x81

#define Scroll_Left   0x00
#define Scroll_Right  0x01

#define Scroll_2Frames    0x7
#define Scroll_3Frames    0x4
#define Scroll_4Frames    0x5
#define Scroll_5Frames    0x0
#define Scroll_25Frames   0x6
#define Scroll_64Frames   0x1
#define Scroll_128Frames  0x2
#define Scroll_256Frames  0x3

class OLED {

public:
  char addressingMode;
  bool begin(uint8_t address, TwoWire &wirePort = Wire);
  void init(void);
  void setFont(const uint8_t *font, bool inverse = false);
  void clearDisplay();
  void sendCommand(unsigned char command);
  void readCommand(unsigned char Data);
  void setBrightness(unsigned char Brightness);
  void setHorizontalMode();
  void setPageMode();
  void setTextXY(unsigned char Row, unsigned char Column);
  bool putChar(unsigned char c);
  void putString(const char *string);
  void putString(String string);
  unsigned char putInt(long n);
  unsigned char putNumber(long n);
  unsigned char putFloat(float floatNumber, unsigned char decimal);
  unsigned char putFloat(float floatNumber);
  void drawBitmap(unsigned char *bitmaparray, int bytes);
  void activateScroll();
  void deactivateScroll();
  void setNormalDisplay();
  void setInverseDisplay();
  void setHorizontalScrollProperties(bool direction, unsigned char startPage, unsigned char endPage, unsigned char scrollSpeed);

private:
  uint8_t _address;
  const uint8_t *m_font;     // Current font.
  uint8_t m_font_offset = 2; // Font bytes for meta data.
  uint8_t m_font_width;      // Font witdth.
  uint8_t m_col;             // Cursor column.
  uint8_t m_row;             // Cursor row (RAM).
  bool m_inverse = false;    // Inverse text.
};

#endif  // End of __DENEYAP_OLED_H definition check