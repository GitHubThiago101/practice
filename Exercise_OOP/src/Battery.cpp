#include "Battery.h"
#include "Car.h"
#include <iostream>
#include <mutex>
using namespace std;

mutex m2;

Battery::Battery()
{
    //ctor
    energy = 0;
}

Battery::~Battery()
{
    //dtor
}

int Battery::getEnergy(int needed)
{
    m2.lock();
    if (energy >= needed)
    {
        energy -= needed;
        m2.unlock();
        return needed;
    }
    else
    {
        int temp = energy;
        energy = 0;
        m2.unlock();
        return temp;
    }
}

int Battery::currentEnergy()
{
    return energy;
}

void Battery::charge(int percent)
{
    m2.lock();
    energy += percent;
//    if (energy < 1000) cout << "Charged " << energy << " mAh" << endl;
//    else
//    {
//        cout << "Energy is full now!!" << endl;
//        energy = 1000;
//    }
    if (energy > 1000) energy = 1000;
    m2.unlock();
}
