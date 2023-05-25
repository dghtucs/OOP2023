//头文件
#include<iostream>
#include<vector>
using namespace std;

inline auto add(int a,int b)
{
    auto d = a/b;
    cout << d;
}

int main()
{
    add(99,2);
}