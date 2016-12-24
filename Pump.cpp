 
#include <Arduino.h>
#include <Pump.h>


Pump::Pump(int pin)
{
    pumpPin = pin;
    pinMode(pumpPin, OUTPUT);
    pumpState = LOW;      
    OnTime = 5000;
    previousMillis = 0;
    currentMillis = 0;
}

void Pump::shutoff_pump()
{
    currentMillis = 0;
    previousMillis = 0;
    digitalWrite(pumpPin, LOW);
}

void Pump::turnon_pump()
{
    digitalWrite(pumpPin, HIGH);
}

int Pump::get_pumpState()
{
    return pumpState;
}
void Pump::set_pumpState(int new_pumpState)
{
    pumpState = new_pumpState;
}

unsigned long Pump::get_previousMillis()
{

    return previousMillis;
}

void Pump::set_previousMillis(int new_previousMillis)
{
    previousMillis = new_previousMillis;
}

long Pump::get_OnTime()
{
    return OnTime;
}

unsigned long Pump::get_currentMillis()
{
    return currentMillis;

}

void Pump::set_currentMillis(int new_currentMillis)
{
    currentMillis = new_currentMillis;
}

Pump::~Pump()
{
    
}

