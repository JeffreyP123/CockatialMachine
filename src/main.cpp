#include <Cocktail.h>
#include <Cocktail.h>
#include <StandardCplusplus.h>
#include <serstream>
#include <vector>
#include <Arduino.h>
#include <string>
#include <string.h>

using namespace std;


int CocktailIndex = 0;

volatile unsigned long buttonpressed = 0;

vector<Cocktail> cocktails;

void RightArrowPress()
{
  
  if(digitalRead(2) == LOW)
  {
    if((millis() - buttonpressed) >= 100)
    {
      buttonpressed = millis();
      CocktailIndex++;
       Serial.println(CocktailIndex);
      if(((int)cocktails.size()) < CocktailIndex)
      {
        CocktailIndex = 0;
      }

    }
  
  }
}

void SetupLCD()
{
  lcd.createChar(6, leftArrow);
  lcd.createChar(7, rightArrow);
  lcd.setCursor(1,0);
  lcd.print("Select Cocktail");
  lcd.setCursor(0,1);
  lcd.write(6);
  lcd.setCursor(15,1);
  lcd.write(7);
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
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), RightArrowPress,CHANGE);
  lcd.begin(16,2);
  SetupLCD();
  AddCocktails();

}

void loop() {
  lcd.setCursor(1,1);
  lcd.print(cocktails.at(CocktailIndex).getCocktailName().c_str());

}




