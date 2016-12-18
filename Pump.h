#ifndef Pump_H
#define Heater_Coil_H
#include "Arduino.h"

class Pump
{
  private:
    int pumpPin;                    // the number of the LED pin
    long OnTime;                    // milliseconds of on-time
    int pumpState;                  // coil State 
    unsigned long previousMillis;   // will store last time LED was updated
    unsigned long currentMillis;

  public:
    // Constructor - creates a heater 
    // and initializes the member variables and state
    Pump(int pin);
    void shutoff_pump();
    void turnon_pump();
    int get_pumpState();
    void set_pumpState(int new_pumpState);
    unsigned long get_previousMillis();
    void set_previousMillis(int new_previousMillis);
    unsigned long get_currentMillis();
    void set_currentMillis(int new_currentMillis);
    long get_OnTime();

};
#endif