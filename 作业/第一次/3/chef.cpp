#include"chef.h"
#include"manager.h"
#include<iostream>
using namespace std;
Chef::Chef(std::string _name, std::string _signatureDish)
{
    this->name = _name;
    this->signatureDish = _signatureDish;
}
bool Chef::isSignatureDish(std::string dish)
{
    if(dish == this->signatureDish)
        return true;
    else
        return false;
}
void Chef::cook(std::string dish)
{
    cout << name;
}