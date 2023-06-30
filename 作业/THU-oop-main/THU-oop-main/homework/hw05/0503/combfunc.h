#pragma once

#include "func.h"

class CombFunc : public Func{
private:
    
    Func *_fun_1;
    Func *_fun_2;
    double _coe_1;
    double _coe_2;
public:
    CombFunc(Func *fun_1, Func *fun_2, double coe_1, double coe_2) :
        _fun_1(fun_1), _fun_2(fun_2), _coe_1(coe_1), _coe_2(coe_2){};
    double getPoint(double point) {
        return _coe_1 * _fun_1->getPoint(point) + _coe_2 * _fun_2->getPoint(point);
    }
    

    ~CombFunc() {
        delete _fun_1;
        delete _fun_2;
    }
};