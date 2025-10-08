#include <cmath>
#include "cstats.h"


void sortArray(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double mean(const double data[], int n) {
    if (n <= 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double median(double data[], int n) {
    if (n <= 0) return 0.0;
    sortArray(data, n);

    if (n % 2 == 0)
        return (data[n/2 - 1] + data[n/2]) / 2.0;
    else
        return data[n/2];
}

double mode(const double data[], int n) {
    if (n <= 0) return 0.0;

    double modeVal = data[0];
    int maxCount = 1;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (data[j] == data[i])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            modeVal = data[i];
        }
    }
    return modeVal;
}

double range(const double data[], int n) {
    if (n <= 0) return 0.0;
    double minVal = data[0];
    double maxVal = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < minVal) minVal = data[i];
        if (data[i] > maxVal) maxVal = data[i];
    }
    return maxVal - minVal;
}

double min(const double data[], int n) {
    if (n <= 0) return 0.0;
    double minVal = data[0];
    for (int i = 1; i < n; i++)
        if (data[i] < minVal) minVal = data[i];
    return minVal;
}

double max(const double data[], int n) {
    if (n <= 0) return 0.0;
    double maxVal = data[0];
    for (int i = 1; i < n; i++)
        if (data[i] > maxVal) maxVal = data[i];
    return maxVal;
}

double sum(const double data[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++)
        total += data[i];
    return total;
}

int count(const double data[], int n) {
    if (n > 0)
        return n;
    else
        return 0;
}

double variance(const double data[], int n) {
    if (n <= 0) return 0.0;

    double m = mean(data, n);
    double var = 0.0;

    for (int i = 0; i < n; i++) {
        var += (data[i] - m) * (data[i] - m);
    }

    return var / n;
}

double stdev(const double data[], int n) {
    return sqrt(variance(data, n));
}
