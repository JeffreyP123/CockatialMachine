#include "Cocktail.h"

Cocktail::Cocktail(string cocktailName)
    :cocktailName(cocktailName)
{
}

Cocktail::~Cocktail(){}

int Cocktail:: AddLiquor(string name, int milliliters)
{
    if(milliliters >0)
    {
        Liquor temp(name, milliliters);
        liquors.push_back(temp);
        return 0;
    }
    return 1;
   
}

string Cocktail::getCocktailName()
{
    return Cocktail::cocktailName;
}

vector<Liquor> Cocktail::getLiquors()
{
   return Cocktail::liquors;
}