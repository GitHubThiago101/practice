//#include <iostream>
//#include "Config.h"
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    Config con1(::ThreeDoor, ::Eleven_inch_horizontal, ::Auto, ::AutoGear);
//    Config con2(::TwoDoor, ::Nine_inch_vertical, ::Manual, ::Mixed);
//    con1.setNumberOfDoor(::ThreeDoor);
//    con1.setScreen(::Eleven_inch_horizontal);
//    con1.setAirConditioner(::Auto);
//    con1.setGear(::AutoGear);
//
//    string path = "data.dat";
//    con1.save(path);
//    con2.save(path);
//
//    Config c1;
//    Config c2;
//    c1.load(path);
//    c2.load(path);
//
//    c1.setNumberOfDoor(::TwoDoor);
//    c1.setScreen(::Fifteen_inch_horizontal);
//    c1.setAirConditioner(::Auto);
//    c1.setGear(::Mixed);
//
//    c1.save(path);
//
//    Config go;
//    go.load(path);
//    return 0;
//}

#include <iostream>
#include "Config.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{
    Config con1(::ThreeDoor, ::Eleven_inch_horizontal, ::Auto, ::AutoGear);

    string path = "data.dat";
    con1.save(path);

    Config c1;
    c1.load(path);

    c1.setNumberOfDoor(::TwoDoor);
    c1.setScreen(::Fifteen_inch_horizontal);
    c1.setAirConditioner(::Auto);
    c1.setGear(::Mixed);

    c1.save(path);

    Config go;
    go.load(path);
    return 0;
}
