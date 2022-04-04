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
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "CbVmQ0X7XdVTH8jp7Cqwmdt1mAfQPiXb";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "rama";
char pass[] = "rama1234";

void setup()
{
// Debug console
Serial.begin(9600);

Blynk.begin(auth, ssid, pass);
}

void loop()
{
Blynk.run();}