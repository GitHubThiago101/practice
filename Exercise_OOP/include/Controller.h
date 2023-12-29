#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>

using namespace std;


enum Gear {
    N,
    D,
    R,
    L1,
    L2
};

enum StateLight {
    ON,
    OFF
};

class EngineControllerDelegate{
    public:
        virtual void didStepOnAccelerator(int) = 0;
        virtual void didChangeGear(Gear) = 0;
};

class LightControllerDelegate
{
public:
    virtual void didTurnLight(StateLight) = 0;
};

class Controller
{
    public:

        void changeGear(Gear);
        void stepOnAccelerator(int);
        void turnLight(StateLight);

        Controller();
        virtual ~Controller();
        Controller(const Controller& other);
        Controller& operator=(const Controller& other);

        void setDelegate(EngineControllerDelegate&);
        void setDelegateLight(LightControllerDelegate&);

    protected:

    private:
        Gear gear;
        int percent;
        EngineControllerDelegate *delegate;
        LightControllerDelegate *controlLight;
};

#endif // CONTROLLER_H
