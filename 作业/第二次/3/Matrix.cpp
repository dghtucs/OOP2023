#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix():elem(nullptr),col(0),row(0){}//默认构造函数这样塑造，全部置零
// {
//     col = 0;
//     row = 0;
// }
Matrix::Matrix(int _row, int _col)
{
    col = _col;
    row = _row;
    elem = new int *[row];
    for (int i = 0; i < row; i++)//初始化之后，还需要给elem进行置零操作
    {
        elem[i] = new int[col];
        for(int j = 0;j < col;j++)
            elem[i][j] = 0;
    }
}
Matrix::~Matrix() {//注意释放空间，在构造函数里面申请的内存要及时清理
    if(!this->elem)
    {
        for(int i = 0;i < row;i++)
        {
            delete []elem[i];//对于指针数组需要在delete时，前面加上[]
        }
        delete []elem;
    }
}

Matrix Matrix::operator+(const Matrix &a)
{//重载函数，不能返回*this，因为会改变原来的对象，导致后续的运算都会出现奇怪的错误
    Matrix m(row,col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m.elem[i][j] = this->elem[i][j] + a.elem[i][j];
        }
    }
    return m;
}
Matrix Matrix::operator-(const Matrix &a)
{
    Matrix m(row,col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m.elem[i][j] = this->elem[i][j] - a.elem[i][j];
        }
    }
    return m;
}
Matrix Matrix::operator*(const int a)
{
   Matrix m(row,col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m.elem[i][j] = this->elem[i][j] * a;
        }
    }
    return m;
}
Matrix Matrix::operator*(const Matrix &a)
{
    Matrix m(row, a.col);
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < a.col; j++)
        {
            int tem = 0;
            for (int k = 0; k < col; k++)
            {
                tem += this->elem[i][k] * a.elem[k][j];
            }
            m.elem[i][j] = tem;
        }
    }
    return m;
}
Matrix transpose(const Matrix &a)//善用构造函数
{
    int col = a.row;
    int row = a.col;
    
    Matrix m(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m[i][j] = a[j][i];
        }
    }

    return m;
}
int *Matrix::operator[](int a) const
{
    return this->elem[a];
}
ostream &operator<<(ostream &os, const Matrix &a)
{
    int col = a.col;
    int row = a.row;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            os << a.elem[i][j];
            if (j != col - 1)
                os << " ";
        }
        os << endl;
    }
    return os;
}
istream &operator>>(istream &is, Matrix &a)
{
    
    int col;
    int row;
    is >> row >> col;
    if(row!=a.row||col!=a.col)//需要判断这个矩阵是不是已经有行列数据，且是否和输入的行列一致
    {
        if(!a.elem)
        {
            for(int i = 0;i < a.row;i++)
                delete []a.elem[i];
            delete []a.elem;
        }
        a.row = row;
        a.col = col;//忘记了把a的行列更新！！！
        a.elem = new int*[row];
        for(int i = 0;i < row;i++)
            a.elem[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            is >> a.elem[i][j];
        }
    }
    return is;
}
