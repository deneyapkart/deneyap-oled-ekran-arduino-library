# Deneyap OLED Ekran Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap OLED Ekran için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M09**, **mpv1.0**
- `MCU` SSD1306 ekranı
- `Ağırlık`
- `Modul Boyutları` 25,4 mm x 38,1 mm
- `I2C Adres` 0x7A, 0x78

| Adres |  | 
| :---  | :---     |
| 0x7A | varsayılan adres |
| 0x78 | ADR1 kısa devre yapıldığındaki adres|

## :closed_book:Dokümanlar
[Deneyap OLED Ekran](https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-oled-ekran-m09)

[Deneyap OLED Ekran Teknik Çizim](https://cdn.deneyapkart.org/media/upload/userFormUpload/wT6dViZ5y4WdwdZkzbxM9t2vsJTwDkks.pdf)

[SSD1306-datasheet](https://www.wisechip.com.tw/en/product-609620/0-96%E2%80%9D-OLED-Display.html)

[Arduino IDE'de Kütüphane Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap OLED Ekran
Bu Arduino kütüphanesi Deneyap OLED SSD1306 0.96" 128x64 piksel siyah mavi ekran modulünün I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.3 - fonksiyonlar güncellendi(`begin`), yeni fonksiyonlar(`init`, `setHorizontalScrollProperties`) ve örnekler(`EkranParlakligiDegistirme`, `KayanYazi`, `T3Logo`) eklendi

1.0.2 - `putNumber` fonksiyon ismi `putInt` olarak değiştirildi ve metin bilgileri güncellendi

1.0.1 - library.properties dosyasının güncellenmesi

1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap OLED Ekran modülü ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir.

| OLED Ekran | Fonksiyon| Kart pinleri |
| :---        |   :---   | :---      |
| 3.3V        |3.3V Besleme Gerilimi| 3.3V      |
| GND         |Toprak| GND       |
| SDA         |Çift Yönlü Veri Hattı| SDA pini |
| SCL         |Veri Hatta Zaman Senkronivasyon İşareti| SCL pini |
| NC          | bağlantı yok |   |

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library/blob/master/LICENSE) dosyasını inceleyin.