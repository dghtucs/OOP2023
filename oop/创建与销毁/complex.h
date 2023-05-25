#pragma once
#include<cmath>
#include<iostream>

class Complex
{
private:
    /* data */
    double real,image;
    double *data;
public:
    Complex():real(0),image(0){};
    Complex(double a,double b);
    Complex(const Complex& c);
    ~Complex();
    Complex operator+(const Complex& c);
    Complex& operator=(const Complex& other);
    friend std::ostream& operator<<(std::ostream& out,const Complex& c);
};






















