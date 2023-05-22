//头文件
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
class Less
{
    public:
    bool operator()(const T& a,const T& b){return a < b;}
};

int main()
{
    auto lesser = Less<int>();
    int a[] = {3,1,5,2,1};
    sort(a,a+5,lesser);
    for(int x:a)cout << x << " ";
}