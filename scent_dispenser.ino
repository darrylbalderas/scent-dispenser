#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <Keypad.h>
#include <Heater_coil.h>
#include <Pump.h>
#include <Valve.h>

#define PUMP1  40
#define PUMP2  41
#define PUMP3  42
#define PUMP4  43
#define PUMP5  44
#define PUMP6  45

const byte KEYPAD_ROWS = 4; // Four rows
const byte KEYPAD_COLS = 4; // Three columns
// Define the Keymap

char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// ASCII value for the key pad
/*
{ 49,50,51,65
  52,53,54,66
  55,56,57,67
  42,48,35,68
}
*/

byte rowPins[KEYPAD_ROWS] = { 3, 2, 8, 0 };
byte colPins[KEYPAD_COLS] = { 7, 6, 5, 4 }; 
 
//////////////////////////////////////////////////DEFINE CLASS VARIABLES/////////////////////////////////////////////////////////
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS );

Heater_coil coil1(22);
Heater_coil coil2(23);
Heater_coil coil3(24);
Heater_coil coil4(25);
Heater_coil coil5(26);
Heater_coil coil6(27);

// change the ONtime 
Valve valve1A(28);
Valve valve2A(29);
Valve valve3A(30);
Valve valve4A(31);
Valve valve5A(32);
Valve valve6A(33);

Valve valve1B(34);
Valve valve2B(35);
Valve valve3B(36);
Valve valve4B(37);
Valve valve5B(38);
Valve valve6B(39);

Pump pump1(40);
Pump pump2(41);
Pump pump3(42);
Pump pump4(43);
Pump pump5(44);
Pump pump6(45);
//***************************************************************************************************

int choice1 = 0; // First choice 
int conf_choice = 0;
int initial = 0;
int current_time = 0;
int dispense = 0;
////////////// function prototypes ////////////
void preheatAni();
void displayChoices();
int getInput();
int confirmChoice(int);
void chooseCoil(int);
void choosePump(int);
void chooseValueA(int);
void chooseValueB(int);
void cooloff_coil(int);


///////////////////////////////////////////////////////////////SETUP///////////////////////////////////////////////////////////////////////////////
void setup()
{
    lcd.init();                      // initialize the lcd 
    lcd.backlight();
}

  
void loop()
{

    if(initial == 0)
    {
        lcd.setCursor(6,0);
        lcd.print("Welcome");
        lcd.setCursor(7,1);
        lcd.print("to the");
        lcd.setCursor(6,2);
        lcd.print("ODS 2000");
        lcd.setCursor(0,3);
        delay(1000);
        lcd.clear();
    }
    //// Main Progam///

    displayChoices();
    choice1 = getInput();
    conf_choice = confirmChoice(choice1);

    lcd.clear();
    chooseCoil(conf_choice);
    choosePump(conf_choice);
    lcd.setCursor(0,2);  
    lcd.print("To dispense");
    lcd.setCursor(0,3);
    lcd.print("'A' for yes");
    dispense= getInput();
    lcd.clear();
    if(dispense == 65)
    {
      chooseValveB(conf_choice);
      chooseValveA(conf_choice);
      cooloff_coil(conf_choice);
      choice1 = 0;
      conf_choice = 0;
      dispense = 0;
    }
    
    initial = 1;
//    chooseCoil(conf_choice);
//    choosePump(conf_choice);
//    lcd.clear()
//    lcd.setCursor(6,0);
//    lcd.print("Finished preheating");
//    lcd.clear();
//    lcd.setCursor(6,0);  
//    lcd.print("Press A to dispense");
//    lcd.setCursor(7,1);
//    lcd.print("Press D to cancel process")
//    dispense = getInput();
//    intial = 1;



}
   //////////////////////////////////////////////////// Display Choices////////////////////////////////////////////


int getInput()
{
    int input = 0;
    do
    {
        input = kpd.getKey();
    }
    while (input == 0);
    return input;
}

void displayChoices()
{
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Make A Selection"); 
    lcd.setCursor(0,1);
    lcd.print("1)Clove   4)Cinnamon");
    lcd.setCursor(0,2);
    lcd.print("2)Vanilla 5)Orange");
    lcd.setCursor(0,3);
    lcd.print("3)Banana  6)Rosemary");
}

int confirmChoice(int ans)
{
    int answer = ans;
    int input = 0;
    int result = 0;

    while(result == 0)
    {
          switch (answer) 
         {
          case 49:
                  lcd.clear();
                  lcd.setCursor(0,0);    
                  lcd.print("Clove selected");
                  lcd.setCursor(0,1);  
                  lcd.print("Is this correct?");
                  lcd.setCursor(0,2);  
                  lcd.print("'A' for yes,");
                  lcd.setCursor(0,3);
                  lcd.print("'D' for no");
                  
                  input = getInput();
                  lcd.clear();
                  while(input != 68 && input != 65)
                  {
                    
                    lcd.setCursor(0,2);  
                    lcd.print("'A' for yes,");
                    lcd.setCursor(0,3);
                    lcd.print("'D' for no");
                    input= getInput();
                    lcd.clear();
                  }
                  if (input == 68)
                  {
                    lcd.setCursor(1,1);
                    lcd. print ("Enter your desired");
                    lcd.setCursor(4,2);
                    lcd.print ("choice again.");
                    delay(2500);
                    displayChoices();
                    answer = getInput();
                    result = 0;
                    lcd.clear();
                  }
                  if(input  == 65)
                  {
                      lcd.setCursor(0,1);    
                      lcd.print("Selection confirmed!");
                      delay(2500);
                      lcd.clear();
                      result = 1;
                  }
                  
                  break;
          case 50:
                  lcd.clear();
                  lcd.setCursor(0,0);    
                  lcd.print("Vanilla selected.");
                  lcd.setCursor(0,1);  
                  lcd.print("Is this correct?");
                  lcd.setCursor(0,2);  
                  lcd.print("'A' for yes,");
                  lcd.setCursor(0,3);
                  lcd.print("'D' for no");
                  
                  input = getInput();
                  lcd.clear();
                  while(input != 68 && input != 65)
                  {
                    
                    lcd.setCursor(0,2);  
                    lcd.print("'A' for yes,");
                    lcd.setCursor(0,3);
                    lcd.print("'D' for no");
                    input= getInput();
                    lcd.clear();
                  }
                  if (input == 68)
                  {
                    lcd.setCursor(1,1);
                    lcd. print ("Enter your desired");
                    lcd.setCursor(4,2);
                    lcd.print ("choice again.");
                    delay(2500);
                    displayChoices();
                    answer = getInput();
                    result = 0;
                    lcd.clear();
                  }
                  if(input  == 65)
                  {
                      lcd.setCursor(0,1);    
                      lcd.print("Selection confirmed!");
                      delay(2500);
                      lcd.clear();
                      result = 1;
                  }
                  
                  break;

          case 51:
                  lcd.clear();
                  lcd.setCursor(0,0);    
                  lcd.print("Banana selected.");
                  lcd.setCursor(0,1);  
                  lcd.print("Is this correct?");
                  lcd.setCursor(0,2);  
                  lcd.print("'A' for yes,");
                  lcd.setCursor(0,3);
                  lcd.print("'D' for no");
                  
                  input = getInput();
                  lcd.clear();
                  while(input != 68 && input != 65)
                  {
                    
                    lcd.setCursor(0,2);  
                    lcd.print("'A' for yes,");
                    lcd.setCursor(0,3);
                    lcd.print("'D' for no");
                    input= getInput();
                    lcd.clear();
                  }
                  if (input == 68)
                  {
                    lcd.setCursor(1,1);
                    lcd. print ("Enter your desired");
                    lcd.setCursor(4,2);
                    lcd.print ("choice again.");
                    delay(2500);
                    displayChoices();
                    answer = getInput();
                    result = 0;
                    lcd.clear();
                  }
                  if(input  == 65)
                  {
                      lcd.setCursor(0,1);    
                      lcd.print("Selection confirmed!");
                      delay(1000);
                      lcd.clear();
                      result = 1;
                  }
                  
                  break;
          case 52:
                  lcd.clear();
                  lcd.setCursor(0,0);    
                  lcd.print("Cinnamon selected.");
                  lcd.setCursor(0,1);  
                  lcd.print("Is this correct?");
                  lcd.setCursor(0,2);  
                  lcd.print("'A' for yes,");
                  lcd.setCursor(0,3);
                  lcd.print("'D' for no");
                  
                  input = getInput();
                  lcd.clear();
                  while(input != 68 && input != 65)
                  {
                    
                    lcd.setCursor(0,2);  
                    lcd.print("'A' for yes,");
                    lcd.setCursor(0,3);
                    lcd.print("'D' for no");
                    input= getInput();
                    lcd.clear();
                  }
                  if (input == 68)
                  {
                    lcd.setCursor(1,1);
                    lcd. print ("Enter your desired");
                    lcd.setCursor(4,2);
                    lcd.print ("choice again.");
                    delay(2500);
                    displayChoices();
                    answer = getInput();
                    result = 0;
                    lcd.clear();
                  }
                  if(input  == 65)
                  {
                      lcd.setCursor(0,1);    
                      lcd.print("Selection confirmed!");
                      delay(2500);
                      lcd.clear();
                      result = 1;
                  }
                  
                  break;
          case 53:
                  lcd.clear();
                  lcd.setCursor(0,0);    
                  lcd.print("Orange selected.");
                  lcd.setCursor(0,1);  
                  lcd.print("Is this correct?");
                  lcd.setCursor(0,2);  
                  lcd.print("'A' for yes,");
                  lcd.setCursor(0,3);
                  lcd.print("'D' for no");
                  
                  input = getInput();
                  lcd.clear();
                  while(input != 68 && input != 65)
                  {
                    
                    lcd.setCursor(0,2);  
                    lcd.print("'A' for yes,");
                    lcd.setCursor(0,3);
                    lcd.print("'D' for no");
                    input= getInput();
                    lcd.clear();
                  }
                  if (input == 68)
                  {
                    lcd.setCursor(1,1);
                    lcd. print ("Enter your desired");
                    lcd.setCursor(4,2);
                    lcd.print ("choice again.");
                    delay(2500);
                    displayChoices();
                    answer = getInput();
                    result = 0;
                    lcd.clear();
                  }
                  if(input  == 65)
                  {
                      lcd.setCursor(0,1);    
                      lcd.print("Selection confirmed!");
                      delay(2500);
                      lcd.clear();
                      result = 1;
                  }
                  
                  break;
          case 54:
                  lcd.clear();
                  lcd.setCursor(0,0);    
                  lcd.print("Rosemary selected.");
                  lcd.setCursor(0,1);  
                  lcd.print("Is this correct?");
                  lcd.setCursor(0,2);  
                  lcd.print("'A' for yes,");
                  lcd.setCursor(0,3);
                  lcd.print("'D' for no");
                  
                  input = getInput();
                  lcd.clear();
                  while(input != 68 && input != 65)
                  {
                    
                    lcd.setCursor(0,2);  
                    lcd.print("'A' for yes,");
                    lcd.setCursor(0,3);
                    lcd.print("'D' for no");
                    input= getInput();
                    lcd.clear();
                  }
                  if (input == 68)
                  {
                    lcd.setCursor(1,1);
                    lcd. print ("Enter your desired");
                    lcd.setCursor(4,2);
                    lcd.print ("choice again.");
                    delay(2500);
                    displayChoices();
                    answer = getInput();
                    result = 0;
                    lcd.clear();
                  }
                  if(input  == 65)
                  {
                      lcd.setCursor(0,1);    
                      lcd.print("Selection confirmed!");
                      delay(2500);
                      lcd.clear();
                      result = 1;
                  }
                  
                  break;
          default:
                  lcd.clear();
                  lcd.setCursor(3,1);
                  lcd.print("Invalid entry.");
                  delay(1000);
                  lcd.setCursor(0,2);
                  lcd. print ("Enter a valid entry.");
                    delay(2500);
                    displayChoices();
                    answer = getInput();
                    result = 0;
                    lcd.clear();
                  break;
        }
   }
   return answer;
}


void chooseCoil(int answer)
{
  switch (answer) 
         {
          case 49:
                  coil1.turnon_coil();
                  while( (coil1.get_currentMillis() - coil1.get_previousMillis()) < coil1.get_OnTime() )
                  {
                        coil1.set_currentMillis(millis());
                  }
                  coil1.set_previousMillis(coil1.get_currentMillis());
                  break;
          case 50:
                  coil2.turnon_coil();
                  while( (coil2.get_currentMillis() - coil2.get_previousMillis()) < coil2.get_OnTime() )
                  {
                        coil2.set_currentMillis(millis());
                  }
                  coil2.set_previousMillis(coil2.get_currentMillis());
                  break;

          case 51:
                  coil3.turnon_coil();
                  while( (coil3.get_currentMillis() - coil3.get_previousMillis()) < coil3.get_OnTime() )
                  {
                        coil3.set_currentMillis(millis());
                  }
                  coil3.set_previousMillis(coil3.get_currentMillis());
                  break;
          case 52:
                  coil4.turnon_coil();
                  while( (coil4.get_currentMillis() - coil4.get_previousMillis()) < coil4.get_OnTime() )
                  {
                        coil4.set_currentMillis(millis());
                  }
                  coil4.set_previousMillis(coil4.get_currentMillis());
                  break;
          case 53:
                  coil5.turnon_coil();
                  while( (coil5.get_currentMillis() - coil5.get_previousMillis()) < coil5.get_OnTime() )
                  {
                        coil5.set_currentMillis(millis());
                  }
                  coil5.set_previousMillis(coil5.get_currentMillis());
                  break;
          case 54:

                  coil6.turnon_coil();
                  while( (coil6.get_currentMillis() - coil6.get_previousMillis()) < coil6.get_OnTime() )
                  {
                        coil6.set_currentMillis(millis());
                  }
                  coil6.set_previousMillis(coil6.get_currentMillis());
                  break;

          default:

                  break;
        }
}

void choosePump(int answer)
{

  switch (answer) 
         {
          case 49:
                  pump1.turnon_pump();
                  while( ( pump1.get_currentMillis() - pump1.get_previousMillis() ) < pump1.get_OnTime() )
                  {
                    pump1.set_currentMillis(millis());
                  }
                  pump1.set_previousMillis(pump1.get_currentMillis());
                  pump1.shutoff_pump();
                  break;
          case 50:
                  pump2.turnon_pump();
                  while( ( pump2.get_currentMillis() - pump2.get_previousMillis() ) < pump2.get_OnTime() )
                  {
                    pump2.set_currentMillis(millis());
                  }
                  pump2.set_previousMillis(pump2.get_currentMillis());
                  pump2.shutoff_pump();
                  break;
          case 51:
                  pump3.turnon_pump();
                  while( ( pump3.get_currentMillis() - pump3.get_previousMillis() ) < pump3.get_OnTime() )
                  {
                    pump3.set_currentMillis(millis());
                  }
                  pump3.set_previousMillis(pump3.get_currentMillis());
                  pump3.shutoff_pump();
                  break;
          case 52:
                  pump4.turnon_pump();
                  while( ( pump4.get_currentMillis() - pump4.get_previousMillis() ) < pump4.get_OnTime() )
                  {
                    pump4.set_currentMillis(millis());
                  }
                  pump4.set_previousMillis(pump4.get_currentMillis());
                  pump4.shutoff_pump();
                  break;
          case 53:
                  pump5.turnon_pump();
                  while( ( pump5.get_currentMillis() - pump5.get_previousMillis() ) < pump5.get_OnTime() )
                  {
                    pump5.set_currentMillis(millis());
                  }
                  pump5.set_previousMillis(pump5.get_currentMillis());
                  pump5.shutoff_pump();
                  break;
          case 54:
                  pump6.turnon_pump();
                  while( ( pump6.get_currentMillis() - pump6.get_previousMillis() ) < pump6.get_OnTime() )
                  {
                    pump6.set_currentMillis(millis());
                  }
                  pump6.set_previousMillis(pump6.get_currentMillis());
                  pump6.shutoff_pump();
                  break;
          default:

                  break;
        }
}


void chooseValveA(int answer)
{
  switch (answer) 
         {
          case 49:
                  valve1A.turnon_valve();
                  while( ( valve1A.get_currentMillis() - valve1A.get_previousMillis() ) < valve1A.get_OnTime() )
                  {
                    valve1A.set_currentMillis(millis());
                  }
                  valve1A.set_previousMillis(valve1A.get_currentMillis());
                  valve1A.shutoff_valve();
                  break;
          case 50:
                  valve2A.turnon_valve();
                  while( ( valve2A.get_currentMillis() - valve2A.get_previousMillis() ) < valve2A.get_OnTime() )
                  {
                    valve2A.set_currentMillis(millis());
                  }
                  valve2A.set_previousMillis(valve2A.get_currentMillis());
                  valve2A.shutoff_valve();
                  break;
          case 51:
                  valve3A.turnon_valve();
                  while( ( valve3A.get_currentMillis() - valve3A.get_previousMillis() ) < valve3A.get_OnTime() )
                  {
                    valve3A.set_currentMillis(millis());
                  }
                  valve3A.set_previousMillis(valve3A.get_currentMillis());
                  valve3A.shutoff_valve();
                  break;
          case 52:
                  valve4A.turnon_valve();
                  while( ( valve4A.get_currentMillis() - valve4A.get_previousMillis() ) < valve4A.get_OnTime() )
                  {
                    valve4A.set_currentMillis(millis());
                  }
                  valve4A.set_previousMillis(valve4A.get_currentMillis());
                  valve4A.shutoff_valve();
                  break;
          case 53:
                  valve5A.turnon_valve();
                  while( ( valve5A.get_currentMillis() - valve5A.get_previousMillis() ) < valve5A.get_OnTime() )
                  {
                    valve5A.set_currentMillis(millis());
                  }
                  valve5A.set_previousMillis(valve5A.get_currentMillis());
                  valve5A.shutoff_valve();
                  break;
          case 54:
                  valve6A.turnon_valve();
                  while( ( valve6A.get_currentMillis() - valve6A.get_previousMillis() ) < valve6A.get_OnTime() )
                  {
                    valve6A.set_currentMillis(millis());
                  }
                  valve6A.set_previousMillis(valve6A.get_currentMillis());
                  valve6A.shutoff_valve();
                  break;
          default:
                  break;
        }
}


void chooseValveB(int answer)
{
  switch (answer) 
         {
          case 49:
                  valve1B.turnon_valvePump();
                  while( ( valve1B.get_currentMillis() - valve1B.get_previousMillis() ) < valve1B.get_OnTime() )
                  {
                    valve1B.set_currentMillis(millis());
                  }
                  valve1B.set_previousMillis(valve1B.get_currentMillis());
                  valve1B.shutoff_valvePump();
                  break;
          case 50:
                  valve2B.turnon_valvePump();
                  while( ( valve2B.get_currentMillis() - valve2B.get_previousMillis() ) < valve2B.get_OnTime() )
                  {
                    valve2B.set_currentMillis(millis());
                  }
                  valve2B.set_previousMillis(valve2B.get_currentMillis());
                  valve2B.shutoff_valvePump();
                  break;
          case 51:
                  valve3B.turnon_valvePump();
                  while( ( valve3B.get_currentMillis() - valve3B.get_previousMillis() ) < valve3B.get_OnTime() )
                  {
                    valve3B.set_currentMillis(millis());
                  }
                  valve3B.set_previousMillis(valve3B.get_currentMillis());
                  valve3B.shutoff_valvePump();
                  break;
          case 52:
                  valve4B.turnon_valvePump();
                  while( ( valve4B.get_currentMillis() - valve4B.get_previousMillis() ) < valve4B.get_OnTime() )
                  {
                    valve4B.set_currentMillis(millis());
                  }
                  valve4B.set_previousMillis(valve4B.get_currentMillis());
                  valve4B.shutoff_valvePump();
                  break;
          case 53:
                  valve5B.turnon_valvePump();
                   while( ( valve5B.get_currentMillis() - valve5B.get_previousMillis() ) < valve5B.get_OnTime() )
                  {
                    valve5B.set_currentMillis(millis());
                  }
                  valve5B.set_previousMillis(valve5B.get_currentMillis());
                  valve5B.shutoff_valvePump();
                  break;
          case 54:
                  valve6B.turnon_valvePump();
                  while( ( valve6B.get_currentMillis() - valve6B.get_previousMillis() ) < valve6B.get_OnTime() )
                  {
                    valve6B.set_currentMillis(millis());
                  }
                  valve6B.set_previousMillis(valve6B.get_currentMillis());
                  valve6B.shutoff_valvePump();
                  break;
          default:
                  break;
        }
}


void cooloff_coil(int answer)
{
  switch (answer) 
         {
          case 49:
                  coil1.shutoff_coil();
                  break;
          case 50:
                  coil2.shutoff_coil();
                  break;
          case 51:
                  coil3.shutoff_coil();
                  break;
          case 52:
                  coil4.shutoff_coil();
                  break;
          case 53:
                  coil5.shutoff_coil();
                  break;
          case 54:
                  coil6.shutoff_coil();
                  break;                                                                        
          default:
                  break;
        }
}

void preheatAni(){
  for(int i=0; i<3;i++){
    lcd.setCursor(0,1);
    lcd.print("Preheating ");
    delay(100);
    lcd.setCursor(0,1);
    lcd.print("Preheating .");
    delay(100);
    lcd.setCursor(0,1);
    lcd.print("Preheating ..");
    delay(100);
    lcd.setCursor(0,1);
    lcd.print("Preheating ...");
    delay(100);
    lcd.setCursor(0,1);
    lcd.print("Preheating ....");
    delay(100);
    lcd.setCursor(0,1);
    lcd.print("Preheating .....");
    delay(100);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Preheating ....");
    delay(100);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Preheating ...");
    delay(100);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Preheating ..");
    delay(100);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Preheating .");
    delay(100);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Preheating ");
    delay(100);
    lcd.clear();
  };
    
}




  

