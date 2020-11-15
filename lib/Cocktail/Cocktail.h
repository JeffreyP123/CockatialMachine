#ifndef COCKTAIL_H
#define COCKTAIL_H

#include <Liquor.h>
#include <StandardCplusplus.h>
#include <vector>
#include <string>

using namespace std;

class Cocktail
{
    private:
    string cocktailName;
    vector<Liquor> liquors;

    public:
        Cocktail(string cocktailName);
        ~Cocktail();
        int AddLiquor(string name, int milliliters);
        string getCocktailName();
        vector<Liquor> getLiquors();

};
#endif