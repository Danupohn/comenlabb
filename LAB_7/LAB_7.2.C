int pwm_wave = 6;
int switch1Pin = 11;  // พินของสวิต์ที่ 1
int switch2Pin = 10;  // พินของสวิต์ที่ 2
int brightnessLevel;  // ระดับความสว่างของไฟ
void setup() {
  Serial.begin(9600);
  pinMode(pwm_wave, OUTPUT);
  pinMode(switch1Pin, INPUT_PULLUP);
  pinMode(switch2Pin, INPUT_PULLUP);
}
void loop() {
  int switch1State = digitalRead(switch1Pin);
  int switch2State = digitalRead(switch2Pin);
  int aVal = analogRead(A0);
  if (switch1State == LOW && brightnessLevel < 255) {
    brightnessLevel = (brightnessLevel + 1) % 256;
    analogWrite(pwm_wave, brightnessLevel);
  } else if (switch2State == LOW && brightnessLevel > 0) {
    brightnessLevel = (brightnessLevel - 1) % 256;
    analogWrite(pwm_wave, brightnessLevel);
  }
  if (switch1State == HIGH && switch2State == HIGH) {
    analogWrite(pwm_wave, brightnessLevel);
  }
  Serial.println(brightnessLevel);
  delay(10);
}