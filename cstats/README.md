# CStats - Comprehensive Statistical Analysis Library for C++

A robust, easy-to-use statistical analysis library providing a wide range of statistical functions for C++ applications.

## Features

- **Basic Statistics**: Mean, median, mode, variance, standard deviation, min, max, sum, range
- **Advanced Statistics**: Percentiles, quartiles, IQR, skewness, kurtosis, z-scores
- **Inferential Statistics**: Standard error, confidence intervals
- **Robust Statistics**: Trimmed mean, weighted mean
- **Correlation Analysis**: Covariance, Pearson correlation
- **Regression Analysis**: Linear regression (slope, intercept, R²)
- **Alternative Means**: Geometric mean, harmonic mean, root mean square
- **Array Operations**: Cumulative sum, array copying

## Installation

Simply include the header file in your C++ project:

```cpp
#include "cstats.h"
```

Compile with the implementation file:

```bash
g++ -o myprogram myprogram.cpp cstats.cpp -lm
```

## Quick Start

```cpp
#include <iostream>
#include "cstats.h"

int main() {
    double data[] = {2.5, 3.7, 5.1, 4.2, 6.8, 3.9, 5.5};
    int n = 7;
    
    // Basic statistics
    std::cout << "Mean: " << mean(data, n) << std::endl;
    std::cout << "Median: " << median(data, n) << std::endl;
    std::cout << "Std Dev: " << stdev(data, n) << std::endl;
    
    // Print comprehensive summary
    printSummaryStats(data, n);
    
    return 0;
}
```

## Function Reference

### Basic Statistics

#### `double mean(const double data[], int n)`
Calculates the arithmetic mean (average).
```cpp
double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
double avg = mean(data, 5);  // Returns 3.0
```

#### `double median(double data[], int n)`
Calculates the median (middle value). **Note**: Modifies array by sorting.
```cpp
double data[] = {5.0, 1.0, 3.0, 2.0, 4.0};
double med = median(data, 5);  // Returns 3.0
```

#### `double mode(const double data[], int n)`
Finds the most frequently occurring value.

#### `double variance(const double data[], int n)`
Calculates population variance (divides by n).

#### `double stdev(const double data[], int n)`
Calculates population standard deviation.

#### `double min(const double data[], int n)` / `double max(const double data[], int n)`
Finds minimum or maximum value.

#### `double sum(const double data[], int n)`
Calculates sum of all values.

#### `double range(const double data[], int n)`
Calculates range (max - min).

### Advanced Statistics

#### `double percentile(double data[], int n, double p)`
Calculates the specified percentile (0-100). **Note**: Modifies array by sorting.
```cpp
double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
double p90 = percentile(data, 5, 90.0);  // 90th percentile
```

#### `double quartile1(double data[], int n)` / `double quartile3(double data[], int n)`
Calculates Q1 (25th percentile) or Q3 (75th percentile).

#### `double iqr(double data[], int n)`
Calculates interquartile range (Q3 - Q1).

#### `double sampleVariance(const double data[], int n)`
Calculates sample variance (divides by n-1).

#### `double sampleStdev(const double data[], int n)`
Calculates sample standard deviation.

#### `double meanAbsoluteDeviation(const double data[], int n)`
Calculates mean absolute deviation from the mean.

#### `double coefficientOfVariation(const double data[], int n)`
Calculates coefficient of variation as a percentage (CV = σ/μ × 100).

#### `double skewness(const double data[], int n)`
Measures asymmetry of the distribution.
- Negative: left-skewed
- Zero: symmetric
- Positive: right-skewed

#### `double kurtosis(const double data[], int n)`
Measures tailedness of the distribution (excess kurtosis).
- Negative: lighter tails than normal
- Zero: normal distribution
- Positive: heavier tails than normal

#### `double zScore(double value, double mean, double stdev)`
Calculates standardized z-score for a value.
```cpp
double z = zScore(75.0, 70.0, 5.0);  // Returns 1.0
```

### Inferential Statistics

#### `double standardError(const double data[], int n)`
Calculates standard error of the mean (SE = s/√n).

#### `double confidenceInterval95Lower(const double data[], int n)`
Calculates lower bound of 95% confidence interval (mean - 1.96×SE).

#### `double confidenceInterval95Upper(const double data[], int n)`
Calculates upper bound of 95% confidence interval (mean + 1.96×SE).

```cpp
double data[] = {10.2, 11.5, 9.8, 10.7, 11.1};
double lower = confidenceInterval95Lower(data, 5);
double upper = confidenceInterval95Upper(data, 5);
std::cout << "95% CI: [" << lower << ", " << upper << "]" << std::endl;
```

### Robust Statistics

#### `double trimmedMean(double data[], int n, double trimPercent)`
Calculates mean after removing specified percentage from each end (0-50%).
```cpp
double data[] = {1.0, 2.0, 3.0, 4.0, 100.0};  // 100 is an outlier
double tm = trimmedMean(data, 5, 20.0);  // Trims 20% from each end
```

#### `double weightedMean(const double data[], const double weights[], int n)`
Calculates weighted average.
```cpp
double values[] = {85.0, 90.0, 78.0};
double weights[] = {0.3, 0.5, 0.2};  // Exam weights
double weighted_avg = weightedMean(values, weights, 3);
```

### Correlation Analysis

#### `double covariance(const double x[], const double y[], int n)`
Calculates covariance between two datasets.

#### `double correlation(const double x[], const double y[], int n)`
Calculates Pearson correlation coefficient (-1 to 1).
```cpp
double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
double y[] = {2.0, 4.0, 5.0, 4.0, 5.0};
double r = correlation(x, y, 5);  // Measures linear relationship
```

### Regression Analysis

#### `double linearRegressionSlope(const double x[], const double y[], int n)`
Calculates slope (m) of best-fit line y = mx + b.

#### `double linearRegressionIntercept(const double x[], const double y[], int n)`
Calculates y-intercept (b) of best-fit line.

#### `double rSquared(const double x[], const double y[], int n)`
Calculates coefficient of determination (0 to 1).
- 0: No linear relationship
- 1: Perfect linear relationship

```cpp
double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
double y[] = {2.1, 4.0, 5.9, 8.1, 10.0};

double slope = linearRegressionSlope(x, y, 5);
double intercept = linearRegressionIntercept(x, y, 5);
double r2 = rSquared(x, y, 5);

std::cout << "y = " << slope << "x + " << intercept << std::endl;
std::cout << "R² = " << r2 << std::endl;
```

### Alternative Means

#### `double geometricMean(const double data[], int n)`
Calculates geometric mean (nth root of product). All values must be positive.
```cpp
double growth_rates[] = {1.05, 1.08, 1.03};  // 5%, 8%, 3% growth
double avg_growth = geometricMean(growth_rates, 3);
```

#### `double harmonicMean(const double data[], int n)`
Calculates harmonic mean (reciprocal of mean of reciprocals). No values can be zero.
```cpp
double speeds[] = {60.0, 40.0};  // mph for two legs of trip
double avg_speed = harmonicMean(speeds, 2);
```

#### `double rootMeanSquare(const double data[], int n)`
Calculates RMS (quadratic mean).

### Array Operations

#### `void cumulativeSum(const double data[], double result[], int n)`
Calculates running sum.
```cpp
double data[] = {1.0, 2.0, 3.0, 4.0};
double cumsum[4];
cumulativeSum(data, cumsum, 4);
// cumsum is now {1.0, 3.0, 6.0, 10.0}
```

### Utility Functions

#### `void sortArray(double arr[], int n)`
Sorts array in ascending order (bubble sort).

#### `void copyArray(const double src[], double dest[], int n)`
Copies elements from source to destination.

#### `void printSummaryStats(double data[], int n)`
Prints comprehensive statistical summary.
```cpp
double data[] = {2.5, 3.7, 5.1, 4.2, 6.8, 3.9, 5.5};
printSummaryStats(data, 7);
```

Output:
```
=== Summary Statistics ===
Count:    7
Mean:     4.52857
Median:   4.2
Std Dev:  1.38197
Min:      2.5
Max:      6.8
Range:    4.3
Q1:       3.7
Q3:       5.5
```

## Important Notes

### Array Modification
Some functions modify the input array by sorting it:
- `median()`
- `percentile()`
- `quartile1()` / `quartile3()`
- `iqr()`
- `trimmedMean()`
- `printSummaryStats()`

If you need to preserve the original array, use `copyArray()` first:
```cpp
double original[] = {5.0, 1.0, 3.0, 2.0, 4.0};
double copy[5];
copyArray(original, copy, 5);
double med = median(copy, 5);  // original is unchanged
```

### Error Handling
Functions return `0.0` for invalid inputs (e.g., n ≤ 0, division by zero).

### Data Requirements
- **Geometric Mean**: All values must be positive
- **Harmonic Mean**: No values can be zero
- **Percentile**: p must be between 0 and 100
- **Trimmed Mean**: trimPercent must be between 0 and 50

## Examples

### Example 1: Basic Data Analysis
```cpp
#include <iostream>
#include "cstats.h"

int main() {
    double scores[] = {85.5, 92.0, 78.5, 88.0, 95.5, 82.0, 90.0};
    int n = 7;
    
    std::cout << "Class Statistics:" << std::endl;
    std::cout << "Average: " << mean(scores, n) << std::endl;
    std::cout << "Median: " << median(scores, n) << std::endl;
    std::cout << "Std Dev: " << sampleStdev(scores, n) << std::endl;
    std::cout << "Range: " << range(scores, n) << std::endl;
    
    return 0;
}
```

### Example 2: Correlation and Regression
```cpp
#include <iostream>
#include "cstats.h"

int main() {
    double study_hours[] = {2.0, 3.0, 4.0, 5.0, 6.0};
    double test_scores[] = {65.0, 72.0, 78.0, 85.0, 90.0};
    int n = 5;
    
    double r = correlation(study_hours, test_scores, n);
    double slope = linearRegressionSlope(study_hours, test_scores, n);
    double intercept = linearRegressionIntercept(study_hours, test_scores, n);
    double r2 = rSquared(study_hours, test_scores, n);
    
    std::cout << "Correlation: " << r << std::endl;
    std::cout << "Regression: score = " << slope << " * hours + " 
              << intercept << std::endl;
    std::cout << "R-squared: " << r2 << std::endl;
    
    return 0;
}
```

### Example 3: Confidence Intervals
```cpp
#include <iostream>
#include "cstats.h"

int main() {
    double measurements[] = {10.2, 10.5, 9.8, 10.1, 10.3, 9.9, 10.4};
    int n = 7;
    
    double avg = mean(measurements, n);
    double se = standardError(measurements, n);
    double ci_lower = confidenceInterval95Lower(measurements, n);
    double ci_upper = confidenceInterval95Upper(measurements, n);
    
    std::cout << "Mean: " << avg << std::endl;
    std::cout << "Standard Error: " << se << std::endl;
    std::cout << "95% CI: [" << ci_lower << ", " << ci_upper << "]" << std::endl;
    
    return 0;
}
```

## License

This library is provided as-is for educational and commercial use.

## Version History

- **v1.0** - Initial release with comprehensive statistical functions

## Contributing

Contributions are welcome! Please ensure all functions include proper error handling and documentation.
