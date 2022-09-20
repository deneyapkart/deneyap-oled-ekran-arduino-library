/*
 *   EkranParlakligiDegistirme örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap OLED ekranını Deneyap Kart yazdırmaktadır.
 *   Ekran parlaklığını beş yüz saniyede bir değiştirmektedir.
 *
 *   Bu ekran I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap OLED Ekran modülü için oluşturulmuştur
 *      ------> https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-oled-ekran-m09 <------
 *      ------> https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library  <------
*/
#include <Deneyap_OLED.h>                         // Deneyap OLED Ekran kütüphanesinin eklenmesi

OLED OLED;                                        // OLED için class tanımlanması

unsigned char brightness = 0;

void setup() {
  Serial.begin(115200);                           // Seri haberleşme başlatılması
  if (!OLED.begin(0x7A)) {                        // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
    delay(3000);
    Serial.println("I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri terminale yazdırılması
  }
  OLED.setInverseDisplay();                       // Ekran renginin değiştirilmesi
  OLED.clearDisplay();                            // OLED ekrandaki verilerin silinmesi
  OLED.setTextXY(3, 1);                           // Satır sayısı ve sütun sayısı ayarlanması
  OLED.putString(" Deneyap Kart ");               // Deneyap Kart yazdırılması
}

void loop() {
  OLED.setBrightness((unsigned char)brightness);  // Ekran parlaklığının ayarlanması
  if (brightness == 255) {
    brightness = 0;
  } else
    brightness += 51;
  delay(500);
}
