#include "Farm.h"
double Farm::milk_ = 0;
void Farm::addCow(Cow c)
{
    cows.push_back(c);
}

void Farm::supply(std::string s, int a)
{
    for (auto &c : cows)
    {
        if (c.name_ == s)
            c.leftFood_ += a;
    }
}

void Farm::startMeal()
{
    for(auto &c : cows)
    {
        if(c.leftFood_==0)
        {
            continue;
        }
        if(c.leftFood_>c.u_)
        {
            c.leftFood_-=c.u_;
            milk_+=c.m_;
        }
        else if(c.leftFood_>=c.l_)
        {
            c.leftFood_=0;
            milk_+=c.m_;
        }
        else
        {
            c.leftFood_=0;
            milk_+=1.0*c.m_/2;
        }
    }
}

void Farm::produceMilk()
{
}

double Farm::getMilkProduction()
{
    return milk_;
}

Farm::Farm(int n)
{
    n_ = n;
    cows.reserve(n_);
}

Farm::~Farm()
{
}
