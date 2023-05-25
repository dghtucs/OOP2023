
#include<iostream>
#include"complex.h"


Complex::Complex(double a,double b)
{
    real = a;image = b;
    data = new double[3];
    data[0] = sqrt(real*real+image*image);
    data[1] = atan(image/real);
    data[2] = asin(image/data[0]);
}
Complex::Complex(const Complex& c)
{
    real = c.real;
    image = c.image;
    data = new double[3];
    data[0] = c.data[0];
    data[1] = c.data[1];
    data[2] = c.data[2];
}

Complex::~Complex()
{
    delete []data;
}

Complex Complex::operator+(const Complex& c)
{
    Complex tem(real+c.real,image+c.image);
    
    tem.data[0] = sqrt(tem.real*tem.real+tem.image*tem.image);
    tem.data[1] = atan(tem.image/tem.real);
    tem.data[2] = asin(tem.image/tem.data[0]);
    return tem;
}
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        delete [] data;  // 删除旧数据
        real = other.real;
        image = other.image;
        data = new double[3];
        data[0] = other.data[0];
        data[1] = other.data[1];
        data[2] = other.data[2];
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out,const Complex& c)
{
    out << c.real << " + " << c.image << "i" << std::endl;
    out << "r = " << c.data[0] << std::endl;
    out << "arctan = " << c.data[1] << " arcsin = " << c.data[2];
    return out;
}














