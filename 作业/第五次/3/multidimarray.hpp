#ifndef MULTIDIMARRAY_HPP
#define MULTIDIMARRAY_HPP

#include <vector>
#include <stdexcept>

template <typename T, int DIM>
class MultiDimArray {
    std::vector<int> dimensions;
    std::vector<T> data;

    int get_index(const std::vector<int>& indices) const {
        if (indices.size() != DIM)
            throw std::invalid_argument("Invalid number of indices");
        
        int index = 0;
        int stride = 1;

        for (int i = 0; i < DIM; i++) {
            if (indices[i] >= dimensions[i] || indices[i] < 0)
                throw std::out_of_range("Index out of range");

            index += indices[i] * stride;
            stride *= dimensions[i];
        }

        return index;
    }

public:
    MultiDimArray(const std::vector<int>& dimensions): dimensions(dimensions) {
        int size = 1;
        for (auto dim : dimensions) {
            size *= dim;
        }
        data.resize(size);
    }

    MultiDimArray(const MultiDimArray<T, DIM>& other) = default;
    MultiDimArray(MultiDimArray<T, DIM>&& other) noexcept = default;
    MultiDimArray<T, DIM>& operator=(const MultiDimArray<T, DIM>& other) = default;
    MultiDimArray<T, DIM>& operator=(MultiDimArray<T, DIM>&& other) noexcept = default;

    T& operator[](const std::vector<int>& indices) {
        return data[get_index(indices)];
    }

    const T& operator[](const std::vector<int>& indices) const {
        return data[get_index(indices)];
    }
};

#endif
