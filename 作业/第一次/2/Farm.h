#pragma once
#include<string>
#include<vector>
#include"Cow.h"
using namespace std;


class Farm
{
private:
    /* data */
    int n_;
    std::vector<Cow> cows;
    static double milk_;
public:
    Farm(int n);
    ~Farm();
    void addCow(Cow c);
    void supply(std::string s,int a);
    void startMeal();
    void produceMilk();
    double getMilkProduction();
};













