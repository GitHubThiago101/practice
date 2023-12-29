#include "Engine.h"
#include "Controller.h"
#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

Engine::Engine()
{
    //ctor
}

Engine::~Engine()
{
    //dtor
}

void Engine::setFuel(FuelTank& fueltank)
{
    this->fueltank = &fueltank;
}

void Engine::setDelegate(CarEngineDelegate& del){
    delegateCar = &del;
}

void Engine::didChangeGear(Gear g){
    currentG = g;
}

void Engine::didStepOnAccelerator(int percent){

    int fuel = fueltank->currentFuel();
    int distance = 0;
    if (percent >= 1 && percent <=100)
    {
        if (currentG == ::N)
        {
            cout << "Stop" << endl;
        }
        else if (currentG == ::D)
        {
            cout << "Go forward " << percent << " m" << endl;
            distance = calcFuel(10, fuel, percent);
        }
        else if (currentG == ::R)
        {
            cout << "Go back " << percent << " m" << endl;
            distance = calcFuel(30, fuel, percent);
        }
        else if (currentG == ::L1)
        {
            cout << "Go L1 mode, " << percent << " m" << endl;
            distance = calcFuel(30, fuel, percent);
        }
        else if (currentG == ::L2)
        {
            cout << "Go L2 mode, " << percent << " m" << endl;
            distance = calcFuel(20, fuel, percent);
        }
        else cout << "ERROR";
    }
    else cout << "ERROR";
    delegateCar->runThisCar(distance, currentG);
}

int Engine::calcFuel(int m, int fuel, int percent)
{
    int distance = 0;
    if (fuel >= percent * m)
    {
        cout << "Enough to go!!" << endl;
        fuel = fueltank->currentFuel() - fueltank->getFuel(percent * m);
        distance = percent;
        cout << "The remaining of fuel : " << fuel << endl;
    }
    else
    {
        cout << "Lack of fuel " << percent * m - fuel << " to get the target" << endl;
        cout << "Just can go " << fuel/m << " m" << endl;
        distance = fuel/m;
        fueltank->getFuel(fuel);
    }
    return distance;
}
