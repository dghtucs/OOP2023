#pragma once
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Altset {
    vector<int> data_;
    int len_;
    int numof1_;
public:
    Altset(){
        data_.clear();
        len_ = 0;
        numof1_ = 0;
    }
    ~Altset()
    {
        data_.clear();
    }

    Altset(const char *data, int len):len_(len){
        for(int i = 0;i < len;i++)
        {
            data_.push_back(data[i]-'0');
            if(data_[i]==1)
                numof1_++;
        }
        reverse(data_.begin(),data_.end());
    }
	Altset& operator = (const Altset &altset);
    Altset& operator = (Altset &&altset);

    void inverse(int index);
    void append(int value);
    bool get(int index) const;
    bool empty() const;
    int count() const;
};
