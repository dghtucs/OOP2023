#include <iostream>
using namespace std;

class Base
{
private:
    

public:

int k = 0;
Base() = default;
    Base(int num);
    void f()
    {
        cout << "f() is voked" << endl;
    }
    Base &operator= (const Base &right)
    {
        if (this != &right)
        {
            k = right.k;
            cout << "operator= is called" << endl;
        }
        return *this;
    }
    ~Base();
};

Base::Base(int num) : k(num)
{
}

class Derive : public Base
{
};

int main()
{
    Derive d1(9),d2;//构造函数不能继承
    cout << d1.k << endl;//公有数据可以继承
    d2.f();//函数可以继承
    Base e;
    d1 = e;//赋值运算符不能继承
}
