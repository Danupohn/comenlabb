#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#define LCD_addr 0x27
LiquidCrystal_I2C lcd(LCD_addr, 16, 2);
unsigned int i = 0;
int time = 0;
void setup() {
  lcd.begin();
  Serial.begin(9600);
  i = EEPROM.read(5);
  time = EEPROM.read(6);
  ++time;
 
}
void loop() {
  lcd.clear();
  lcd.setCursor(7, 0);
  if (i < 10)
    lcd.print('0');
  EEPROM.write(5,i);
  lcd.print(i);
  Serial.println(i);
  lcd.setCursor(7, 1);
  EEPROM.write(6,time);
  lcd.print(time);
  i++;
  delay(800);
}