#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <IPAddress.h>
#define LCD_addr 0x27
LiquidCrystal_I2C lcd(LCD_addr, 16, 2);
void setup() {
lcd.begin();
Serial.begin(9600);
// อ่านค่า IP address จาก EEPROM
IPAddress ip = readIPAddressFromEEPROM();
printIPAddress(ip);
}
void loop() {
if (Serial.available() > 0) {
   // รับข้อมูล IP address จาก Serial Monitor
   String ipString = Serial.readStringUntil('\n');
   IPAddress ip = parseIPAddress(ipString);
   // แสดงค่า IP address ที่รับเข้ามาทาง Serial Monitor
   printIPAddress(ip);
   // บันทึกค่า IP address ลงใน EEPROM
   saveIPAddressToEEPROM(ip);
}
}
IPAddress parseIPAddress(String ipString) {
// แยกส่วนของ IP address โดยใช้ strtok()
char* part = strtok(const_cast<char*>(ipString.c_str()), ".");
byte parts[4];
for (int i = 0; i < 4; i++) {
   parts[i] = atoi(part);
   part = strtok(NULL, ".");
}
return IPAddress(parts[0], parts[1], parts[2], parts[3]);
}
void printIPAddress(IPAddress ip) {
// แสดงค่า IP address ทาง Serial Monitor
Serial.print("IP: ");
for (int i = 0; i < 4; i++) {
   Serial.print(ip[i]);
   if (i < 3) {
     Serial.print(".");
   }
}
Serial.println();
// แสดงค่า IP address บน LCD แบบ I2C
lcd.clear();
lcd.setCursor(2, 0);
lcd.print("IP Address: ");
lcd.setCursor(2, 1);
lcd.print(ip[0]);
lcd.print(".");
lcd.print(ip[1]);
lcd.print(".");
lcd.print(ip[2]);
lcd.print(".");
lcd.print(ip[3]);
}
void saveIPAddressToEEPROM(IPAddress ip) {
// บันทึกค่า IP address ลงใน EEPROM
for (int i = 0; i < 4; i++) {
   EEPROM.write(i, ip[i]);
}
}
IPAddress readIPAddressFromEEPROM() {
// อ่านค่า IP address จาก EEPROM
byte parts[4];
for (int i = 0; i < 4; i++) {
   parts[i] = EEPROM.read(i);
}
return IPAddress(parts[0], parts[1], parts[2], parts[3]);
}