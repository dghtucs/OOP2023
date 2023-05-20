#include<iostream>

#define fast ios::sync_with_stdio(false);cin.tie(0);
#define fu(i,k,n) for(int i = k;i < n;i++)
#define fd(i,k,n) for(int i = k;i >= n;i--)
using namespace std;

int main()
{
    fast;
    fu(i,1,10)
    {
        cout << i << " ";
    }
    cout << '\n';
    fd(i,9,1){
        cout << i << " ";
    }
}