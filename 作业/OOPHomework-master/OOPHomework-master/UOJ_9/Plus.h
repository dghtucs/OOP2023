#pragma once

#include "Operator.h"
#include "Value.h"

class Plus: public Operator {
public:
    Plus(Value*, Value*);
    virtual int calc() override;
};