//Cow.cpp
#include<iostream>
#include<string>
#include "Cow.h"
using namespace std;
Cow::Cow(string name, int lowFeed, int upperFeed, double dailyMilk)
    : name_(name), lowFeed_(lowFeed), upperFeed_(upperFeed),dailyMilk_(dailyMilk)
    {}

void Cow::eat(int feedCase) {
    
    if(feedCase == 1) { 
        milkPerDayPerCow = dailyMilk_ / 2;
    }
    else if(feedCase == 2) { 
        milkPerDayPerCow = 0;
    }
    else if(feedCase == 3){ 
        milkPerDayPerCow = dailyMilk_;
    }
    else if(feedCase == 4) {
        milkPerDayPerCow = dailyMilk_;
    }
}

void Cow::produceMilk() {
    milkProduction_ = milkPerDayPerCow;
}