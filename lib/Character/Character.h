#ifndef CHARACTER_H
#define CHARACTER_H
#include <Arduino.h>

byte leftArrow[8]= {
  B00000,
  B00011,
  B00111,
  B01111,
  B11111,
  B01111,
  B00111,
  B00011
};

byte rightArrow[8]= {
  B00000,
  B11000,
  B11100,
  B11110,
  B11111,
  B11110,
  B11100,
  B11000
};

#endif