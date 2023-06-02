#pragma once
#include<string>

class Cow
{
private:
    /* data */
    std::string name_;
    double l_,u_,m_;
public:
    Cow(std::string n,double l,double u,double m);
    ~Cow();
};

Cow::Cow(std::string n,double l,double u,double m)
{
    name_ = n;
    l_ = l;
    u_ = u;
    m_ = m;
}

Cow::~Cow()
{
}













