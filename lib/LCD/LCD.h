#ifndef LCD_H
#define LCD_H

#include <StandardCplusplus.h>
#include <string>
#include <string.h>
#include <LiquidCrystal.h>

using namespace std;

#define RS 12
#define D0, 11
#define D4, 7
#define D5, 6
#define D6, 5
#define D7, 4

LiquidCrystal* lcd;

class LCD
{
    private:
        void InitLCD();
    public:
        LCD();
        ~LCD();
        void WriteToLCD(string value);
};
#endif