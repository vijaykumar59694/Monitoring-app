#include <IRremote.h>

#define Button_1 0x0
#define Button_2 0x10
#define Button_3 0x80BF33CC
#define Button_4 0x80BF718E
#define Button_5 0x80BFF10E
#define Button_6 0x80BF13EC
#define Button_7 0x80BF51AE
#define Button_8 0x80BFD12E

#define Buzzer_pin 12
#define relay_1 4
#define relay_2 5
#define relay_3 6
#define relay_4 7

int RECV_PIN = 8; // IR receiver pin


uint32_t Previous;


int count = 0;


int buttonNumber = 0;



unsigned long DELAY_TIME = 5000;

IRrecv irrecv(RECV_PIN);


decode_results results;


extern volatile unsigned long timer0_millis;

void setup()
{
  Serial.begin(9600);
 
  irrecv.enableIRIn(); // Start the receiver


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
    if (results.value == 0xFFFFFFFF)
    {
      results.value = Previous;
     
      Serial.println(results.value, HEX);
     switch(results.value)
     {
      case Button_1 :
      {
          if (buttonNumber != 1)
          {
            count = 0;
            buttonNumber = 1;
            count ++;
          }
          else
          {            
            if (millis() <= DELAY_TIME) {
              count ++;
              Serial.println("dely is ... ");
              Serial.println(millis());
              Serial.println(count);
            }
            else
            {
              Serial.println("resetting....");
              Serial.println(millis());
              count = 0;
                noInterrupts ();
                timer0_millis = 0;
                interrupts ();
            }
          }
          if (count > 30)
          {
            Serial.println("count more than 30");
           if (digitalRead(relay_1) == LOW)
            {
              Serial.println("making high");
              digitalWrite(relay_1, HIGH); delay(200);  
              noInterrupts ();
                timer0_millis = 0;
                interrupts ();
                count = 0;
              break;
            }
            else
            {
              Serial.println("making low");
              digitalWrite(relay_1, LOW);delay(200);  
              noInterrupts ();
                timer0_millis = 0;
                interrupts ();
                count = 0;
              break;
            }
            count = 0;
          }
          else
          {
            Serial.println("printing 1 count");
            Serial.println(count);
          }
          break;
        if (digitalRead(relay_1) == LOW)
        {
          Serial.println("making high");
          delay(5000);
          digitalWrite(relay_1, HIGH); delay(200);  break;
        }
        else
        {
          Serial.println("making low");
          delay(5000);
          digitalWrite(relay_1, LOW);delay(200);  
          break;
        }
      }
      }
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
