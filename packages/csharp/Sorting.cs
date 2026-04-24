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
}