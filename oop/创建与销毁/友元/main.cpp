//头文件
#include<iostream>
#include<vector>
using namespace std;
class person
{
private:
    /* data */
    int age;
public:
    person(int a):age(a){}
    ~person();
    friend void getAge(person& p);
};


person::~person()
{
}

void getAge(person& p)
{
    cout << p.age << endl;
}

int main()
{
    auto p = new person(12);
    getAge(*p);
}