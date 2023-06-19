#pragma once

template<typename T>
class Line
{
private:
    /* data */
    
public:
    T k,b;
    Line(T k_,T b_ = 0);
    ~Line();
    bool intersect(const Line&);
    void show();
    bool operator<(Line& p);
};


