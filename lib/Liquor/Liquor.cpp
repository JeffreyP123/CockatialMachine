#include "Liquor.h"

Liquor::Liquor(string liquorName,  int liquorMilliliter)
    :liquorName(liquorName),
     liquorMilliliter(liquorMilliliter)
{    
}

Liquor::~Liquor(){}

string Liquor::getLiquorName() const
{
    return  liquorName;
}

int Liquor::getLiquorMilliliter() const
{
    return liquorMilliliter;
}