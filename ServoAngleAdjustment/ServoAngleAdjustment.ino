#include <Servo.h>

#define STEP 10

// constants won't change
const int BUTTON0_PIN = 12;
const int BUTTON1_PIN = 13;
const int SERVO_PIN  = 9; // Arduino pin connected to servo motor's pin

Servo servo; // create servo object to control a servo

// variables will change:
int angle = 0;          // the current angle of servo motor

int lastButton0State;
int currentButton0State;

int lastButton1State;
int currentButton1State;

void setup() {
  Serial.begin(9600);                // initialize serial

  pinMode(BUTTON0_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(BUTTON1_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  
  servo.attach(SERVO_PIN);           // attaches the servo on pin 9 to the servo object

  servo.write(angle);

  currentButton0State = digitalRead(BUTTON0_PIN);
  currentButton1State = digitalRead(BUTTON1_PIN);
}

void loop() {
  lastButton0State = currentButton0State;      // save the last state
  currentButton0State = digitalRead(BUTTON0_PIN); // read new state

  lastButton1State = currentButton0State;      // save the last state
  currentButton1State = digitalRead(BUTTON1_PIN);

  if(lastButton0State == HIGH && currentButton0State == LOW) {
    angle -= STEP;
    if(angle < 0) angle = 0;

    Serial.println(angle);    
  }
  if(lastButton1State == HIGH && currentButton1State == LOW) {
    angle += STEP;
    if(angle > 180) angle = 180;

    Serial.println(angle);    
  }

  servo.write(angle);
  delay(300);
}









