#ifndef _Valve_H_
#define _Valve_H_
#include "Arduino.h"

class Valve
{
  private:
    int valvePin;                    // the number of the LED pin
    long OnTimeA;
    long OnTimeB;                    // milliseconds of on-time
    int valveState;                  // coil State 
    unsigned long previousMillis;   // will store last time LED was updated
    unsigned long currentMillis;

  public:
    // Constructor - creates a heater 
    // and initializes the member variables and state
    Valve(int pin);
    //Valve A
    void turnon_valve();
    void shutoff_valve();
    int get_valveState();
    void set_valveState(int new_heatState);
    unsigned long get_previousMillis();
    void set_previousMillis(int new_previousMillis);
    //ValveA
    long get_OnTimeA();
    void set_OnTimeA(int newOnTime);

    //ValveB
    long get_OnTimeB();
    void set_OnTimeB(int newOnTime);

    //Valve B
    void turnon_valvePump(int pumpPin);
    void shutoff_valvePump(int pumpPin);

    unsigned long get_currentMillis();
    void set_currentMillis(int new_currentMillis);
};
#endif