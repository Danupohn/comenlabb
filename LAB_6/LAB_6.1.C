#define LOOP_PLAY 300
const char pin_seg[] = { 2,3, 4, 5, 6, 7, 8, 9, 10, 11, 12,};// digit 1, 2, 3, a, b, c, d, e, f, g, dp
const char led_num[] = {0x5C,0x54,0x00,0x7C,0X79,0x6E,0x1C};
int iNum = 0;
int iPin = 0;
void setup() {
  iPin = sizeof(pin_seg);
  for (int i = 0; i < iPin; i++) {
    pinMode(pin_seg[i], OUTPUT);
  }
}
void loop() {
  for (int i = 0; i < LOOP_PLAY; i++) {
    DisplayNum(pin_seg[2], 1);
    DisplayNum(pin_seg[1], 0);
    DisplayNum(pin_seg[0], 2);
  }
  for (int i = 0; i < LOOP_PLAY; i++) {
    DisplayNum(pin_seg[0], 3);
    DisplayNum(pin_seg[2], 4);
    DisplayNum(pin_seg[1], 5);
  }
   for (int i = 0; i < LOOP_PLAY; i++) {
    DisplayNum(pin_seg[0], 5);
    DisplayNum(pin_seg[2], 6);
    DisplayNum(pin_seg[1], 0);
  }
  if(iNum++ > 999) iNum = 0;
}
void DisplayNum(int digit, int num) {
  char digital = led_num[num];
  if (digit != pin_seg[2]) digitalWrite(pin_seg[2], HIGH);
  if (digit != pin_seg[1]) digitalWrite(pin_seg[1], HIGH);
  if (digit != pin_seg[0]) digitalWrite(pin_seg[0], HIGH);
  digitalWrite(digit, LOW);
  for (int i = 3; i < iPin; i++) {
    if (digital & 0x01)
      digitalWrite(pin_seg[i], HIGH);
    else
      digitalWrite(pin_seg[i], LOW);
    digital = digital >> 1;
  }
   delay(1);
}