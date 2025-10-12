#ifndef TEST_ARRAYS_H
#define TEST_ARRAYS_H

#include <vector>

namespace test_data {

    inline std::vector<int> sorted_array = {1, 2, 3, 4, 5, 6};
    inline std::vector<int> reversed_array = {9, 7, 5, 3, 1};
    inline std::vector<int> random_array = {5, 2, 9, 1, 5, 6};
    inline std::vector<int> negative_array = {-3, -1, -7, -4};
    inline std::vector<int> empty_array = {};
    inline std::vector<int> single_element_array = {42};

    // You can template these for flexibility
    template<typename T>
    std::vector<T> copy(const std::vector<T>& vec) {
        return std::vector<T>(vec.begin(), vec.end());
    }
}

#endif
