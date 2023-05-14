#include<iostream>
#include<vector>
using namespace std;
int main()
{
    auto p = std::make_pair(5,"dgh");
    auto [a,b] = p;
    cout << a << " " << b;
}