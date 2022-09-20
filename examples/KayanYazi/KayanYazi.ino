/*
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap OLED ekranına DENEYAP KART GELISTIRME KARTLARI yazdırmaktadır.
 *   Yazıları sağa doğru kaymaktadır.
 *
 *   Bu ekran I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap OLED Ekran modülü için oluşturulmuştur
 *      ------> https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-oled-ekran-m09 <------
 *      ------> https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library  <------
*/
#include <Deneyap_OLED.h>                         // Deneyap OLED Ekran kütüphanesinin eklenmesi

OLED OLED;                                        // OLED için class tanımlanması

void setup() {
  Serial.begin(115200);                           // Seri haberleşme başlatılması
  if (!OLED.begin(0x7A)) {                        // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
    delay(3000);
    Serial.println("I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri terminale yazdırılması
  }
  OLED.clearDisplay();                            // OLED ekrandaki verilerin silinmesi
  OLED.setTextXY(1, 0);                           // Satır ve sütun ayarlanması
  OLED.putString(" DENEYAP KART ");               // DENEYAP KART yazdırılması
  OLED.setTextXY(3, 0);
  OLED.putString(" GELISTIRME ");
  OLED.setTextXY(5, 0);
  OLED.putString(" KARTLARI ");
  OLED.setTextXY(7, 0);
  OLED.putString("################");
}

void loop() {
  /*    Scroll_Right: yazı sağa doğru kayıyor.  Scroll_Left
   *    0,7: 0. satırdan 7. sütuna kadar
   *    Scroll_5Frames: yazının kayma hızı.     Scroll_2Frames, Scroll_3Frames, Scroll_4Frames, Scroll_5Frames, Scroll_25Frames, Scroll_64Frames, Scroll_128Frames, Scroll_256Frames */
  OLED.setHorizontalScrollProperties(Scroll_Right, 0, 7, Scroll_4Frames);
  OLED.activateScroll();
}
