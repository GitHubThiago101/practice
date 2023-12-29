#include "FuelTank.h"
//#include "Car.h"
//#include "Engine.h"
#include <iostream>
using namespace std;

FuelTank::FuelTank()
{
    //ctor
    fuel = 1000;
}

FuelTank::~FuelTank()
{
    //dtor
}

int FuelTank::getFuel(int needed)
{
    if (fuel > needed)
    {
        fuel -= needed;
        return needed;
    }
    else
    {
        int temp = fuel;
        fuel = 0;
        return temp;
    }
}

int FuelTank::currentFuel()
{
    if (fuel <= 75000) return fuel;
    else
    {
        int temp = fuel;
        fuel = 75000;
        return temp;
    }

}


