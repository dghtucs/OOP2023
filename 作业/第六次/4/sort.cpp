//sort.cpp
#include <iostream>
#include <list>
#include <vector>
#include "compare.h"
#include "sortlevel.h"
using namespace std;

Compare<vector<int>> make_comp(list<sort_level> sortlevels)
{
    // Note the change here, using initializer_list to create Compare object.
    return Compare<vector<int>>({
        [&sortlevels](vector<int> l, vector<int> r) {
            for(auto &level : sortlevels)
            {
                int column = level.column-1;
                if(level.order == ASCEND)
                {
                    if(l[column] < r[column]) return true;
                    if(l[column] > r[column]) return false;
                }
                else
                {
                    if(l[column] > r[column]) return true;
                    if(l[column] < r[column]) return false;
                }
            }
            return false;
        }
    });
}
