#ifndef COW_H
#define COW_H

#include<string>
using namespace std;

class Cow
{
private:
    /* data */
    

public:
    string c_name;
    double c_low,c_upper,c_dailyMilk;
    double c_totalfeed;
    double milkPerdayPercow;
    double c_milkProduction;

    Cow(string n,double l,double u,double m);
    ~Cow();
};























#endif