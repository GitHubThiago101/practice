#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <fstream>
using namespace std;

enum Door
{
    TwoDoor, //0
    ThreeDoor, //1
    FourDoor
};

constexpr const char* DoorToString(Door d) throw()
{
    switch (d)
    {
        case Door::TwoDoor: return "2";
        case Door::ThreeDoor: return "3";
        case Door::FourDoor: return "4";
        default: throw std::invalid_argument("Unimplemented item");
    }
}

enum Screen
{
    Nine_inch_horizontal,
    Nine_inch_vertical,
    Eleven_inch_horizontal,
    Eleven_inch_vertical,
    Fifteen_inch_horizontal
};

constexpr const char* ScreenToString(Screen s) throw()
{
    switch (s)
    {
        case Screen::Nine_inch_horizontal: return "9 inch horizontal";
        case Screen::Nine_inch_vertical: return "9 inch vertical";
        case Screen::Eleven_inch_horizontal: return "11 inch horizontal";
        case Screen::Eleven_inch_vertical: return "11 inch vertical";
        case Screen::Fifteen_inch_horizontal: return "15 inch horizontal";
        default: throw std::invalid_argument("Unimplemented item");
    }
}

enum AirConditioner
{
    Auto,
    Manual
};

constexpr const char* AirConditionerToString(AirConditioner a) throw()
{
    switch (a)
    {
        case AirConditioner::Auto: return "Auto";
        case AirConditioner::Manual: return "Manual";
        default: throw std::invalid_argument("Unimplemented item");
    }
}

enum Gear
{
    AutoGear,
    ManualGear,
    Mixed
};

constexpr const char* GearToString(Gear g) throw()
{
    switch (g)
    {
        case Gear::AutoGear: return "Auto";
        case Gear::ManualGear: return "Manual";
        case Gear::Mixed: return "Mixed";
        default: throw std::invalid_argument("Unimplemented item");
    }
}

class Config
{
    public:
        Config();
        Config(Door, Screen, AirConditioner, Gear);
        void setNumberOfDoor(Door);
        void setScreen(Screen);
        void setAirConditioner(AirConditioner);
        void setGear(Gear);
        virtual ~Config();

        void save(string&);
        void load(string&);
        void show();

    protected:

    private:
        Door door;
        Screen screen;
        AirConditioner air;
        Gear gear;
        uint8_t sum;
        short doornumber;
        short screensize;
        short aircon;
        short geartype;
};
#endif // CONFIG_H
