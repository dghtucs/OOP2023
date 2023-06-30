//Cow.h
#ifndef COW_H
#define COW_H
#include<string>
#include"Cow.h"
using namespace std;
class Cow {
    public:
        Cow(string name, int lowFeed, int upperFeed, double dailyMilk); 
        void produceMilk(); 
        void eat(int feedCase); 
        
        double getMilkProduction() const { return milkProduction_; } 
        string getCowName() const { return name_; } 
        int getLow() const{ return lowFeed_; } 
        int getUpper() const{ return upperFeed_; }
        double getDailyMilk() const{ return dailyMilk_; }
    private:
        string name_; 
        int lowFeed_; 
        int upperFeed_; 
        double dailyMilk_; 
        double milkProduction_; 
        int currentTotal_; 
        double milkPerDayPerCow;
};

#endif