 
#include <Arduino.h>
#include <Heater_coil.h>


Heater_coil::Heater_coil(int pin)
{
    heatPin = pin;
    pinMode(heatPin, OUTPUT);
    heatState = LOW;      
    OnTime = 40000;
    previousMillis = 0;
    currentMillis = 0;
}

void Heater_coil::shutoff_coil()
{
    previousMillis = 0;
    currentMillis = 0;
    digitalWrite(heatPin, LOW);
}

void Heater_coil::turnon_coil()
{
    digitalWrite(heatPin, HIGH);
}

int Heater_coil::get_heatState()
{
    return heatState;
}
void Heater_coil::set_heatState(int new_heatState)
{
    heatState = new_heatState;
}

unsigned long Heater_coil::get_previousMillis()
{

    return previousMillis;
}

void Heater_coil::set_previousMillis(int new_previousMillis)
{
    previousMillis = new_previousMillis;
}

long Heater_coil::get_OnTime()
{
    return OnTime;
}

unsigned long Heater_coil::get_currentMillis()
{
    return currentMillis;

}

void Heater_coil::set_currentMillis(int new_currentMillis)
{
    currentMillis = new_currentMillis;
}



