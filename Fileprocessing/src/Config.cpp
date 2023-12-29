#include "Config.h"
#include <iostream>
#include <fstream>
using namespace std;

Config::Config()
{
    //ctor
//    sum = 0;
}

Config::~Config()
{
    //dtor
}

Config::Config(Door door, Screen screen, AirConditioner air, Gear gear)
{
    this->door = door;
    this->screen = screen;
    this->air = air;
    this->gear = gear;
}

void Config::setNumberOfDoor(Door door)
{
    this->door = door;
}

void Config::setScreen(Screen screen)
{
    this->screen = screen;
}
void Config::setAirConditioner(AirConditioner air)
{
    this->air = air;
}

void Config::setGear(Gear gear)
{
    this->gear = gear;
}

void Config::show()
{
    cout << "Number of Door : " << DoorToString(Door(doornumber))
    << "\t\tScreen Size : " << ScreenToString(Screen(screensize))
    << "\t\tAir Conditioner Type : " << AirConditionerToString(AirConditioner(aircon))
    << "\t\tGear Type : " << GearToString(Gear(geartype)) << endl;
}

void Config::save(string& path)
{
    ofstream f(path, ios::binary | ios::out);
    sum = 0;
    sum = sum | gear;
    sum = sum | (air << 2);
    sum = sum | (screen << 3);
    sum = sum | (door << 6);
    f.write((char*)&sum, sizeof(sum));
    f.close();
}

void Config::load(string& path)
{
    ifstream f(path, ios::binary | ios::in);
    f.read((char*)&sum, sizeof(sum));
    doornumber = sum >> 6;
    screensize = (sum >> 3) & 7;
    aircon = (sum >> 2) & 1;
    geartype = (sum >> 0) & 3;
    f.close();
    this->show();
}
