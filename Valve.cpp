#include <Arduino.h>
#include <Valve.h>

Valve::Valve(int pin)
{
  valvePin = pin;
  pinMode(valvePin, OUTPUT);     
  OnTimeA = 1000;
  OnTimeB = 3000;
  valveState = LOW; 
  previousMillis = 0;
  currentMillis = 0;
}

void Valve::shutoff_valve()
{
  currentMillis = 0;
  previousMillis = 0;
   digitalWrite(valvePin,LOW);
}

void Valve::turnon_valve()
{
   digitalWrite(valvePin,HIGH);
}

int Valve::get_valveState()
{
      return valveState;
}

void Valve::set_valveState(int new_heatState)
{
      valveState = new_heatState;
}

unsigned long Valve::get_previousMillis()
{
      return previousMillis;
}

void Valve::set_previousMillis(int new_previousMillis)
{
     previousMillis = new_previousMillis;
}

long Valve::get_OnTimeA()
{
	return OnTimeA;
}

void Valve::set_OnTimeA(int newOnTime)
{
  OnTimeA = newOnTime;
}

long Valve::get_OnTimeB()
{
  return OnTimeB;
}

void Valve::set_OnTimeB(int newOnTime)
{
  OnTimeB = newOnTime;
}


void Valve::turnon_valvePump(int pumpPin)
{
  digitalWrite(valvePin,HIGH);
  digitalWrite(pumpPin,HIGH);

}

void Valve::shutoff_valvePump(int pumpPin)
{
  currentMillis = 0;
  previousMillis = 0;
  digitalWrite(valvePin,LOW);
  digitalWrite(pumpPin,LOW);
}

unsigned long Valve::get_currentMillis()
{
    return currentMillis;

}

void Valve::set_currentMillis(int new_currentMillis)
{
    currentMillis = new_currentMillis;
}

Valve::~Valve()
{
  
}