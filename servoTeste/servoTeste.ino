// #include <Servo.h>

// #define SERVO_PORT 13
// #define BUTTON_PORT 8

// Servo servo;
// int angle = 0;

// void setup()
// {
//   servo.attach(SERVO_PORT);
//   pinMode(BUTTON_PORT, INPUT);

//   servo.write(0);
// }

// void loop()
// {
//   if(digitalRead(BUTTON_PORT) == HIGH)
//   {
//     angle += 5;
//     if(angle >= 255)
//       angle = 255;
//   }
//   else
//   {
//     angle -= 5;
//     if(angle < 0)
//       angle = 0;
//   }

//   servo.write(angle);
//   delay(100);
// }
/*
#include <Servo.h>

// constants won't change
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO_PIN  = 9; // Arduino pin connected to servo motor's pin

Servo servo; // create servo object to control a servo

// variables will change:
int angle = 0;          // the current angle of servo motor
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  servo.attach(SERVO_PIN);           // attaches the servo on pin 9 to the servo object

  servo.write(angle);
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // change angle of servo motor
    if(angle == 0)
      angle = 90;
    else
    if(angle == 90)
      angle = 0;

    // control servo motor arccoding to the angle
    servo.write(angle);
  }
}*/
/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-servo-motor
 */

#include <Servo.h>

// constants won't change
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO_PIN  = 9; // Arduino pin connected to servo motor's pin

Servo servo; // create servo object to control a servo

// variables will change:
int angle = 180;          // the current angle of servo motor
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  servo.attach(SERVO_PIN);           // attaches the servo on pin 9 to the servo object

  servo.write(angle);
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    angle = 130;
    servo.write(angle);
    delay(100);
    angle = 180;
    // // change angle of servo motor
    // if(angle == 180)
    //   angle = 130;
    // else
    // if(angle == 130)
    //   angle = 180;

    // control servo motor arccoding to the angle
    servo.write(angle);
  }
  delay(300);
}

/*


 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-servo-motor
 

#include <Servo.h>

// constants won't change
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO_PIN  = 9; // Arduino pin connected to servo motor's pin

ezButton =) button(BUTTON_PIN); // create ezButton object that attach to pin 7;
Servo servo;                 // create servo object to control a servo

// variables will change:
int angle = 0; // the current angle of servo motor

void setup() {
  Serial.begin(9600);         // initialize serial
  servo.attach(SERVO_PIN);    // attaches the servo on pin 9 to the servo object

  servo.write(angle);
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if(button.isPressed()) {
    Serial.println("The button is pressed");

    // change angle of servo motor
    if(angle == 0)
      angle = 90;
    else
    if(angle == 90)
      angle = 0;

    // control servo motor arccoding to the angle
    servo.write(angle);
  }
}*/