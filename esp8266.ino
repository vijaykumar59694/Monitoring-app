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
Blynk.run();
}