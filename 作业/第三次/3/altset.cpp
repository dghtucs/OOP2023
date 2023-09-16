#include"altset.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
Altset& Altset::operator = (const Altset &altset)//复制构造函数
{
    if(this == &altset) return *this;
    data_.clear();
    data_ = altset.data_;
    len_ = altset.len_;
    numof1_ = altset.numof1_;
    return *this;
}


Altset& Altset::operator = (Altset &&altset)//移动构造函数需要使用move
{
    if(this == &altset) return *this;
    data_.clear();
    data_ = move(altset.data_);
    len_ = altset.len_;
    numof1_ = altset.numof1_;
    altset.data_.clear();
    altset.len_ = 0;
    altset.numof1_ = 0;
    return *this;
}

void Altset::inverse(int index)
{
    if(data_[index] == 1) {
        data_[index] = 0;
        numof1_ --;
    }
    else {
        data_[index] = 1;
        numof1_ ++;
    }
}

void Altset::append(int value)
{
    len_++;
    if(value==1)
    {
        data_.push_back(1);
        numof1_++;
    }
    else
        data_.push_back(0);
}

bool Altset::get(int index) const
{
    if(data_[index] == 1)
        return true;
    else
        return false;
}
bool Altset::empty() const
{
    return data_.empty();
}

int Altset::count() const
{
    return numof1_;
}







