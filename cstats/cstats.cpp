#include <cmath>
#include <iostream>
#include "cstats.h"

using namespace std;

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

double percentile(double data[], int n, double p) {
    if (n <= 0 || p < 0 || p > 100) return 0.0;
    sortArray(data, n);
    
    double index = (p / 100.0) * (n - 1);
    int lower = (int)index;
    int upper = lower + 1;
    
    if (upper >= n) return data[n - 1];
    
    double weight = index - lower;
    return data[lower] * (1 - weight) + data[upper] * weight;
}

double quartile1(double data[], int n) {
    return percentile(data, n, 25.0);
}

double quartile3(double data[], int n) {
    return percentile(data, n, 75.0);
}

double iqr(double data[], int n) {
    if (n <= 0) return 0.0;
    return quartile3(data, n) - quartile1(data, n);
}

double sampleVariance(const double data[], int n) {
    if (n <= 1) return 0.0;
    
    double m = mean(data, n);
    double var = 0.0;
    
    for (int i = 0; i < n; i++) {
        var += (data[i] - m) * (data[i] - m);
    }
    
    return var / (n - 1);
}

double sampleStdev(const double data[], int n) {
    return sqrt(sampleVariance(data, n));
}

double meanAbsoluteDeviation(const double data[], int n) {
    if (n <= 0) return 0.0;
    
    double m = mean(data, n);
    double mad = 0.0;
    
    for (int i = 0; i < n; i++) {
        mad += fabs(data[i] - m);
    }
    
    return mad / n;
}

double coefficientOfVariation(const double data[], int n) {
    if (n <= 0) return 0.0;
    
    double m = mean(data, n);
    if (m == 0.0) return 0.0;
    
    return (stdev(data, n) / m) * 100.0;
}

double skewness(const double data[], int n) {
    if (n <= 2) return 0.0;
    
    double m = mean(data, n);
    double sd = stdev(data, n);
    if (sd == 0.0) return 0.0;
    
    double skew = 0.0;
    for (int i = 0; i < n; i++) {
        double z = (data[i] - m) / sd;
        skew += z * z * z;
    }
    
    return skew / n;
}

double kurtosis(const double data[], int n) {
    if (n <= 3) return 0.0;
    
    double m = mean(data, n);
    double sd = stdev(data, n);
    if (sd == 0.0) return 0.0;
    
    double kurt = 0.0;
    for (int i = 0; i < n; i++) {
        double z = (data[i] - m) / sd;
        kurt += z * z * z * z;
    }
    
    return (kurt / n) - 3.0;
}

double zScore(double value, double mean, double stdev) {
    if (stdev == 0.0) return 0.0;
    return (value - mean) / stdev;
}

double covariance(const double x[], const double y[], int n) {
    if (n <= 0) return 0.0;
    
    double meanX = mean(x, n);
    double meanY = mean(y, n);
    
    double cov = 0.0;
    for (int i = 0; i < n; i++) {
        cov += (x[i] - meanX) * (y[i] - meanY);
    }
    
    return cov / n;
}

double correlation(const double x[], const double y[], int n) {
    if (n <= 0) return 0.0;
    
    double cov = covariance(x, y, n);
    double sdX = stdev(x, n);
    double sdY = stdev(y, n);
    
    if (sdX == 0.0 || sdY == 0.0) return 0.0;
    
    return cov / (sdX * sdY);
}

double geometricMean(const double data[], int n) {
    if (n <= 0) return 0.0;
    
    double product = 1.0;
    for (int i = 0; i < n; i++) {
        if (data[i] <= 0) return 0.0;
        product *= data[i];
    }
    
    return pow(product, 1.0 / n);
}

double harmonicMean(const double data[], int n) {
    if (n <= 0) return 0.0;
    
    double sumReciprocals = 0.0;
    for (int i = 0; i < n; i++) {
        if (data[i] == 0.0) return 0.0;
        sumReciprocals += 1.0 / data[i];
    }
    
    return n / sumReciprocals;
}

double rootMeanSquare(const double data[], int n) {
    if (n <= 0) return 0.0;
    
    double sumSquares = 0.0;
    for (int i = 0; i < n; i++) {
        sumSquares += data[i] * data[i];
    }
    
    return sqrt(sumSquares / n);
}

void copyArray(const double src[], double dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

double standardError(const double data[], int n) {
    if (n <= 1) return 0.0;
    return sampleStdev(data, n) / sqrt(n);
}

double confidenceInterval95Lower(const double data[], int n) {
    if (n <= 1) return 0.0;
    double m = mean(data, n);
    double se = standardError(data, n);
    return m - 1.96 * se;
}

double confidenceInterval95Upper(const double data[], int n) {
    if (n <= 1) return 0.0;
    double m = mean(data, n);
    double se = standardError(data, n);
    return m + 1.96 * se;
}

double trimmedMean(double data[], int n, double trimPercent) {
    if (n <= 0 || trimPercent < 0 || trimPercent >= 50) return 0.0;
    
    sortArray(data, n);
    
    int trimCount = (int)(n * trimPercent / 100.0);
    int newN = n - 2 * trimCount;
    
    if (newN <= 0) return mean(data, n);
    
    double sum = 0.0;
    for (int i = trimCount; i < n - trimCount; i++) {
        sum += data[i];
    }
    
    return sum / newN;
}

double weightedMean(const double data[], const double weights[], int n) {
    if (n <= 0) return 0.0;
    
    double weightedSum = 0.0;
    double totalWeight = 0.0;
    
    for (int i = 0; i < n; i++) {
        weightedSum += data[i] * weights[i];
        totalWeight += weights[i];
    }
    
    if (totalWeight == 0.0) return 0.0;
    return weightedSum / totalWeight;
}

double linearRegressionSlope(const double x[], const double y[], int n) {
    if (n <= 1) return 0.0;
    
    double meanX = mean(x, n);
    double meanY = mean(y, n);
    
    double numerator = 0.0;
    double denominator = 0.0;
    
    for (int i = 0; i < n; i++) {
        numerator += (x[i] - meanX) * (y[i] - meanY);
        denominator += (x[i] - meanX) * (x[i] - meanX);
    }
    
    if (denominator == 0.0) return 0.0;
    return numerator / denominator;
}

double linearRegressionIntercept(const double x[], const double y[], int n) {
    if (n <= 1) return 0.0;
    
    double slope = linearRegressionSlope(x, y, n);
    double meanX = mean(x, n);
    double meanY = mean(y, n);
    
    return meanY - slope * meanX;
}

double rSquared(const double x[], const double y[], int n) {
    if (n <= 1) return 0.0;
    
    double slope = linearRegressionSlope(x, y, n);
    double intercept = linearRegressionIntercept(x, y, n);
    double meanY = mean(y, n);
    
    double ssRes = 0.0;
    double ssTot = 0.0;
    
    for (int i = 0; i < n; i++) {
        double predicted = slope * x[i] + intercept;
        ssRes += (y[i] - predicted) * (y[i] - predicted);
        ssTot += (y[i] - meanY) * (y[i] - meanY);
    }
    
    if (ssTot == 0.0) return 0.0;
    return 1.0 - (ssRes / ssTot);
}

void cumulativeSum(const double data[], double result[], int n) {
    if (n <= 0) return;
    
    result[0] = data[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] + data[i];
    }
}

void printSummaryStats(double data[], int n) {
    if (n <= 0) {
        cout << "No data available\n";
        return;
    }
    
    cout << "=== Summary Statistics ===\n";
    cout << "Count:    " << n << "\n";
    cout << "Mean:     " << mean(data, n) << "\n";
    cout << "Median:   " << median(data, n) << "\n";
    cout << "Std Dev:  " << stdev(data, n) << "\n";
    cout << "Min:      " << min(data, n) << "\n";
    cout << "Max:      " << max(data, n) << "\n";
    cout << "Range:    " << range(data, n) << "\n";
    cout << "Q1:       " << quartile1(data, n) << "\n";
    cout << "Q3:       " << quartile3(data, n) << "\n";
}
