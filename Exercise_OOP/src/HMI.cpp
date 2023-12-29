#include "HMI.h"
#include <iostream>
using namespace std;

HMI::HMI()
{
    //ctor
}

HMI::~HMI()
{
    //dtor
}

void HMI::showInfor(int fuel, int battery, Gear gear)
{
    cout << " " << endl;
    cout << "----Information of Car----" << endl;
    cout << "Fuel : " << fuel << endl;
    cout << "Battery : " << battery << endl;
    cout << "Gear : " << gear << endl;
}
