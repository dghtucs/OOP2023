#include <unordered_map>
#include <utility>
#include <iostream>
#include"HitStatsResult.hpp"


template<class Key, class Value>
class MyDict {
private:
    std::unordered_map<Key, Value> dict;
    int hit_count = 0, miss_count = 0;

public:
    Value& operator[](const Key& key) {
        if (dict.find(key) != dict.end()) {
            hit_count++;
            return dict[key];
        }
        else {
            miss_count++;
            return dict[key] = Value();
        }
    }

    HitStatsResult hitStats() const {
        return HitStatsResult(hit_count, miss_count);
    }

    int size() const {
        return dict.size();
    }

    void clear() {
        dict.clear();
        hit_count = 0;
        miss_count = 0;
    }
};
