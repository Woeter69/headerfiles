namespace csharp_packages;
using System;

public static class Sorting {
    public static void BubbleSort<T>(T[] arr) where T : IComparable<T> {
        for (int i = 0; i < arr.Length - 1; i++) {
            for (int j = 0; j < arr.Length - i - 1; j++) {
                if (arr[j].CompareTo(arr[j + 1]) > 0) {
                    (arr[j], arr[j + 1]) = (arr[j + 1], arr[j]);
                }
            }
        }
    }

    public static void SelectionSort<T>(T[] arr) where T : IComparable<T> {
        for (int i = 0; i < arr.Length - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < arr.Length; j++) {
                if (arr[j].CompareTo(arr[minIdx]) < 0) minIdx = j;
            }
            (arr[i], arr[minIdx]) = (arr[minIdx], arr[i]);
        }
    }

    public static void InsertionSort<T>(T[] arr) where T : IComparable<T> {
        for (int i = 1; i < arr.Length; i++) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j].CompareTo(key) > 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    public static void HeapSort<T>(T[] arr) where T : IComparable<T> {
        var heap = new MinHeap<T>();
        foreach (var item in arr) heap.Insert(item);
        for (int i = 0; i < arr.Length; i++) arr[i] = heap.ExtractMin();
    }

    public static void QuickSort<T>(T[] arr) where T : IComparable<T> {
        QuickSortRec(arr, 0, arr.Length - 1);
    }
    
    private static void QuickSortRec<T>(T[] arr, int low, int high) where T : IComparable<T> {
        if (low < high) {
            int pi = Partition(arr, low, high);
            QuickSortRec(arr, low, pi - 1);
            QuickSortRec(arr, pi + 1, high);
        }
    }
    
    private static int Partition<T>(T[] arr, int low, int high) where T : IComparable<T> {
        T pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j].CompareTo(pivot) < 0) {
                i++;
                (arr[i], arr[j]) = (arr[j], arr[i]);
            }
        }
        (arr[i + 1], arr[high]) = (arr[high], arr[i + 1]);
        return i + 1;
    }

    public static void MergeSort<T>(T[] arr) where T : IComparable<T> {
        if (arr.Length <= 1) return;
        T[] temp = new T[arr.Length];
        MergeSortRec(arr, temp, 0, arr.Length - 1);
    }
    
    private static void MergeSortRec<T>(T[] arr, T[] temp, int left, int right) where T : IComparable<T> {
        if (left < right) {
            int mid = left + (right - left) / 2;
            MergeSortRec(arr, temp, left, mid);
            MergeSortRec(arr, temp, mid + 1, right);
            Merge(arr, temp, left, mid, right);
        }
    }
    
    private static void Merge<T>(T[] arr, T[] temp, int left, int mid, int right) where T : IComparable<T> {
        for (int i = left; i <= right; i++) temp[i] = arr[i];
        
        int iLeft = left;
        int iRight = mid + 1;
        int curr = left;
        
        while (iLeft <= mid && iRight <= right) {
            if (temp[iLeft].CompareTo(temp[iRight]) <= 0) {
                arr[curr++] = temp[iLeft++];
            } else {
                arr[curr++] = temp[iRight++];
            }
        }
        
        int remaining = mid - iLeft;
        for (int i = 0; i <= remaining; i++) {
            arr[curr + i] = temp[iLeft + i];
        }
    }
}