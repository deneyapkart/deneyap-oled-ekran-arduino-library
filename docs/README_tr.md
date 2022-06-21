# Deneyap OLED Ekran Modülü SSD1306 Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap OLED Ekran Modülü SSD1306 için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M09**, **mpv1.0**
- `MCU` SSD1306
- `Ağırlık`
- `Modul Boyutları` 
- `I2C Adres` 0x7A, 0x78

| Adres |  | 
| :---  | :---     |
| 0x7A | varsayılan adres |
| 0x78 | ADR1 kısa devre yapıldığındaki adres|

## :closed_book:Dokümanlar
Deneyap OLED Ekran Modülü SSD1306

[SSD1306-datasheet](https://www.digimax.it/media_import/DISPLAY/RAYSTAR%20OPTRONICS/DISPLAY%20OLED/REX012864DWPP3N00003/REX012864DWPP3N00003_DS_001.pdf)

Arduino Kütüphanesi Nasıl İndirilir

## :pushpin:Deneyap OLED Ekran Modülü SSD1306
Bu Arduino kütüphanesi Deneyap OLED SSD1306 0.96" 128x64 piksel siyah mavi ekran modulünün I2C çevre birimi ile kullanılmasını sağlar. String, int, float tipi verileri yazdırabilirsiniz. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap OLED Ekran modülü ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir.

| OLED Ekran | Fonksiyon| Kart pinleri |
| :---        |   :---   | :---      |
| 3.3V        | Güç      | 3.3V      |
| GND         | Toprak   | GND       |
| SDA         | I2C Data  | SDA pini |
| SCL         | I2C Clock | SCL pini |
| NC          | bağlantı yok |   |

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-oled-ekran-arduino-library/blob/master/LICENSE) dosyasını inceleyin.
