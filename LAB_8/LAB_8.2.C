#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
uint8_t a[8] = { B10000, B10000, B10000, B10000, B10000, B11100, B10100, B11100 };  //เ
uint8_t b[8] = { B00000, B01111, B10000, B01110, B10010, B10010, B10010, B11110 };  //ธ
uint8_t c[8] = { B00000, B01110, B10001, B00001, B01101, B10001, B10001, B01110 };  //อ
uint8_t d[8] = { B00000, B00000, B11001, B11001, B01001, B01001, B11101, B11011 };  //ม
uint8_t e[8] = { B00000, B01100, B10010, B00010, B00010, B00010, B00010, B00010 };  //า
uint8_t f[8] = { B00000, B01110, B10001, B00001, B01101, B10001, B10001, B01110 };  //อ
uint8_t g[8] = { B00001, B01101, B10000, B01001, B10001, B10001, B01110, B00110 };  //ยู่
uint8_t h[8] = { B00010, B01110, B00000, B11010, B11010, B01010, B01111, B01011 };  //นี่
void setup() {
  while(true){
  lcd.begin();
  lcd.createChar(0, a);
  lcd.setCursor(4, 0);
  lcd.print((char)0);
  lcd.setCursor(5, 0);
  lcd.print((char)1);
  lcd.createChar(2, c);
  lcd.setCursor(6, 0);
  lcd.print((char)2);
  lcd.createChar(3, d);
  lcd.setCursor(7, 0);
  lcd.print((char)3);
  lcd.createChar(4, e);
  lcd.setCursor(8, 0);
  lcd.print((char)4);
  lcd.createChar(5, f);
  lcd.setCursor(9, 0);
  lcd.print((char)5);
  lcd.createChar(6, g);
  lcd.setCursor(10, 0);
  lcd.print((char)6);
  lcd.createChar(7, h);
  lcd.setCursor(11, 0);
  lcd.print((char)7);
  lcd.setCursor(0, 1);
  lcd.print("Hello ");
  lcd.createChar(0, a);
  lcd.setCursor(6, 1);
  lcd.print((char)0);
  delay(500);
  lcd.createChar(1, b);
  lcd.setCursor(7, 1);
  lcd.print((char)1);
  delay(500);
 
  lcd.createChar(2, c);
  lcd.setCursor(8, 1);
  lcd.print((char)2);
  delay(500);
 
  lcd.createChar(3, d);
  lcd.setCursor(9, 1);
  lcd.print((char)3);
  delay(500);
 
  lcd.createChar(4, e);
  lcd.setCursor(10, 1);
  lcd.print((char)4);
  delay(500);
 
  lcd.createChar(5, f);
  lcd.setCursor(11, 1);
  lcd.print((char)5);
  delay(500);
 
  lcd.createChar(6, g);
  lcd.setCursor(12, 1);
  lcd.print((char)6);
  delay(500);
 
  lcd.createChar(7, h);
  lcd.setCursor(13, 1);
  lcd.print((char)7);
  delay(500);
  lcd.clear();
  }
}
void loop() {}