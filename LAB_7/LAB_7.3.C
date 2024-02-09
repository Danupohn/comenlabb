int ledPin = 6;
int analogPin = 0;
int val = 0;
int brightness = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  val = analogRead(A0);
  Serial.print("val = ");
  Serial.println(val);
  if (val < 255) {
    analogWrite(ledPin, brightness++);
    if (brightness > 255) {
      brightness = 255;
    }
    Serial.println(brightness);
  } else {
    analogWrite(ledPin, brightness--);
    if (brightness <= 1) {
      brightness = 1;
    }
    Serial.println(brightness);
  }
}