#define LOOP_PLAY 150
const char pin_seg[] = {2,3,4,5,6,7,8,9,10,11,12,}; // digit 1, 2, 3, a, b, c, d, e, f, g, dp
const char led_num[] = {   0x3F,   0x06,   0x5B,   0x4F, 0x66,0x6D,0x7D, 0x07, 0x7F,  0x6F,  0x77,  0x7C,  0x39, 0x5E,  0x79,  0x71,   0x80,};
int iNum = 0;
int iPin = 0;
void setup()
{
    iPin = sizeof(pin_seg);
    for (int i = 0; i < iPin; i++)
    {
        pinMode(pin_seg[i], OUTPUT);
    }
}
void loop()
{
    for (int i = 0; i < LOOP_PLAY; i++)
    {
        DisplayNUM(pin_seg[0], ((iNum % 100) % 10));
        DisplayNUM(pin_seg[0], ((iNum % 100) / 10));
        DisplayNUM(pin_seg[0], (iNum / 100));
    }
    if(iNum++ > 999) iNum = 0;
}
void DisplayNum(int digit, int num)
{
    char digital = led_num[num];
    if (digit != pin_seg[0])
        digitalWrite(pin_seg[0], HIGH);
    if (digit != pin_seg[1])
        digitalWrite(pin_seg[1], HIGH);
    if (digit != pin_seg[2])
        digitalWrite(pin_seg[2], HIGH);
    digitalWrite(digit, LOW);
    for (int i = 3; i < iPin; i++)
    {
        if (digital & 0x01)
            digitalWrite(pin_seg[i], HIGH);
        else
            digitalWrite(pin_seg[i], LOW);

        digital = digital >> 1;
    }
