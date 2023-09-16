#pragma once
#include "engine.h"
#include "wheel.h"
#include <string>
#include "vehicle.h"

class Car : public Vehicle//用公开继承
{
public:
    Car(int num, string engine) : Vehicle(num, engine)//使用父类的构造函数简化
    {
        cout << "Finish building a car with "
             << this->wheel_.get_num() << " wheels and a " << this->engine_.get_name() << " engine." << endl;
    }
    void describe()//重写覆盖父类的函数
    {
        cout << "A car with " << this->wheel_.get_num()
             << " wheels and a " << this->engine_.get_name() << " engine." << endl;
    }
};
