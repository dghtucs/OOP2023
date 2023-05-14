#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v(3,5);
    vector<int> v1{3,5};
    for(auto i = v.begin();i != v.end();i++)
        cout << *i << " ";
    cout << endl;
    for(auto i = v1.begin();i!=v1.end();i++)
        cout << *i << " ";
}