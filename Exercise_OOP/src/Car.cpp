#include "Car.h"
#include <iostream>
using namespace std;

int Car::counter = 0;

Car::Car()
{
    //ctor
    battery = new Battery();
    engine = new Engine();
    light = new Light();
    fueltank = new FuelTank();
    controller = new Controller();
    hmi = new HMI();

    controller->setDelegate(*engine);
    engine->setDelegate(*this);
    controller->setDelegateLight(*light);

    light->setBattery(*battery);
    engine->setFuel(*fueltank);
    ++counter;
}

Car::~Car()
{
    //dtor
    delete fueltank;
    delete battery;
    delete controller;
    delete engine;
    delete battery;
    delete hmi;
    delete light;
}

void Car::printCount(void)
{
    cout << "count:" << counter << "\n";
}

void Car::runThisCar(int distance, Gear gear)
{
//    cout << " " << endl;
//    cout << "----Controller sent signal to car----" << endl;
    battery->charge(distance);

    int energy = battery->currentEnergy();
    int fuel = fueltank->currentFuel();
    hmi->showInfor(fuel, energy, gear);
}

Controller* Car::getController(){
    return controller;
}

