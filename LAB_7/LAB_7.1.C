void setup() {
  Serial.begin(9600);
  for (int pin = 2; pin <= 12; pin++) {
    pinMode(pin, OUTPUT);
  }
}
void loop() {
  int aVal = analogRead(A0);
  Serial.println(aVal, DEC);
  Serial.println(aVal / 102, DEC);
  delay(100);
  aVal = aVal / 102;
  switch (aVal) {
    case 1: aVal = 2; break;
    case 2: aVal = 3; break;
    case 3: aVal = 4; break;
    case 4: aVal = 5; break;
    case 5: aVal = 6; break;
    case 6: aVal = 7; break;
    case 7: aVal = 8; break;
    case 8: aVal = 9; break;
    case 9: aVal = 10; break;
    case 10: aVal = 11; break;
    default: aVal = 0;
  }
  for (int pin = 2; pin <= 12; pin++) {
    if (pin == aVal)
      digitalWrite(pin, HIGH);
    else
      digitalWrite(pin, LOW);
  }
}