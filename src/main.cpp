#include <Cocktail.h>
#include <LCD.h>
#include <StandardCplusplus.h>
#include <serstream>
#include <vector>
#include <Arduino.h>
#include <string>
#include <string.h>

using namespace std;

int CocktailIndex = 0;

volatile unsigned long rightButtonpressed = 0;
volatile unsigned long leftButtonpressed = 0;

vector<Cocktail> cocktails;
LCD* display;

void RightArrowPress()
{
  if(digitalRead(2) == LOW)
  {
    rightButtonpressed = millis();
  }

  if(digitalRead(2) == HIGH)
  {
    if((millis() - rightButtonpressed) > 100)
    {
      ++CocktailIndex;
      if((int)cocktails.size() <  CocktailIndex)
      {
        CocktailIndex = 0;
      }
      Serial.println(CocktailIndex);
    }
  }
}

void LeftArrowPress()
{
   if(digitalRead(3) == LOW)
  {
    leftButtonpressed = millis();
  }

  if(digitalRead(3) == HIGH)
  {
    if((millis() - leftButtonpressed) > 100)
    {
      CocktailIndex--;
      if(CocktailIndex < 0)
      {
        CocktailIndex = (int)cocktails.size();
      }
      Serial.println(CocktailIndex);
    }
  }
}



void AddCocktails()
{
  Cocktail sexOnTheBeach("Sex OT Beach");
  sexOnTheBeach.AddLiquor("vodka", 30);
  sexOnTheBeach.AddLiquor("Peach Liquor", 30);
  cocktails.push_back(sexOnTheBeach);

  Cocktail mojito("mojito");
  mojito.AddLiquor("Bacardi", 50);
  cocktails.push_back(mojito);
}

void setup() {
  Serial.begin(9600);
  display = new LCD();
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), RightArrowPress,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), LeftArrowPress, CHANGE);
  AddCocktails();
}

void loop() {
  display->WriteToLCD(cocktails.at(CocktailIndex).getCocktailName());
  //static LCD display;
  //lcd.setCursor(1,1);
  //lcd.print(cocktails.at(CocktailIndex).getCocktailName().c_str());

}




