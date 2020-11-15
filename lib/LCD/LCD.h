#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <StandardCplusplus.h>
#include <string>
#include <string.h>
#include <LiquidCrystal.h>

using namespace std;

#define Row 2
#define LenghtRow 16

#define RS 12
#define D0 11
#define D4 7
#define D5 6
#define D6 5
#define D7 4


class LCD
{
    private:
        void InitLCD();
        LiquidCrystal* lcd;
    public:
        LCD();
        ~LCD();
        void WriteToLCD(string value);
        void WriteCharToLCD(int index);
};
#endif