// C++ code
//
#include <LiquidCrystal.h>

int photpin=2;
int relpin=3;                                     //Decralation
int sensvalue=0;

const int rs = 8, en = 7, d4 = 6, d5 = 5, d6 = 4, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  pinMode(photpin, INPUT);            //Stating if pin is OUT/IN PUT
  pinMode(relpin, OUTPUT);
  lcd.begin(0,0);     //Marking the starting cordinates
}

void loop()
{ 
  sensvalue=analogRead(photpin); //Geting sensor value
  lcd.print(sensvalue);         //printing the value on LCD          
  lcd.setCursor(0,0);         //Setting the cordinates of cursal
  
  
  if (sensvalue < 350) {         // Checking if light intensity is below 350
    digitalWrite(relpin, HIGH);  //Lighting Bulb
  } else {
    digitalWrite(relpin, LOW);   //Offing Bulb
  }
  delay(90); // Delaying a little bit to improve simulation performance
}