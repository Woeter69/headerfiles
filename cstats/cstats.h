/**
 * @file cstats.h
 * @brief Comprehensive statistical analysis library for C++
 * @author Statistics Library
 * @version 1.0
 */

#ifndef CSTATS_H
#define CSTATS_H

// ============================================================================
// SORTING HELPER
// ============================================================================

/**
 * @brief Sorts an array in ascending order using bubble sort
 * @param arr Array to sort (modified in place)
 * @param n Number of elements in the array
 */
void sortArray(double arr[], int n);

// ============================================================================
// BASIC STATISTICS
// ============================================================================

/**
 * @brief Calculates the arithmetic mean (average) of a dataset
 * @param data Array of values
 * @param n Number of elements
 * @return Mean value, or 0.0 if n <= 0
 */
double mean(const double data[], int n);

/**
 * @brief Calculates the median (middle value) of a dataset
 * @param data Array of values (will be sorted)
 * @param n Number of elements
 * @return Median value, or 0.0 if n <= 0
 */
double median(double data[], int n);

/**
 * @brief Finds the mode (most frequent value) in a dataset
 * @param data Array of values
 * @param n Number of elements
 * @return Mode value, or first element if n <= 0
 */
double mode(const double data[], int n);

/**
 * @brief Calculates the population variance
 * @param data Array of values
 * @param n Number of elements
 * @return Variance, or 0.0 if n <= 0
 */
double variance(const double data[], int n);

/**
 * @brief Calculates the population standard deviation
 * @param data Array of values
 * @param n Number of elements
 * @return Standard deviation, or 0.0 if n <= 0
 */
double stdev(const double data[], int n);

/**
 * @brief Finds the minimum value in a dataset
 * @param data Array of values
 * @param n Number of elements
 * @return Minimum value, or 0.0 if n <= 0
 */
double min(const double data[], int n);

/**
 * @brief Finds the maximum value in a dataset
 * @param data Array of values
 * @param n Number of elements
 * @return Maximum value, or 0.0 if n <= 0
 */
double max(const double data[], int n);

/**
 * @brief Calculates the sum of all values in a dataset
 * @param data Array of values
 * @param n Number of elements
 * @return Sum of all values
 */
double sum(const double data[], int n);

/**
 * @brief Returns the count of elements
 * @param data Array of values
 * @param n Number of elements
 * @return Count of elements, or 0 if n <= 0
 */
int count(const double data[], int n);

/**
 * @brief Calculates the range (max - min) of a dataset
 * @param data Array of values
 * @param n Number of elements
 * @return Range, or 0.0 if n <= 0
 */
double range(const double data[], int n);

// ============================================================================
// ADVANCED STATISTICS
// ============================================================================

/**
 * @brief Calculates the specified percentile of a dataset
 * @param data Array of values (will be sorted)
 * @param n Number of elements
 * @param p Percentile to calculate (0-100)
 * @return Percentile value, or 0.0 if invalid parameters
 */
double percentile(double data[], int n, double p);

/**
 * @brief Calculates the first quartile (25th percentile)
 * @param data Array of values (will be sorted)
 * @param n Number of elements
 * @return Q1 value
 */
double quartile1(double data[], int n);

/**
 * @brief Calculates the third quartile (75th percentile)
 * @param data Array of values (will be sorted)
 * @param n Number of elements
 * @return Q3 value
 */
double quartile3(double data[], int n);

/**
 * @brief Calculates the interquartile range (Q3 - Q1)
 * @param data Array of values (will be sorted)
 * @param n Number of elements
 * @return IQR value, or 0.0 if n <= 0
 */
double iqr(double data[], int n);

/**
 * @brief Calculates the sample variance (using n-1 denominator)
 * @param data Array of values
 * @param n Number of elements
 * @return Sample variance, or 0.0 if n <= 1
 */
double sampleVariance(const double data[], int n);

/**
 * @brief Calculates the sample standard deviation (using n-1 denominator)
 * @param data Array of values
 * @param n Number of elements
 * @return Sample standard deviation, or 0.0 if n <= 1
 */
double sampleStdev(const double data[], int n);

/**
 * @brief Calculates the mean absolute deviation from the mean
 * @param data Array of values
 * @param n Number of elements
 * @return MAD value, or 0.0 if n <= 0
 */
double meanAbsoluteDeviation(const double data[], int n);

/**
 * @brief Calculates the median absolute deviation (robust measure of dispersion)
 * @param data Array of values (will be sorted)
 * @param n Number of elements
 * @return Median absolute deviation, or 0.0 if n <= 0
 * @note More robust to outliers than standard deviation
 */
double medianAbsoluteDeviation(double data[], int n);

/**
 * @brief Calculates the coefficient of variation (CV = stdev/mean * 100)
 * @param data Array of values
 * @param n Number of elements
 * @return CV as a percentage, or 0.0 if n <= 0 or mean is 0
 */
double coefficientOfVariation(const double data[], int n);

/**
 * @brief Calculates the skewness (measure of asymmetry)
 * @param data Array of values
 * @param n Number of elements
 * @return Skewness value, or 0.0 if n <= 2
 */
double skewness(const double data[], int n);

/**
 * @brief Calculates the excess kurtosis (measure of tailedness)
 * @param data Array of values
 * @param n Number of elements
 * @return Excess kurtosis value, or 0.0 if n <= 3
 */
double kurtosis(const double data[], int n);

/**
 * @brief Calculates the z-score (standard score) for a value
 * @param value The value to standardize
 * @param mean Mean of the distribution
 * @param stdev Standard deviation of the distribution
 * @return Z-score, or 0.0 if stdev is 0
 */
double zScore(double value, double mean, double stdev);

/**
 * @brief Calculates the covariance between two datasets
 * @param x First array of values
 * @param y Second array of values
 * @param n Number of elements in each array
 * @return Covariance, or 0.0 if n <= 0
 */
double covariance(const double x[], const double y[], int n);

/**
 * @brief Calculates the Pearson correlation coefficient between two datasets
 * @param x First array of values
 * @param y Second array of values
 * @param n Number of elements in each array
 * @return Correlation coefficient (-1 to 1), or 0.0 if invalid
 */
double correlation(const double x[], const double y[], int n);

/**
 * @brief Calculates the geometric mean (nth root of product)
 * @param data Array of values (must be positive)
 * @param n Number of elements
 * @return Geometric mean, or 0.0 if any value <= 0 or n <= 0
 */
double geometricMean(const double data[], int n);

/**
 * @brief Calculates the harmonic mean (reciprocal of mean of reciprocals)
 * @param data Array of values (must be non-zero)
 * @param n Number of elements
 * @return Harmonic mean, or 0.0 if any value is 0 or n <= 0
 */
double harmonicMean(const double data[], int n);

/**
 * @brief Calculates the root mean square (quadratic mean)
 * @param data Array of values
 * @param n Number of elements
 * @return RMS value, or 0.0 if n <= 0
 */
double rootMeanSquare(const double data[], int n);

// ============================================================================
// INFERENTIAL STATISTICS
// ============================================================================

/**
 * @brief Calculates the standard error of the mean (SE = s/sqrt(n))
 * @param data Array of values
 * @param n Number of elements
 * @return Standard error, or 0.0 if n <= 1
 */
double standardError(const double data[], int n);

/**
 * @brief Calculates the lower bound of the 95% confidence interval
 * @param data Array of values
 * @param n Number of elements
 * @return Lower bound (mean - 1.96*SE), or 0.0 if n <= 1
 */
double confidenceInterval95Lower(const double data[], int n);

/**
 * @brief Calculates the upper bound of the 95% confidence interval
 * @param data Array of values
 * @param n Number of elements
 * @return Upper bound (mean + 1.96*SE), or 0.0 if n <= 1
 */
double confidenceInterval95Upper(const double data[], int n);

// ============================================================================
// ROBUST STATISTICS
// ============================================================================

/**
 * @brief Calculates the trimmed mean (mean after removing outliers)
 * @param data Array of values (will be sorted)
 * @param n Number of elements
 * @param trimPercent Percentage to trim from each end (0-50)
 * @return Trimmed mean, or 0.0 if invalid parameters
 */
double trimmedMean(double data[], int n, double trimPercent);

/**
 * @brief Calculates the weighted mean
 * @param data Array of values
 * @param weights Array of weights corresponding to each value
 * @param n Number of elements
 * @return Weighted mean, or 0.0 if n <= 0 or total weight is 0
 */
double weightedMean(const double data[], const double weights[], int n);

// ============================================================================
// REGRESSION ANALYSIS
// ============================================================================

/**
 * @brief Calculates the slope of the linear regression line (y = mx + b)
 * @param x Independent variable array
 * @param y Dependent variable array
 * @param n Number of data points
 * @return Slope (m), or 0.0 if n <= 1 or denominator is 0
 */
double linearRegressionSlope(const double x[], const double y[], int n);

/**
 * @brief Calculates the y-intercept of the linear regression line
 * @param x Independent variable array
 * @param y Dependent variable array
 * @param n Number of data points
 * @return Y-intercept (b), or 0.0 if n <= 1
 */
double linearRegressionIntercept(const double x[], const double y[], int n);

/**
 * @brief Calculates the coefficient of determination (R-squared)
 * @param x Independent variable array
 * @param y Dependent variable array
 * @param n Number of data points
 * @return R-squared value (0-1), or 0.0 if n <= 1 or invalid
 */
double rSquared(const double x[], const double y[], int n);

// ============================================================================
// ARRAY OPERATIONS
// ============================================================================

/**
 * @brief Calculates the cumulative sum of an array
 * @param data Input array of values
 * @param result Output array for cumulative sums (must be pre-allocated)
 * @param n Number of elements
 */
void cumulativeSum(const double data[], double result[], int n);

// ============================================================================
// VECTOR OPERATIONS
// ============================================================================

/**
 * @brief Calculates the dot product of two vectors
 * @param v1 First vector
 * @param v2 Second vector
 * @param n Number of elements in each vector
 * @return Dot product (sum of element-wise products)
 */
double dotProduct(const double v1[], const double v2[], int n);

/**
 * @brief Calculates the magnitude (length) of a vector
 * @param v Vector
 * @param n Number of elements
 * @return Euclidean norm (sqrt of sum of squares)
 */
double vectorMagnitude(const double v[], int n);

/**
 * @brief Calculates the Euclidean distance between two vectors
 * @param v1 First vector
 * @param v2 Second vector
 * @param n Number of elements in each vector
 * @return Euclidean distance
 */
double vectorDistance(const double v1[], const double v2[], int n);

/**
 * @brief Calculates the angle between two vectors in radians
 * @param v1 First vector
 * @param v2 Second vector
 * @param n Number of elements in each vector
 * @return Angle in radians (0 to π), or 0.0 if either vector has zero magnitude
 */
double vectorAngle(const double v1[], const double v2[], int n);

/**
 * @brief Normalizes a vector to unit length
 * @param v Input vector
 * @param result Output normalized vector (must be pre-allocated)
 * @param n Number of elements
 * @return true if successful, false if vector has zero magnitude
 */
bool normalizeVector(const double v[], double result[], int n);

/**
 * @brief Calculates the cross product of two 3D vectors
 * @param v1 First 3D vector (must have 3 elements)
 * @param v2 Second 3D vector (must have 3 elements)
 * @param result Output 3D vector (must be pre-allocated with 3 elements)
 */
void crossProduct3D(const double v1[], const double v2[], double result[]);

/**
 * @brief Adds two vectors element-wise
 * @param v1 First vector
 * @param v2 Second vector
 * @param result Output vector (must be pre-allocated)
 * @param n Number of elements
 */
void vectorAdd(const double v1[], const double v2[], double result[], int n);

/**
 * @brief Subtracts two vectors element-wise (v1 - v2)
 * @param v1 First vector
 * @param v2 Second vector
 * @param result Output vector (must be pre-allocated)
 * @param n Number of elements
 */
void vectorSubtract(const double v1[], const double v2[], double result[], int n);

/**
 * @brief Multiplies a vector by a scalar
 * @param v Input vector
 * @param scalar Scalar value to multiply by
 * @param result Output vector (must be pre-allocated)
 * @param n Number of elements
 */
void vectorScale(const double v[], double scalar, double result[], int n);

/**
 * @brief Calculates the projection of v1 onto v2
 * @param v1 Vector to project
 * @param v2 Vector to project onto
 * @param result Output projection vector (must be pre-allocated)
 * @param n Number of elements
 * @return true if successful, false if v2 has zero magnitude
 */
bool vectorProjection(const double v1[], const double v2[], double result[], int n);

// ============================================================================
// ESSENTIAL HELPERS
// ============================================================================

/**
 * @brief Copies elements from source array to destination array
 * @param src Source array
 * @param dest Destination array (must be pre-allocated)
 * @param n Number of elements to copy
 */
void copyArray(const double src[], double dest[], int n);

/**
 * @brief Prints a summary of key statistics for a dataset
 * @param data Array of values (will be sorted for quartiles)
 * @param n Number of elements
 */
void printSummaryStats(double data[], int n);

#endif
