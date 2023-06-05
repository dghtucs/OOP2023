#pragma once
#include<string>

class Cow
{
public:
    /* data */
    std::string name_;
    double l_,u_,m_,feed;
    Cow(std::string n,double l,double u,double m);
    ~Cow();
};

Cow::Cow(std::string n,double l,double u,double m)
{
    name_ = n;
    l_ = l;
    u_ = u;
    m_ = m;
    feed = 0;
}

Cow::~Cow()
{
}













