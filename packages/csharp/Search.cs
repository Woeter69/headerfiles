namespace csharp_packages;
using System;

public static class Searching {
    public static int LinearSearch<T>(T[] arr, T target) where T : IEquatable<T> {
        for (int i = 0; i < arr.Length; i++) {
            if (arr[i].Equals(target)) return i;
        }
        return -1;
    }

    public static int BinarySearch<T>(T[] arr, T target) where T : IComparable<T> {
        int l = 0, r = arr.Length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int res = target.CompareTo(arr[m]);
            if (res == 0) return m;
            if (res > 0) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
}