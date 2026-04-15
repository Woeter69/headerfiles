#pragma once
#include <vector>

class Sorting {
public:
    static void bubbleSort(std::vector<int>& arr);
    static void selectionSort(std::vector<int>& arr);
    static void insertionSort(std::vector<int>& arr);
    static void heapSort(std::vector<int>& arr);
};
