#include <Servo.h>

#define SERVO_PIN 9

Servo servo;
int angle = 0;
const int BUTTON_PIN = 12;
int lastButtonState;
int currentButtonState;

int firstIterationFlag = 1;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  servo.attach(SERVO_PIN);
  servo.write(angle);

  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(BUTTON_PIN);

  if(lastButtonState == HIGH && currentButtonState == LOW)
  {
    if(!angle)
      angle = 60;
    else
      angle = 0;
    
    servo.write(angle);
  }

  // servo.write(60);
  // delay(1000);
  // servo.write(0);
  
  // delay(1000);
}
