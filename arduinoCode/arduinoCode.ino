#include <Servo.h>


#define TIMEOUT 150
#define ANGLE 30
#define SETUPPIN 0 //pin for set servo in 90deg

Servo servo;

void setup() {
  servo.attach(2);// put your setup code here, to run once:
  pinMode(SETUPPIN, INPUT);   //switch pin 
}

void loop() {

  if( digitalRead(SETUPPIN)==LOW)
  {
    servo.write(90);
  }
  else
  {
    delay(TIMEOUT);
    servo.write(90-ANGLE);
    delay(TIMEOUT);  
    servo.write(90+ANGLE);
    
  }
  

}
