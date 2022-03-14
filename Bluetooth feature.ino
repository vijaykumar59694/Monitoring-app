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