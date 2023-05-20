#include<iostream>
#include<cstring>
using namespace std;

class Person
{
    
    private:
        int id;
    protected:
        string name;
    public:
        int age;
        int setId(int i){this->id = i;}
        void setName(string s){this->name = s;}
        int getId(){return this->id;}
        string getName(){return this->name;}
        int getAge();
};
class Hr : public Person
{
    public:
        void printName()
        {
            cout << this->name << endl;
        }
        //void printId(){cout << this->id << endl;}
};
int Person::getAge()
{
    return this->age;
}

int main()
{
    Person p1;
    p1.age = 5;
    //p1.id = 9;
    p1.setId(9);
    //p1.name = "tql";
    p1.setName("tql");
    cout << p1.getAge() << " " << p1.getId() << " " << p1.getName()<<endl;;
    Hr h;h.age = 1;
    h.setId(2);h.setName("ddd");
    h.printName();//h.printId();
}