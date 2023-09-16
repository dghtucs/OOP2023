#pragma once
#include "engine.h"
#include "wheel.h"
#include <string>
using namespace std;
class Vehicle
{
protected://用protected使子类可以访问父类的数据
    /* data */
    Engine engine_;
    Wheel wheel_;

public:
    


    Vehicle() = default;
    Vehicle(int, string);
    ~Vehicle();
    void describe();
};

