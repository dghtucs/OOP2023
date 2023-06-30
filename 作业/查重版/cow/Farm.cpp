//farm.cpp
#include<iostream>
#include<string>
#include "Farm.h"

//Farm.cpp
Farm::Farm(int n) : totalProduction_(0) {
        cowsArray.reserve(n);
        supplyArray.reserve(n);
}
void Farm::addCow(Cow cow) {
    cowsArray.push_back(cow);
    supplyArray.push_back(0);
}

void Farm::supply(string Cowname,int feed) { 
    for (Cow& cow : cowsArray) {
        if (cow.getCowName() == Cowname) { 
            supplyArray[&cow - &cowsArray[0]] += feed; 
            break;
        }
    }
}

void Farm::startMeal() {
    for (Cow& cow : cowsArray) {
        int index = &cow - &cowsArray[0];
        if(supplyArray[index] < cow.getLow() && supplyArray[index] > 0) {
            cow.eat(1);
            supplyArray[index] = 0;
        }
        else if(supplyArray[index] == 0) {
            cow.eat(2);
        }
        else if(supplyArray[index] >= cow.getLow() && supplyArray[index] < cow.getUpper()) {
            cow.eat(3);
            supplyArray[index] = 0;
        }
        else {
            cow.eat(4);
            supplyArray[index] -= cow.getUpper();
        }
    }
}

void Farm::produceMilk() { 
    float dailyProduction = 0; 
    for(Cow& cow : cowsArray) {
        cow.produceMilk(); 
        dailyProduction += cow.getMilkProduction();
    }
    totalProduction_ += dailyProduction; 
}