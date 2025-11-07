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

// Finds the middle value (or average of two middle values for even n)
double median(double data[], int n) {
    if (n <= 0) return 0.0;
    sortArray(data, n);

    if (n % 2 == 0)
        return (data[n/2 - 1] + data[n/2]) / 2.0;
    else
        return data[n/2];
}

// Finds the most frequently occurring value using nested loops
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

// Calculates the difference between maximum and minimum values
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

// Finds the smallest value in the dataset
double min(const double data[], int n) {
    if (n <= 0) return 0.0;
    double minVal = data[0];
    for (int i = 1; i < n; i++)
        if (data[i] < minVal) minVal = data[i];
    return minVal;
}

// Finds the largest value in the dataset
double max(const double data[], int n) {
    if (n <= 0) return 0.0;
    double maxVal = data[0];
    for (int i = 1; i < n; i++)
        if (data[i] > maxVal) maxVal = data[i];
    return maxVal;
}

// Calculates the sum of all values
double sum(const double data[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++)
        total += data[i];
    return total;
}

// Returns the count of elements (simple validation wrapper)
int count(const double data[], int n) {
    if (n > 0)
        return n;
    else
        return 0;
}

// Calculates population variance: average of squared deviations from mean
double variance(const double data[], int n) {
    if (n <= 0) return 0.0;
    double m = mean(data, n);
    double var = 0.0;
    for (int i = 0; i < n; i++) {
        var += (data[i] - m) * (data[i] - m);
    }
    return var / n;
}

// Calculates population standard deviation: square root of variance
double stdev(const double data[], int n) {
    return sqrt(variance(data, n));
}

// Calculates a specified percentile
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

// Calculates first quartile (25th percentile)
double quartile1(double data[], int n) {
    return percentile(data, n, 25.0);
}

// Calculates third quartile (75th percentile)
double quartile3(double data[], int n) {
    return percentile(data, n, 75.0);
}

// Calculates interquartile range: Q3 - Q1 (middle 50% spread)
double iqr(double data[], int n) {
    if (n <= 0) return 0.0;
    return quartile3(data, n) - quartile1(data, n);
}

// Sample statistics (n-1 denominator)

// Calculates sample variance using Bessel's correction (n-1)
double sampleVariance(const double data[], int n) {
    if (n <= 1) return 0.0;
    double m = mean(data, n);
    double var = 0.0;
    for (int i = 0; i < n; i++) {
        var += (data[i] - m) * (data[i] - m);
    }
    return var / (n - 1);
}

// Calculates sample standard deviation: square root of sample variance
double sampleStdev(const double data[], int n) {
    return sqrt(sampleVariance(data, n));
}

// Calculates average of absolute deviations from the mean
double meanAbsoluteDeviation(const double data[], int n) {
    if (n <= 0) return 0.0;
    double m = mean(data, n);
    double mad = 0.0;
    for (int i = 0; i < n; i++) {
        mad += fabs(data[i] - m);
    }
    return mad / n;
}

// Calculates median of absolute deviations from median (robust measure)
double medianAbsoluteDeviation(double data[], int n) {
    if (n <= 0) return 0.0;
    double* tempData = new double[n];
    copyArray(data, tempData, n);
    double med = median(tempData, n);
    double* deviations = new double[n];
    for (int i = 0; i < n; i++) {
        deviations[i] = fabs(data[i] - med);
    }
    double result = median(deviations, n);
    delete[] tempData;
    delete[] deviations;
    return result;
}

// Calculates relative variability: (stdev / mean) × 100%
double coefficientOfVariation(const double data[], int n) {
    if (n <= 0) return 0.0;
    double m = mean(data, n);
    if (m == 0.0) return 0.0;
    return (stdev(data, n) / m) * 100.0;
}

// Measures asymmetry: negative = left-skewed, positive = right-skewed
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

// Measures tailedness: excess kurtosis (normal distribution = 0)
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

// Standardizes a value: (value - mean) / stdev
double zScore(double value, double mean, double stdev) {
    if (stdev == 0.0) return 0.0;
    return (value - mean) / stdev;
}

// Measures how two variables change together
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

// Calculates Pearson correlation coefficient: normalized covariance (-1 to 1)
double correlation(const double x[], const double y[], int n) {
    if (n <= 0) return 0.0;
    double cov = covariance(x, y, n);
    double sdX = stdev(x, n);
    double sdY = stdev(y, n);
    if (sdX == 0.0 || sdY == 0.0) return 0.0;
    return cov / (sdX * sdY);
}

// Calculates nth root of product (useful for growth rates)
double geometricMean(const double data[], int n) {
    if (n <= 0) return 0.0;
    double product = 1.0;
    for (int i = 0; i < n; i++) {
        if (data[i] <= 0) return 0.0;
        product *= data[i];
    }
    return pow(product, 1.0 / n);
}

// Calculates reciprocal of mean of reciprocals (useful for rates)
double harmonicMean(const double data[], int n) {
    if (n <= 0) return 0.0;
    double sumReciprocals = 0.0;
    for (int i = 0; i < n; i++) {
        if (data[i] == 0.0) return 0.0;
        sumReciprocals += 1.0 / data[i];
    }
    return n / sumReciprocals;
}

// Calculates quadratic mean: sqrt of mean of squares
double rootMeanSquare(const double data[], int n) {
    if (n <= 0) return 0.0;
    double sumSquares = 0.0;
    for (int i = 0; i < n; i++) {
        sumSquares += data[i] * data[i];
    }
    return sqrt(sumSquares / n);
}

// ============================================================================
// VECTOR OPERATIONS
// ============================================================================

// Calculates dot product: sum of v1[i] * v2[i]
double dotProduct(const double v1[], const double v2[], int n) {
    if (n <= 0) return 0.0;
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Calculates Euclidean norm (L2 norm): sqrt(sum of squares)
double vectorMagnitude(const double v[], int n) {
    if (n <= 0) return 0.0;
    double sumSquares = 0.0;
    for (int i = 0; i < n; i++) {
        sumSquares += v[i] * v[i];
    }
    return sqrt(sumSquares);
}

// Calculates Euclidean distance between two points in n-dimensional space
double vectorDistance(const double v1[], const double v2[], int n) {
    if (n <= 0) return 0.0;
    double sumSquares = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = v1[i] - v2[i];
        sumSquares += diff * diff;
    }
    return sqrt(sumSquares);
}

// Calculates angle between vectors using: θ = arccos(v1·v2 / (|v1||v2|))
double vectorAngle(const double v1[], const double v2[], int n) {
    if (n <= 0) return 0.0;
    double mag1 = vectorMagnitude(v1, n);
    double mag2 = vectorMagnitude(v2, n);
    if (mag1 == 0.0 || mag2 == 0.0) return 0.0;
    double dot = dotProduct(v1, v2, n);
    double cosAngle = dot / (mag1 * mag2);
    if (cosAngle > 1.0) cosAngle = 1.0;
    if (cosAngle < -1.0) cosAngle = -1.0;
    return acos(cosAngle);
}

// Normalizes vector to unit length: result = v / |v|
bool normalizeVector(const double v[], double result[], int n) {
    if (n <= 0) return false;
    double mag = vectorMagnitude(v, n);
    if (mag == 0.0) return false;  // Cannot normalize zero vector
    for (int i = 0; i < n; i++) {
        result[i] = v[i] / mag;
    }
    return true;
}

// Calculates cross product for 3D vectors only: v1 × v2
// Result is perpendicular to both input vectors
void crossProduct3D(const double v1[], const double v2[], double result[]) {
    result[0] = v1[1] * v2[2] - v1[2] * v2[1];
    result[1] = v1[2] * v2[0] - v1[0] * v2[2];
    result[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

// Element-wise vector addition: result[i] = v1[i] + v2[i]
void vectorAdd(const double v1[], const double v2[], double result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = v1[i] + v2[i];
    }
}

// Element-wise vector subtraction: result[i] = v1[i] - v2[i]
void vectorSubtract(const double v1[], const double v2[], double result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = v1[i] - v2[i];
    }
}

// Scalar multiplication: result[i] = v[i] * scalar
void vectorScale(const double v[], double scalar, double result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = v[i] * scalar;
    }
}

// Projects v1 onto v2: proj_v2(v1) = ((v1·v2) / (|v2|²)) * v2
bool vectorProjection(const double v1[], const double v2[], double result[], int n) {
    if (n <= 0) return false;
    double mag2Squared = 0.0;
    for (int i = 0; i < n; i++) {
        mag2Squared += v2[i] * v2[i];
    }
    if (mag2Squared == 0.0) return false;  // Cannot project onto zero vector
    double dot = dotProduct(v1, v2, n);
    double scalar = dot / mag2Squared;
    vectorScale(v2, scalar, result, n);
    return true;
}

// ============================================================================
// ESSENTIAL HELPERS
// ============================================================================

// Copies all elements from source array to destination array
void copyArray(const double src[], double dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Prints a formatted summary of key descriptive statistics
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
