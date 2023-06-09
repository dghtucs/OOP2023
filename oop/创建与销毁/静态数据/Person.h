#pragma once

class Person
{
private:
    /* data */
    int age_;
    double height_;
    
public:
    static int count;
    Person():age_(0),height_(30){}
    Person(int age,double height);
    ~Person();
    static int getCount();
};

Person::Person(int age,double height)
{
    age_ = age;
    height_ = height;
    count++;
}

Person::~Person()
{
    count--;
}













