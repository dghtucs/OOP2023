#include<iostream>
#include<cstring>
using namespace std;

class Person
{
    public:
        int age;
        int id;
        string name;
        int getId(){return this->id;}
        string getName(){return this->name;}
        int getAge();
};

int Person::getAge()
{
    return this->age;
}

int main()
{
    Person p1,p2,p3;
    p1.age = 5;
    p1.id = 9;
    p1.name = "tql";
    cout << p1.getAge() << " " << p1.getId() << " " << p1.getName();
}