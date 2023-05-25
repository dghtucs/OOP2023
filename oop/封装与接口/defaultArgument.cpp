//头文件
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printMessage(const string& a,int c=1)
{
    for(int i = 1;i <= c;i++)
        cout << a << endl;
}


int main()
{
    string s = "dghtql";
    printMessage(s);
    printMessage(s,2);
    
    
}