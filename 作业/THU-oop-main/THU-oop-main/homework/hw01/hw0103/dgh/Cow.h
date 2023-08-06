#ifndef COW_H
#define COW_H
#include<iostream>

class Cow
{
private:
    /* data */
    

public:
    std::string name;
    double l,u,m;
    double feed;
    double milkEveryday;
    double remain;

    Cow::Cow(std::string n,double l,double u,double m);
    ~Cow();
};



Cow::~Cow()
{
}






















#endif