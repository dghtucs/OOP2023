#pragma once
#include"Cow.h"

class Farm
{
private:
    /* data */
    int n_;
    Cow* p;
public:
    Farm(int n);
    ~Farm();
    void addCow(Cow c);
};

Farm::Farm(int n)
{
    n_ = n;
    p = new Cow[n];
}

Farm::~Farm()
{
}












