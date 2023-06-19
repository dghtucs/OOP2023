#include"Point.h"
#include"Line.h"
#include<math.h>
template<typename T>
Point<T>::Point(T a,T b):x(a),y(b){}

template<typename T>
void Point<T>::move(T dx, T dy)
{
    x+=dx;
    y+=dy;
}
template<typename T>
void Point<T>::show()
{
    std::cout << '(' << x << ',' << y << ')' << std::endl;
}
template<typename T>
bool Point<T>::check(Line<T> const& l){
    if(abs(l.k*x+l.b-y) <= 1e-6)
        return true;
    else 
        return false;
}