#pragma once

#include "func.h"

class CompFunc : public Func{
private:
    
    Func *_outer;
    Func *_inner;
public:
    CompFunc(Func *outer, Func* inner) : _outer(outer), _inner(inner){};
    
    double getPoint(double point) {
        return _outer->getPoint(_inner->getPoint(point));
    }
    ~CompFunc() {
        delete _outer;
        delete _inner;
    }
};