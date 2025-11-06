#include "probability.h"
#include <cmath>

// Factorial function for probability calculations
long long factorial(int n) {
    if (n < 0) return 0;
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Permutation: nPr = n! / (n-r)!
long long permutation(int n, int r) {
    if (r > n || r < 0 || n < 0) return 0;
    long long result = 1;
    for (int i = n; i > n - r; i--) {
        result *= i;
    }
    return result;
}

// Combination: nCr = n! / (r! * (n-r)!)
long long combination(int n, int r) {
    if (r > n || r < 0 || n < 0) return 0;
    if (r > n - r) r = n - r; // Optimization
    long long result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

// Binomial probability: P(X=k) = nCr * p^k * (1-p)^(n-k)
double binomialProbability(int n, int k, double p) {
    if (k > n || k < 0 || n < 0 || p < 0 || p > 1) return 0;
    return combination(n, k) * pow(p, k) * pow(1 - p, n - k);
}

// Expected value for discrete distribution
double expectedValue(int values[], double probabilities[], int size) {
    double expected = 0;
    for (int i = 0; i < size; i++) {
        expected += values[i] * probabilities[i];
    }
    return expected;
}

// Variance for discrete distribution
double variance(int values[], double probabilities[], int size) {
    double mean = expectedValue(values, probabilities, size);
    double var = 0;
    for (int i = 0; i < size; i++) {
        var += probabilities[i] * pow(values[i] - mean, 2);
    }
    return var;
}

// Standard deviation
double standardDeviation(int values[], double probabilities[], int size) {
    return sqrt(variance(values, probabilities, size));
}
