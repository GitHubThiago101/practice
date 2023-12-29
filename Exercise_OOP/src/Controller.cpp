#include "Controller.h"
#include "Engine.h"
#include "Car.h"
#include "Light.h"
#include <iostream>
using namespace std;


Controller::Controller()
{

}

Controller::~Controller()
{
    //dtor
}

Controller::Controller(const Controller& other)
{
    //copy ctor
}

Controller& Controller::operator=(const Controller& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Controller::setDelegate(EngineControllerDelegate& g){
    delegate = &g;
}
void Controller::changeGear(Gear g){
    gear = g;
    delegate->didChangeGear(gear);
}

void Controller::stepOnAccelerator(int per){
    percent = per;
    delegate->didStepOnAccelerator(percent);

}

void Controller::setDelegateLight(LightControllerDelegate &l)
{
    controlLight = &l;
}


void Controller::turnLight(StateLight state){
    controlLight->didTurnLight(state);
}
