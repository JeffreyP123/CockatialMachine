#ifndef LIQUOR_H
#define LIQUOR_H

#include <StandardCplusplus.h>
#include <vector>
#include <string>

using namespace std;

class Liquor
{
    private:
        string liquorName;
        int liquorMilliliter;
        
    public:
       Liquor(string liquorName,  int liquorMilliliter);
        string getLiquorName() const;
        int getLiquorMilliliter() const;
        ~Liquor();
};
#endif