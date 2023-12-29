#ifndef ENGINE_H
#define ENGINE_H
#include "Controller.h"
#include "FuelTank.h"

class CarEngineDelegate{
public:
    virtual void runThisCar(int, Gear) = 0;

};


class Engine : public EngineControllerDelegate{
public:
    Engine();
    virtual ~Engine();
    void setDelegate(CarEngineDelegate&);
    void didChangeGear(Gear) override;
    void didStepOnAccelerator(int) override;
    int calcFuel(int, int, int);
    void setFuel(FuelTank& fueltank);

protected:

private:
    CarEngineDelegate *delegateCar;
    FuelTank *fueltank;
    Gear currentG;
};

#endif // ENGINE_H
