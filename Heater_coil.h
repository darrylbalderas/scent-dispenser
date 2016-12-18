#ifndef Heater_coil_H
#define Heater_coil_H

#include "Arduino.h"

class Heater_coil
{
  private:
    int heatPin;                    // the number of the LED pin
    long OnTime;                    // milliseconds of on-time
    int heatState;                  // coil State 
    unsigned long previousMillis;   // will store last time LED was updated
    unsigned long currentMillis;

  public:
    // Constructor - creates a heater 
    // and initializes the member variables and state
    Heater_coil(int pin);
    void shutoff_coil();
    void turnon_coil();
    int get_heatState();
    void set_heatState(int new_heatState);
    unsigned long get_previousMillis();
    void set_previousMillis(int new_currentMillis);

    unsigned long get_currentMillis();
    void set_currentMillis(int new_currentMillis);

    long get_OnTime();

};
#endif