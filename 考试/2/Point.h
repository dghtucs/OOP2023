#pragma once
template<typename T>
class Point
{
private:
    /* data */
    
public:
 
    T x,y;
    Point(T a,T b);
    ~Point();
    void move(T dx, T dy);
    void show();
    bool check(Line<T> const& l);
};


