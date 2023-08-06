#include"Farm.h"




void Farm::addCow(Cow c){
    CowArr.push_back(c);
}

void Farm::supply(std::string name,double a)
{
    for(auto c : CowArr)
    {
        if(c.name == name)
            c.feed = a;
        else
            continue;
    }
}

void Farm::produceMilk()
{
    for(auto c:CowArr)
    {

    }
}

double Farm::getMilkProduction()
{
    double milkToday = 0;
    for(auto c : CowArr)
    {
        milkToday += c.milkEveryday;
        c.milkEveryday = 0;
    }
    for(auto c : CowArr)
    {
        c.feed = 0;
    }
    return milkToday;
}


void Farm::startMeal()
{
    for(auto c : CowArr)
    {
        c.feed = c.feed + c.remain;
        if(c.feed == 0)
            c.milkEveryday = 0;
        else if(c.feed >= c.l && c.feed <= c.u)
            c.milkEveryday = c.m;
        else if(c.feed < c.l)
            c.milkEveryday = c.m / 2;
        else if(c.feed > c.u)
        {
            c.milkEveryday = c.m;
            c.remain = c.feed - c.u;

        }
    }
}


