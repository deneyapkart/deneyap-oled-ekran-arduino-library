/*
 *   Deneyap OLED ekrana Merhaba Dunya yazdırma örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap OLED ekranını 2.satırına Merhaba Dunya!
 *   4.satır 5.sutununa OLED
 *   5.satır 5.sutununa EKRAN yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap OLED ekran modülü için oluşturulmuştur
 *      ------> www.....com <------ //docs
 *      ------> https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library  <------
 *
 */

#include <Deneyap_OLED.h>               // Deneyap_SicaklikNemOlcer.h kütüphanesi eklendi

OLED OLED;                              // OLED için class tanımlaması

void setup() {
    Serial.begin(115200);               // Seri haberlesme baslatildi
    OLED.begin(0x7A);                   // OLED ayarlari konfigure edildi
    OLED.clearDisplay();                // OLED ekranı silindi

    OLED.setTextXY(0, 0);               // Satır ve sutun ayarlandı
    OLED.putString("****************");
    OLED.setTextXY(2, 0);
    OLED.putString(" Merhaba Dunya! "); // Merhaba Dunya! yazdırıldı
    OLED.setTextXY(4, 5);
    OLED.putString("OLED");
    OLED.setTextXY(5, 5);
    OLED.putString("EKRAN");
    OLED.setTextXY(7, 0);
    OLED.putString("****************");
}

void loop() {
}
