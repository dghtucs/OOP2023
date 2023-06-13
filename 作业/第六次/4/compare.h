//compare.h
#include <functional>
#include <initializer_list>
#include <vector>

template<typename T>
class Compare
{
private:
    std::vector<std::function<bool(T, T)>> funs;

public:
    Compare(std::initializer_list<std::function<bool(T, T)>> list) 
        : funs(list) 
    {}

    bool operator()(T l, T r) 
    {
        for(auto &fun : funs) 
        {
            if(fun(l, r)) return true;
            if(fun(r, l)) return false;
        }
        return false;
    }
};
