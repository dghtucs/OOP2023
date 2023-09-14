#include <iostream>
#include "chef.h"
#include "manager.h"
using namespace std;
void Manager::newChef(Chef c)
{
    chefs_.push_back(c);
}

void Manager::order(string dish)
{

    bool found = false;
    for (auto i = 0u; i < chefs_.size(); i++)
    {
        if (chefs_[i].isSignatureDish(dish))
        {
            chefs_[i].cook(dish);
            cout << " made an awesome " << dish << endl;
                found = true;
                break;
        }

    }
    if(!found)
    {
        chefs_[0].cook(dish);
            cout << " made a plain " << dish << endl;
    }
}
void Manager::order(string dish, int chefId)
{
    if (chefs_[chefId].isSignatureDish(dish))
    {
        chefs_[chefId].cook(dish);
        cout << " made an awesome " << dish << endl;
    }
    else
    {
        chefs_[chefId].cook(dish);
        cout << " made a plain " << dish << endl;
    }
}
Manager::Manager(/* args */)
{
}

Manager::~Manager()
{
}