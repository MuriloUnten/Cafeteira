#include <Thermistor.h>
#include <Servo.h>

#define MAKE_COFFEE '1'
#define STOP '0'
#define MAX_TEMPERATURE 70
//#define MAX_TEMPERATURE 70
//#define MAX_TEMPERATURE 85
#define BOILER_RELAY_PORT 8
#define VALVE_RELAY_PORT 12
#define DC_RELAY_PORT 7
#define SERVO_PORT 9
#define POUR_TIME_LIMIT 60000 //TODO ajustar para tempo certo


Thermistor thermistor(5);

bool makingCoffee = false;
bool pouringWater = false;
char incomingValue = STOP;

unsigned long startingTime;
unsigned long pourTime;

Servo servo;

void setup()
{
  pinMode(BOILER_RELAY_PORT, OUTPUT);
  pinMode(VALVE_RELAY_PORT, OUTPUT);
  pinMode(DC_RELAY_PORT, OUTPUT);
  
  servo.attach(SERVO_PORT);
  servo.write(0);

  stopBoilingWater();
  closeValve();

  Serial.begin(9600);
  startingTime = millis();
}

void loop()
{
  // Test for bluetooth signal
  if (Serial.available() > 0)
  {
    incomingValue = Serial.read();

    if (incomingValue == MAKE_COFFEE)
    {
      Serial.println("recieved make coffee");
      if(!makingCoffee && !pouringWater)
        {
          releaseCoffeeGrounds();
          startBoilingWater();
        }

      makingCoffee = true;
    }

    else if (incomingValue == STOP)
    {
      Serial.println("recieved stoo");
      stopBoilingWater();
      closeValve();
      makingCoffee = false;
      pouringWater = false;
    }
  }

  if(makingCoffee && !pouringWater)
  {
    int currentTemperature = thermistor.getTemp();
    Serial.println(currentTemperature);
    delay(300);
    if(currentTemperature >= MAX_TEMPERATURE && currentTemperature > 0 && currentTemperature < 150)
    {
      stopBoilingWater();
      pourWater();
    }
  }
}
 

void startBoilingWater()
{
  digitalWrite(BOILER_RELAY_PORT, HIGH);
}


void stopBoilingWater()
{
  digitalWrite(BOILER_RELAY_PORT, LOW);
}


void openValve()
{
  digitalWrite(VALVE_RELAY_PORT, LOW);
}


void closeValve()
{
  digitalWrite(VALVE_RELAY_PORT, HIGH);
}


void releaseCoffeeGrounds()
{
  digitalWrite(DC_RELAY_PORT, HIGH);
  delay(1000);

  servo.write(60);
  delay(1000);
  servo.write(0);
  
  delay(1000);
  digitalWrite(DC_RELAY_PORT, LOW);
}


void pourWater()
{
  openValve();
  /*pourTime = millis() - startingTime;
  if(pourTime >= POUR_TIME_LIMIT)
  {
    pouringWater = false;
    makingCoffee = false;
    closeValve();
  }
  else
  {
    pouringWater = true;
    openValve();
  }*/
}




