/*
 *   MerhabaDunya örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap OLED ekranını 2.satırına Merhaba Dunya!
 *   4.satır 5.sutununa OLED
 *   5.satır 5.sutununa EKRAN yazdırmaktadır.
 *
 *   Bu ekran I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap OLED Ekran modülü için oluşturulmuştur
 *      ------> https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-oled-ekran-m09 <------
 *      ------> https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library  <------
*/
#include <Deneyap_OLED.h>               // Deneyap OLED Ekran kütüphanesinin eklenmesi

OLED OLED;                              // OLED için class tanımlanması

void setup() {
    OLED.begin(0x7A);                   // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
    OLED.clearDisplay();                // OLED ekrandaki verilerin silinmesi
    OLED.setTextXY(0, 0);               // Satır ve sütun ayarlanması
    OLED.putString("****************");
    OLED.setTextXY(2, 0);
    OLED.putString(" Merhaba Dunya! "); // Merhaba Dunya! yazdırılması
    OLED.setTextXY(4, 5);
    OLED.putString("OLED");
    OLED.setTextXY(5, 5);
    OLED.putString("EKRAN");
    OLED.setTextXY(7, 0);
    OLED.putString("****************");
}

void loop() {
}
