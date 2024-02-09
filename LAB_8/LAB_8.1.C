#include <Wire.h>
#define PCF8574A_addr 0x3F
unsigned int data_out = 0x88;
void setup() {
  Wire.begin();
  Serial.begin(9600);
}
void loop() {
  Wire.beginTransmission(PCF8574A_addr);
  Wire.write(data_out);
  Wire.endTransmission();
  delay(500);
  Serial.print(data_out,DEC);
  Serial.print("  ");
 
  Serial.print(data_out,BIN);
    Serial.print("  ");
 
  Serial.println(data_out,HEX);
  data_out = ~data_out;
}