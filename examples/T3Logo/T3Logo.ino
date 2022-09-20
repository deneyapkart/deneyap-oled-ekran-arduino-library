/*
 *   T3Logo örneği,
 *   Deneyap OLED ekranına Türkiye Teknoloji Takımı Vakfı(T3)'nın logosunun yazdırılmaktadır.
 *   Her beş saniyede bir ekran rengi değişmektedir.
 *
 *   Bu ekran I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap OLED Ekran modülü için oluşturulmuştur
 *      ------> https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-oled-ekran-m09 <------
 *      ------> https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library  <------
*/
#include <Deneyap_OLED.h>                           // Deneyap OLED Ekran kütüphanesinin eklenmesi
#include "T3Logo.h"                                 // T3 Logosunun hex kodlarının olduğu .h dosyasının eklenmesi

OLED OLED;                                          // OLED için class tanımlanması

void setup() {
  Serial.begin(115200);                             // Seri haberleşme başlatılması
  if (!OLED.begin(0x7A)) {                          // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
    delay(3000);
    Serial.println("I2C bağlantısı başarısız ");    // I2C bağlantısı başarısız olursa seri terminale yazdırılması
  }
  OLED.clearDisplay();                              // OLED ekrandaki verilerin silinmesi
}

void loop() {
  OLED.setInverseDisplay();                        // Ekran renginin değiştirilmesi
  OLED.drawBitmap((unsigned char *)T3VAKFI, 1024); // T3 logosunun ekranına yazdırılması
  delay(5000);
  OLED.setNormalDisplay();                         // Ekran renginin değiştirilmesi
  delay(5000);
}
