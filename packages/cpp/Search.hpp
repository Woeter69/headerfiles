#pragma once
#include <vector>

class Search {
public:
    static int linearSearch(const std::vector<int>& arr, int target);
    static int binarySearch(const std::vector<int>& arr, int target);
};
