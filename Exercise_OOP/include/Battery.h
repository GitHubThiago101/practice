#ifndef BATTERY_H
#define BATTERY_H
//#include "Car.h"
#include <iostream>
using namespace std;

class Battery
{
public:
    Battery();
    ~Battery();

    int getEnergy(int);
    void charge(int);
    int currentEnergy();

private:

    int energy;
};

#endif // BATTERY_H
