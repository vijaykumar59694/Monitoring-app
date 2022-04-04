#include <IRremote.h>
//#include "Timer.h"

#define Button_1 0x10

#define Button_2 0x810

#define Button_3 0x410

#define Button_4 0xC10

#define Button_5 0x210

#define Button_6 0xA10
#define Button_7 0x610

#define Button_8 0xE10

#define Buzzer_pin 12
#define relay_1 4
#define relay_2 5
#define relay_3 6
#define relay_4 7

int RECV_PIN = 8; // IR receiver pin

uint32_t Previous;

48

int count = 0;

49

int buttonNumber = 0;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()

{
Serial.begin(9600); irrecv.enableIRIn();
// Start the receiver

pinMode(relay_1, OUTPUT);
pinMode(relay_2, OUTPUT);
pinMode(relay_3, OUTPUT);
pinMode(relay_4, OUTPUT);
pinMode(Buzzer_pin, OUTPUT);
// Initially all relay pin will HIGH because relay active LOW
digitalWrite(relay_1, HIGH);
digitalWrite(relay_2, HIGH);
digitalWrite(relay_3, HIGH);
digitalWrite(relay_4, HIGH);
}

void loop() {
if (irrecv.decode(&results)) {
// if (results.value == 0xFFFFFFFF)
// {
// results.value = Previous;
// }
switch(results.value)
{
case Button_1 :

50

{

51

Serial.println("button 1");
if (buttonNumber != 1)
{
count = 0;
buttonNumber = 1;
count ++;
}
else
{
Serial.println("increment count");
count ++;
}
if (count > 20)
{
digitalWrite(relay_1, LOW); digitalWrite(Buzzer_pin, HIGH); delay(200);
digitalWrite(Buzzer_pin,LOW);
count = 0;
}
else
{
Serial.println("printing 1 count");
Serial.println(count);
}
break;
}
case Button_2 :
{
if (buttonNumber != 2)
{
count = 0;
buttonNumber = 2;
count ++;
}

52

else

53

{
count ++;
}
if (count > 20)
{
digitalWrite(relay_1, HIGH); digitalWrite(Buzzer_pin, HIGH); delay(200);
digitalWrite(Buzzer_pin,LOW);
count = 0;
}
else
{
Serial.println(count);
}
break;
}
}
}
}
char val;
void setup() {
// put your setup code here, to run once:
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
Serial.begin(9600);
}

void loop() {
if (Serial.available()) {
val = Serial.read();
Serial.println();
}
if (val == '1')
{
digitalWrite(13, LOW);
}
else if (val == '2')
{
digitalWrite(13, HIGH);
}
else if (val == '3')
{

44

digitalWrite(12, LOW);

}
else if (val == '4')
{
digitalWrite(12, HIGH);
}
else if (val == '5')
{
digitalWrite(11, LOW);
}
else if (val == '6')
{
digitalWrite(11, HIGH);
}

delay(100);

}