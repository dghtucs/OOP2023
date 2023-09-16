#pragma once
#include "engine.h"
#include "wheel.h"
#include <string>
#include "vehicle.h"

class Motor : public Vehicle
{
public:
    Motor(int num, string engine) : Vehicle(num, engine)
    {
        cout << "Finish building a motor with "
             << this->wheel_.get_num() << " wheels and a " << this->engine_.get_name() << " engine." << endl;
    }
    void describe()
    {
        cout << "A motor with " << this->wheel_.get_num()
             << " wheels and a " << this->engine_.get_name() << " engine." << endl;
    }
    void sell();
};
