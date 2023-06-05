#pragma once
#include<string>
#include<vector>
#include"Cow.h"

class Farm
{
private:
    /* data */
    int n_;
    std::vector<Cow> cows;
    
public:
    Farm(int n);
    ~Farm();
    void addCow(Cow c);
    void supply(std::string s,double a);
};

Farm::Farm(int n)
{
    n_ = n;
    cows.reserve(n_);
}

Farm::~Farm()
{
}












