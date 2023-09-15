#include "Matrix.h"
#include<iostream>
using namespace std;

Matrix::Matrix(){}
Matrix::Matrix(int _row, int _col){}
Matrix::~Matrix(){}

Matrix Matrix::operator+(const Matrix &){}
Matrix Matrix::operator-(const Matrix &){}
Matrix Matrix::operator*(const int){}
Matrix Matrix::operator*(const Matrix &){}
Matrix transpose(const Matrix &){}
int *Matrix::operator[](int) const{}
ostream &operator<<(ostream &, const Matrix &){}
istream &operator>>(istream &, Matrix &){}
