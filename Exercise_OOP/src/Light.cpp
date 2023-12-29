#include "Light.h"
#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

Light::Light()
{
    //ctor

}

Light::~Light()
{
    //dtor
}

void Light::operator()()
{
    while (battery->currentEnergy() > 0)
    {

        cout << "Energy : " << battery->currentEnergy() << endl;
        battery->getEnergy(1);
        sleep(1);
    }
    cout << "Light is OFF" << endl;
}

void Light::didTurnLight(StateLight status)
{
    cout << " " << endl;
    cout << "----Control light----" << endl;
    currentstatus = status;
    int temp = battery->getEnergy(5);
    if (currentstatus == ::ON && temp >= 5)
    {
        cout << "Light is ON" << endl;
        cout << "The remaining energy " << battery->currentEnergy() << " mAh" << endl;
        thread th1(*this);
        th1.detach();
        if (th1.joinable()) th1.join();

    }
    else if (currentstatus == ::OFF)
    {
        cout << "Light is OFF" << endl;
    }
    else
    {
        cout << "Not enough energy to turn the light ON!!" << endl;
        cout << "The remaining of energy : " << temp << endl;
    }

    cout << " " << endl;
}
void Light::setBattery(Battery& battery)
{
    this->battery = &battery;
}
