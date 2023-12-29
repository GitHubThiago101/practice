#ifndef HMI_H
#define HMI_H
#include <iostream>
#include "Controller.h"
//#include "Car.h"
using namespace std;

class HMI
{
public:
    HMI();
    ~HMI();
    void showInfor(int, int, Gear);
//    void showInfor(int, int);
//    void showInfor(int);
//    void showInfor(Gear);
//    void showInfor(int, Gear);

};

#endif // HMI_H
