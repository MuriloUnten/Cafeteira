#include <Thermistor.h>

#define MAKE_COFFEE '1'
#define STOP '0'
#define MAX_TEMPERATURE 85
#define BOILER_RELAY_PORT 8
#define VALVE_RELAY_PORT 12
#define POUR_TIME_LIMIT 60000 //TODO ajustar para tempo certo


Thermistor thermistor(0);

bool makingCoffee = false;
bool pouringWater = false;
char incomingValue = STOP;

unsigned long startingTime;
unsigned long pourTime; 

void setup()
{
  pinMode(BOILER_RELAY_PORT, OUTPUT);
  pinMode(VALVE_RELAY_PORT, OUTPUT);
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
      if(!makingCoffee && !pouringWater)
        {
          startBoilingWater();
          releaseCoffeeGrounds();
        }

      makingCoffee = true;
    }

    else if (incomingValue == STOP)
    {
      stopBoilingWater();
      closeValve();
      makingCoffee = false;
      pouringWater = false;
    }
  }

  if(makingCoffee && !pouringWater)
  {
    int currentTemperature = thermistor.getTemp();
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
  //TODO Implement using servomotor.
}


void pourWater()
{
  pourTime = millis() - startingTime;
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
  }
}







