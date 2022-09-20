/*
 *   SicaklikGozlem örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Saniyede bir Deneyap Karttaki dahili IMU sensöründen sıcaklık değerlerini alınmaktadır.
 *   Aynı zamanda buton durumu okumaktadır. Alınan bu değerleri
 *   Deneyap OLED ekrana yazdırmaktadır.
 *
 *   Bu ekran I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap OLED Ekran modülü için oluşturulmuştur
 *      ------> https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-oled-ekran-m09 <------
 *      ------> https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library  <------
 *
 *   Bu uygulama için başka bir Deneyap geliştirme kartı kullanılırsa harici sıcaklık sensörü bağlanmalıdır ve koddaki gerekli değişiklikler yapılmalıdır.
*/
#include <Deneyap_OLED.h>                               // Deneyap OLED Ekran kütüphanesinin eklenmesi
#include <lsm6dsm.h>                                    // IMU kütüphanesinin eklenmesi

OLED OLED;                                              // OLED için class tanımlanması
LSM6DSM IMU;                                            // IMU için Class tanımlaması
float sicaklik;
int butonDurum;

#define BUTON GPKEY                                     // DENEYAP geliştirme kartlarındaki dahili butonun tanımlaması

void setup() {
    Serial.begin(115200);                               // Seri haberleşme başlatılması
    if(!OLED.begin(0x7A)){                              // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
       delay(3000);
        Serial.println("I2C bağlantısı başarısız ");    // I2C bağlantısı başarısız olursa seri terminale yazdırılması
    }
    IMU.begin();                                        // IMU begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
    OLED.clearDisplay();                                // OLED ekrandaki verilerin silinmesi
    pinMode(BUTON, INPUT);
}

void loop() {
    sicaklik = IMU.readTempC();                         // Sıcaklık değeri alınması
    OLED.setTextXY(3, 0);                               // OLED satır sütun ayarlanması
    OLED.putString("Sicaklik: ");                       // OLED ekrana string türünde ekrana yazı yazdırılması
    OLED.setTextXY(3, 10);
    OLED.putFloat(sicaklik);                            // OLED ekrana float türünde ekrana yazı yazdırılması

    int butonDurum = digitalRead(BUTON);                // Buton durumunun alınması
    OLED.setTextXY(5, 0);
    OLED.putString("Buton Durumu:");
    OLED.setTextXY(5, 14);
    OLED.putInt(butonDurum);                            // OLED ekrana int türünde ekrana yazı yazdırılması
    delay(1000);
}
