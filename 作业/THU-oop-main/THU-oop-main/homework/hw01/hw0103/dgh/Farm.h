#pragma once
#include<iostream>
#include<vector>
#include"Cow.h"


class Farm
{
private:
    /* data */
    int n;
    std::vector<Cow> CowArr;
public:
    Farm(int num):n(num){}
    ~Farm();
    void addCow(Cow c);
    void supply(std::string name,double a);
    void produceMilk();
};



Farm::~Farm()
{
}




















