//Farm.h
#ifndef FARM_H
#define FARM_H
#include<vector>
#include<string>
#include "Cow.h"
using namespace std;
class Farm {
    public:
        Farm(int n); 

        void addCow(Cow); 
        void startMeal(); 
        void supply(string name, int feed); 
        void produceMilk(); 

        float getMilkProduction() const {return totalProduction_;} 
        
    private:
        vector<Cow>cowsArray; 
        vector<int>supplyArray; 
        float totalProduction_; 
};

#endif