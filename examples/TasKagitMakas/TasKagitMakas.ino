/*
 *   TasKagitMakas örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap OLED ekranda sırasıyla taş, kağıt, makas yazıları ve işaretleri yazmaktadır. Daha sonra ekranda "oyun basliyor" yazmaktadır.
 *   Birden üçe kadar random sayı ataması yapılmaktadır. Random sayı 1 ise taş, 2 ise kağıt, 3 ise makas ekrana yazdırmaktadır.
 *   Oyun 1500 milisaniyede bir ekranda "tekrar" yazdırarak döngü içinde devam etmektedir.
 *
 *   Bu ekran I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap OLED Ekran modülü için oluşturulmuştur
 *      ------> https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-oled-ekran-m09 <------
 *      ------> https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library  <------
*/
#include <Deneyap_OLED.h>                   // Deneyap OLED Ekran kütüphanesinin eklenmesi

OLED OLED;                                  // OLED için class tanımlanması

void TAS();                                 // TAS fonksiyonun prototip tanımlanması
void KAGIT();                               // KAGIT fonksiyonun prototip tanımlanması
void MAKAS();                               // MAKAS fonksiyonun prototip tanımlanması

void setup() {
    Serial.begin(115200);                   // Seri haberleşme başlatılması
    OLED.begin(0x7A);                       // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
    OLED.clearDisplay();                    // OLED ekrandaki verilerin silinmesi

    TAS();                                  // TAS fonksiyonu çalıştırılması
    delay(1000);                            // 1 saniye bekleme
    KAGIT();                                // KAGIT fonksiyonu çalıştırılması
    delay(1000);
    MAKAS();                                // MAKAS fonksiyonu çalıştırılması
    delay(1000);

    OLED.clearDisplay();
    OLED.setTextXY(3, 1);                   // OLED satır sütun ayarlanması
    OLED.putString("Oyun basliyor");        // OLED ekrana string türünde ekrana yazı yazdırılması
    delay(500);
}

void loop() {
    int randNumber = random(1, 4);          // 1'den 3 kadar random sayısı ataması yapılıyor
    Serial.println(randNumber);             // Random sayı ekrana yazdırıldı

    switch (randNumber) {
    case 1:                                 // Random sayı 1 ise
        TAS();                              // TAS fonksiyonunu çalıştır
        break; 
    case 2:                                 // Random sayı 2 ise
        KAGIT();                            // KAGIT fonksiyonunu çalıştır
        break;
    case 3:                                 // Random sayı 3 ise
        MAKAS();                            // MAKAS fonksiyonunu çalıştır
        break;
    }
    delay(1500);
    OLED.clearDisplay();
    OLED.setTextXY(3, 4);
    OLED.putString("tekrar");
    delay(2500);
}

/*
 * OLED ekranına TAS ve taş işareti yazdırır
 */
void TAS() {
    OLED.setTextXY(0, 0);
    OLED.putString("             TAS");
    OLED.setTextXY(1, 0);
    OLED.putString("  _____         ");
    OLED.setTextXY(2, 0);
    OLED.putString(" /#####)        ");
    OLED.setTextXY(3, 0);
    OLED.putString("|######)        ");
    OLED.setTextXY(4, 0);
    OLED.putString("|######)        ");
    OLED.setTextXY(5, 0);
    OLED.putString(" \\#####)       ");
    OLED.setTextXY(6, 0);
    OLED.putString("  \\----        ");
    OLED.setTextXY(7, 0);
    OLED.putString("                ");
}

/*
 * OLED ekranına KAGIT ve kağıt işareti yazdırır
 */
void KAGIT() {
    OLED.setTextXY(0, 0);
    OLED.putString("           KAGIT");
    OLED.setTextXY(1, 0);
    OLED.putString("   ____         ");
    OLED.setTextXY(2, 0);
    OLED.putString(" /######)       ");
    OLED.setTextXY(3, 0);
    OLED.putString("|########)      ");
    OLED.setTextXY(4, 0);
    OLED.putString("|#########)     ");
    OLED.setTextXY(5, 0);
    OLED.putString("|########)      ");
    OLED.setTextXY(6, 0);
    OLED.putString(" \\####)        ");
    OLED.setTextXY(7, 0);
    OLED.putString("  ----");
}

/*
 * OLED ekranına MAKAS ve makas işareti yazdırır
 */
void MAKAS() {
    OLED.setTextXY(0, 0);
    OLED.putString("           MAKAS");
    OLED.setTextXY(1, 0);
    OLED.putString("    -----       ");
    OLED.setTextXY(2, 0);
    OLED.putString(" __/#####)      ");
    OLED.setTextXY(3, 0);
    OLED.putString("|###/           ");
    OLED.setTextXY(4, 0);
    OLED.putString("|###K           ");
    OLED.setTextXY(5, 0);
    OLED.putString("|########)      ");
    OLED.setTextXY(6, 0);
    OLED.putString(" \\####)        ");
    OLED.setTextXY(7, 0);
    OLED.putString("  \\---         ");
}
