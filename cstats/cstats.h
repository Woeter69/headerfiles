#ifndef CSTATS_H
#define CSTATS_H

// Sorting helper
void sortArray(double arr[], int n);

// Basic stats
double mean(const double data[], int n);
double median(double data[], int n);
double mode(const double data[], int n);
double variance(const double data[], int n);
double stdev(const double data[], int n);
double min(const double data[], int n);
double max(const double data[], int n);
double sum(const double data[], int n);
int count(const double data[], int n);
double range(const double data[], int n);

// Advanced stats
double percentile(double data[], int n, double p);
double quartile1(double data[], int n);
double quartile3(double data[], int n);
double iqr(double data[], int n);
double sampleVariance(const double data[], int n);
double sampleStdev(const double data[], int n);
double meanAbsoluteDeviation(const double data[], int n);
double coefficientOfVariation(const double data[], int n);
double skewness(const double data[], int n);
double kurtosis(const double data[], int n);
double zScore(double value, double mean, double stdev);
double covariance(const double x[], const double y[], int n);
double correlation(const double x[], const double y[], int n);
double geometricMean(const double data[], int n);
double harmonicMean(const double data[], int n);
double rootMeanSquare(const double data[], int n);

// Inferential statistics
double standardError(const double data[], int n);
double confidenceInterval95Lower(const double data[], int n);
double confidenceInterval95Upper(const double data[], int n);

// Robust statistics
double trimmedMean(double data[], int n, double trimPercent);
double weightedMean(const double data[], const double weights[], int n);

// Regression analysis
double linearRegressionSlope(const double x[], const double y[], int n);
double linearRegressionIntercept(const double x[], const double y[], int n);
double rSquared(const double x[], const double y[], int n);

// Array operations
void cumulativeSum(const double data[], double result[], int n);

// Essential helpers
void copyArray(const double src[], double dest[], int n);
void printSummaryStats(const double data[], int n);

#endif
