#include"Line.h"
#include"Point.h"
template<typename T>
bool Line<T>::intersect(const Line& l)
{
    if((l.k==k&&l.b==b)||l.k != k)
        return false;
    else
        return true;
}


template<typename T>
void Line<T>::show()
{
    std::cout << k << ',' << b << std::endl;
}
template<typename T>
bool Line<T>::operator<(Line& p)     
	{
		if(k < p.k)
            return true;
        else 
            return false;
}
template<typename T>
Line<T>::Line(T k_,T b_ = 0)
{k = k_;b = b_;}