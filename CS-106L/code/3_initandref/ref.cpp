//头文件
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> origin{1,2,3};
    vector<int> equal = origin;
    vector<int> &ref = origin;
    origin.push_back(9);
    for(auto i = equal.begin();i != equal.end();i++)
        cout << *i << " ";
    cout << endl;
    for(auto i = ref.begin();i != ref.end();i++)
        cout << *i << " ";
    
}


