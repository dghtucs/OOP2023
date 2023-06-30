#pragma once

#include "constfunc.h"
#include "func.h"

class LinearFunc : public Func{
private:
    double _a;
    double _b;
public:
    LinearFunc(double a, double b) : _a(a), _b(b) {}
    double getPoint(double point) {
        return _a * point + _b;
    }
};