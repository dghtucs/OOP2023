//头文件
#include<iostream>
#include<vector>
#include"Person.h"
using namespace std;
int Person::count = 0;
int main()
{
    Person* p = new Person[15];
    cout << Person::getCount << endl;
}