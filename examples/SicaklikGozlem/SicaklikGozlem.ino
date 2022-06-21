/*
 *   Deneyap karttaki dahili IMU sensöründen Sıcaklık okuma ve buton durumunu okuyup Deneyap OLED ekrana yazdırma örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Saniyede bir sıcaklık değerlerini alınmaktadır.
 *   Aynı zamanda buton durumu okumaktadır. Alınan bu değerleri
 *   Deneyap OLED ekrana yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap OLED ekran modülü için oluşturulmuştur
 *      ------> www.....com <------ //docs
 *      ------> https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library  <------
 *
 *   Bu uygulama Deneyap Kart 1A veya Deneyap Mini Kartı ile gerçekleştirilmek istenirse harici sıcaklık sensörü bağlanmalıdır ve gerekli değişiklikler yapılmalıdır.
 *
 */

#include <Deneyap_OLED.h>
#include <lsm6dsm.h>

OLED OLED;                                // OLED için Class tanımlaması
LSM6DSM IMU;                              // IMU için Class tanımlaması
float sicaklik;
int butonDurum;

#define BUTON GPKEY                       // DENEYAP KART ve DENEYAP KART 1A geliştirme kartlarındaki dahili butonun tanımlaması
//#define BUTON BUILTIN_KEY               // DENEYAP MİNİ geliştirme kartındaki dahili butonun tanımlaması

void setup()
{
    Serial.begin(115200);                 // Seri haberlesme baslatildi
    OLED.begin(0x7A);                     // OLED ayarlari konfigure edildi
    IMU.begin();                          // IMU ayarlari konfigure edildi
    OLED.clearDisplay();                  // OLED ekranına silindi
    pinMode(BUTON, INPUT);
}

void loop()
{
    sicaklik = IMU.readTempC();           // Sıcaklık değeri alınması
    OLED.setTextXY(3, 0);                 // OLED satır sutun ayarlanması
    OLED.putString("Sicaklik: ");         // OLED ekrana string türünde ekrana yazı yazdırma
    OLED.setTextXY(3, 10);
    OLED.putFloat(sicaklik);              // OLED ekrana float türünde ekrana yazı yazdırma

    int butonDurum = digitalRead(BUTON);  // Buton durumunun alınması
    OLED.setTextXY(5, 0);
    OLED.putString("Buton Durumu:");
    OLED.setTextXY(5, 14);
    OLED.putNumber(butonDurum);           // OLED ekrana int türünde ekrana yazı yazdırma
    delay(1000);
}
