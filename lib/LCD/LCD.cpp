#include "LCD.h"



static byte leftArrow[8]= {
  B00000,
  B00011,
  B00111,
  B01111,
  B11111,
  B01111,
  B00111,
  B00011
};

static byte rightArrow[8]= {
  B00000,
  B11000,
  B11100,
  B11110,
  B11111,
  B11110,
  B11100,
  B11000
};

LCD::LCD()
{
    lcd = new LiquidCrystal(RS,D0,D4,D5,D6,D7);
    InitLCD();
}

LCD::~LCD()
{
}

void LCD::InitLCD()
{
    lcd->begin(LenghtRow,Row);
    lcd->createChar(6, leftArrow);
    lcd->createChar(7, rightArrow);
    lcd->setCursor(1,0);
    lcd->print("Select Cockatil");
    lcd->setCursor(0,1);
    lcd->write(6);
    lcd->setCursor(15,1);
    lcd->write(7);
    lcd->setCursor(1,1);
    Serial.println("Display setup");
}

void LCD::WriteToLCD(string value)
{
    lcd->print("              ");
    lcd->setCursor(1,1);
    lcd->print(value.c_str());
    lcd->setCursor(1,1);
}

void LCD::WriteCharToLCD(int index)
{
    lcd->write(index);
}

