#ifndef MYQUERIABLE_H
#define MYQUERIABLE_H

#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

template<typename T>
class MyQueriable {
private:
    std::vector<T> data;

public:
    MyQueriable(std::vector<T> const &vec): data(vec) {}

    size_t size() const {
        return data.size();
    }

    T operator[](size_t i) const {
        return data[i];
    }

    MyQueriable<T> where(std::function<bool(T)> func) const {
        std::vector<T> result;
        for (const auto &val : data) {
            if (func(val)) {
                result.push_back(val);
            }
        }
        return MyQueriable<T>(result);
    }

    MyQueriable<T> apply(std::function<T(T)> func) const {
        std::vector<T> result(data.size());
        std::transform(data.begin(), data.end(), result.begin(), func);
        return MyQueriable<T>(result);
    }

    T sum() const {
        return std::accumulate(data.begin(), data.end(), static_cast<T>(0));
    }
};

template<typename T>
MyQueriable<T> from(const std::vector<T> &vec) {
    return MyQueriable<T>(vec);
}

#endif
