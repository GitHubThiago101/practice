#ifndef CAR_H
#define CAR_H
#include "Controller.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Light.h"
#include "Battery.h"
#include "HMI.h"
#include <iostream>
using namespace std;


class Car : public CarEngineDelegate
{
public:
    static int counter;
    Car();
    Controller* getController();

    virtual ~Car();

    static void printCount();
    void runThisCar(int, Gear) override;

protected:

private:
    Engine* engine;
    FuelTank* fueltank;
    Battery* battery;
    Light* light;
    Controller* controller;
    HMI* hmi;
};
#endif // CAR_H






