#pragma once
#include"chef.h"
#include<vector>
#include<string>
using namespace std;

class Manager
{
private:

    vector<Chef> chefs_;
public:
    Manager(/* args */);
    ~Manager();
    void newChef(Chef c);
    void order(string dish);
    void order(string dish,int chefid);
};

