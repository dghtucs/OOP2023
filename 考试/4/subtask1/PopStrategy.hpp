#pragma once
#include<vector>

template<typename T>
class PopStrategy
{
private:
    /* data */
public:
    vector<T> v;
    PopStrategy(/* args */);
    ~PopStrategy();
    virtual void visit(T s);
    virtual T pop();
};


template<typename T>
class FIFOStrategy:public PopStrategy
{
    public:
    vector<T> v;
    static int i =0;
    void visit(T s)
    {
        v.push_back(s);
    }
    T pop()
    {
        return v[i++];
    }

};
template<typename T>
class LRUStrategy:public PopStrategy
{
    public:
    vector<T> v;
    
    void visit(T s)
    {
        v.push_back(s);
    }
    T pop()
    {
        return v[i++];
    }
};