//头文件
#include<iostream>
#include<vector>
using namespace std;

void incre(vector<pair<int,int>> nums)
{
    for(int i = 0;i < nums.size();i++)
    {
        auto& [a,b] = nums[i];
        a++;b++;
    }    
        
}

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
    cout << '\n';
    vector<pair<int,int>> n = {{1,2},{3,4},{5,6}};
    incre(n);
    cout << n[0].first << " " << n[0].second;
}

 
