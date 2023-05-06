#include <Servo.h>

#define SERVO_PIN 9

Servo servo;
int angle = 0;

int firstIterationFlag = 1;

void setup() {
  
  servo.attach(SERVO_PIN);
  servo.write(angle);

}

void loop() {
  if(firstIterationFlag)
  {
    firstIterationFlag = 0;
    delay(10000);
  }
  else
    delay(4000);

  servo.write(90);
  delay(2000);
  servo.write(0);
}
