#ifndef LIGHT_H
#define LIGHT_H
#include "Controller.h"
#include "Battery.h"
#include <thread>
#include <unistd.h>

class Light : public LightControllerDelegate
{
    public:
        Light();
        virtual ~Light();
        void operator()();
        void didTurnLight(StateLight) override;
        void setBattery(Battery& battery);

    protected:

    private:
        Battery* battery;
        StateLight currentstatus;
};

#endif // LIGHT_H
