/*
 *   Deneyap OLED ekrana Taş Kağıt Makas örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap OLED ekranda sırasıyla taş, kağıt, makas yazıları ve işaretleri yazmaktadır. Daha sonra ekranda "oyun basliyor" yazmaktadır.
 *   Birden üçe kadar random sayı ataması yapılmaktadır. Random sayı 1 ise taş, 2 ise kağıt, 3 ise makas ekrana yazdırmaktadır.
 *   Oyun 1500 milisaniyede bir ekranda "tekrar" yazdırarak döngü içinde devam etmektedir.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap OLED ekran modülü için oluşturulmuştur
 *      ------> www.....com <------ //docs
 *      ------> https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library  <------
 *
 */

#include <Deneyap_OLED.h>

OLED OLED;                           // OLED için Class tanımlaması

void TAS();                          // TAS fonksiyonun prototip tanımlanması
void KAGIT();                        // KAGIT fonksiyonun prototip tanımlanması
void MAKAS();                        // MAKAS fonksiyonun prototip tanımlanması

void setup() {
    Serial.begin(115200);            // Seri haberlesme baslatildi
    OLED.begin(0x7A);                // OLED ayarlari konfigure edildi
    OLED.clearDisplay();             // OLED ekranı silindi

    TAS();                           // TAS fonksiyonu calistirilmasi
    delay(1000);                     // 1 saniye bekleme
    KAGIT();                         // KAGIT fonksiyonu calistirilmasi
    delay(1000);
    MAKAS();                         // MAKAS fonksiyonu calistirilmasi
    delay(1000);

    OLED.clearDisplay();
    OLED.setTextXY(3, 1);            // OLED satır sutun ayarlanması
    OLED.putString("Oyun basliyor"); // OLED ekrana string türünde ekrana yazı yazdırma
    delay(500);
}

void loop() {

    int randNumber = random(1, 4);  // 1'den 3 kadar random sayısı atamasi yapiliyor
    Serial.println(randNumber);     // Random sayi ekrana yazdirildi

    switch (randNumber) {
    case 1:                         // Random sayi 1 ise
        TAS();                      // TAS fonksiyonunu calistir
        break;
    case 2:                         // Random sayi 2 ise
        KAGIT();                    // KAGIT fonksiyonunu calistir
        break;
    case 3:                         // Random sayi 3 ise
        MAKAS();                    // MAKAS fonksiyonunu calistir
        break;
    }
    delay(1500);
    OLED.clearDisplay();
    OLED.setTextXY(3, 4);
    OLED.putString("tekrar");
    delay(2500);
}

/*
 * Ekrana TAS ve taş işareti yazdırır
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
 * Ekrana KAGIT ve kağıt işareti yazdırır
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
 * Ekrana MAKAS ve makas işareti yazdırır
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
