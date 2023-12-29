#ifndef FUELTANK_H
#define FUELTANK_H
#include <iostream>
#include <Controller.h>
//#include "Engine.h"
using namespace std;



class FuelTank
{
public:
    FuelTank();
    ~FuelTank();
    int getFuel(int);
    int currentFuel();
private:
    int fuel;
};

#endif // FUELTANK_H
