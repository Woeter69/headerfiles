#include "Search.hpp"

int Search::linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int Search::binarySearch(const std::vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == target) {
            return m;
        }
        if (arr[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}
