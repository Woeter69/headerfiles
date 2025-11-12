#include <iostream>
#include <iomanip>
#include <cmath>
#include "cstats.h"

using namespace std;

// Test counter
int passed = 0;
int failed = 0;

// Helper function to check if two doubles are approximately equal
bool approxEqual(double a, double b, double epsilon = 0.0001) {
    return fabs(a - b) < epsilon;
}

// Test macro for displaying results
#define TEST_RESULT(name, result) \
    cout << name << ": " << result << endl;

// Test macro for pass/fail
#define TEST(name, condition) \
    if (condition) { \
        passed++; \
    } else { \
        failed++; \
    }

int main() {
    cout << "=== COMPREHENSIVE CSTATS TEST SUITE ===" << endl << endl;
    
    // Test data sets
    double data1[] = {1, 2, 3, 4, 5};
    int n1 = 5;
    
    double data2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n2 = 10;
    
    double data3[] = {5, 5, 5, 5, 5};
    int n3 = 5;
    
    double data4[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n4 = 10;
    
    double data5[] = {-5, -3, 0, 3, 5};
    int n5 = 5;
    
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {2, 4, 6, 8, 10};
    int nxy = 5;
    
    double v1[] = {1, 0, 0};
    double v2[] = {0, 1, 0};
    double v3[] = {3, 4};
    int n3d = 3;
    int n2d = 2;
    
    cout << "--- BASIC STATISTICS ---" << endl;
    TEST_RESULT("mean(1,2,3,4,5)", mean(data1, n1));
    TEST_RESULT("mean(10-100)", mean(data2, n2));
    TEST_RESULT("mean(all 5s)", mean(data3, n3));
    
    double medianData[] = {1, 2, 3, 4, 5};
    TEST_RESULT("median(1,2,3,4,5)", median(medianData, 5));
    double medianData2[] = {1, 2, 3, 4};
    TEST_RESULT("median(1,2,3,4)", median(medianData2, 4));
    
    TEST_RESULT("mode(1,2,2,3,3,3,4,4,4,4)", mode(data4, n4));
    
    TEST_RESULT("min(1,2,3,4,5)", min(data1, n1));
    TEST_RESULT("max(1,2,3,4,5)", max(data1, n1));
    TEST_RESULT("sum(1,2,3,4,5)", sum(data1, n1));
    TEST_RESULT("count(data1)", count(data1, n1));
    TEST_RESULT("range(1,2,3,4,5)", range(data1, n1));
    
    cout << endl << "--- VARIANCE & STANDARD DEVIATION ---" << endl;
    TEST_RESULT("variance(1,2,3,4,5)", variance(data1, n1));
    TEST_RESULT("stdev(1,2,3,4,5)", stdev(data1, n1));
    TEST_RESULT("sampleVariance(1,2,3,4,5)", sampleVariance(data1, n1));
    TEST_RESULT("sampleStdev(1,2,3,4,5)", sampleStdev(data1, n1));
    TEST_RESULT("variance(all 5s)", variance(data3, n3));
    
    cout << endl << "--- PERCENTILES & QUARTILES ---" << endl;
    double percData[] = {1, 2, 3, 4, 5};
    TEST_RESULT("percentile(1-5, 50%)", percentile(percData, 5, 50.0));
    double q1Data[] = {1, 2, 3, 4, 5};
    TEST_RESULT("quartile1(1-5)", quartile1(q1Data, 5));
    double q3Data[] = {1, 2, 3, 4, 5};
    TEST_RESULT("quartile3(1-5)", quartile3(q3Data, 5));
    double iqrData[] = {1, 2, 3, 4, 5};
    TEST_RESULT("iqr(1-5)", iqr(iqrData, 5));
    
    cout << endl << "--- DEVIATION MEASURES ---" << endl;
    TEST_RESULT("meanAbsoluteDeviation(1-5)", meanAbsoluteDeviation(data1, n1));
    double madData[] = {1, 2, 3, 4, 5};
    TEST_RESULT("medianAbsoluteDeviation(1-5)", medianAbsoluteDeviation(madData, 5));
    TEST_RESULT("coefficientOfVariation(1-5)", coefficientOfVariation(data1, n1));
    TEST_RESULT("coefficientOfVariation(all 5s)", coefficientOfVariation(data3, n3));
    
    cout << endl << "--- SHAPE MEASURES ---" << endl;
    TEST_RESULT("skewness(1-5)", skewness(data1, n1));
    TEST_RESULT("skewness(all 5s)", skewness(data3, n3));
    TEST_RESULT("kurtosis(1-5)", kurtosis(data1, n1));
    TEST_RESULT("kurtosis(all 5s)", kurtosis(data3, n3));
    
    cout << endl << "--- Z-SCORE ---" << endl;
    TEST_RESULT("zScore(5, 3, 1)", zScore(5.0, 3.0, 1.0));
    TEST_RESULT("zScore(3, 3, 1)", zScore(3.0, 3.0, 1.0));
    TEST_RESULT("zScore(5, 3, 0)", zScore(5.0, 3.0, 0.0));
    
    cout << endl << "--- BIVARIATE STATISTICS ---" << endl;
    TEST_RESULT("covariance(x=[1-5], y=[2,4,6,8,10])", covariance(x, y, nxy));
    TEST_RESULT("correlation(x=[1-5], y=[2,4,6,8,10])", correlation(x, y, nxy));
    double uncorX[] = {1, 2, 3, 4, 5};
    double uncorY[] = {5, 4, 3, 2, 1};
    TEST_RESULT("correlation(x=[1-5], y=[5-1])", correlation(uncorX, uncorY, 5));
    
    cout << endl << "--- ALTERNATIVE MEANS ---" << endl;
    double posDat[] = {1, 2, 3, 4, 5};
    TEST_RESULT("geometricMean(1-5)", geometricMean(posDat, 5));
    TEST_RESULT("harmonicMean(1-5)", harmonicMean(posDat, 5));
    TEST_RESULT("rootMeanSquare(1-5)", rootMeanSquare(posDat, 5));
    TEST_RESULT("geometricMean(-5,-3,0,3,5)", geometricMean(data5, n5));
    
    cout << endl << "--- INFERENTIAL STATISTICS ---" << endl;
    TEST_RESULT("standardError(1-5)", standardError(data1, n1));
    TEST_RESULT("CI95Lower(1-5)", confidenceInterval95Lower(data1, n1));
    TEST_RESULT("CI95Upper(1-5)", confidenceInterval95Upper(data1, n1));
    double ciData[] = {1, 2, 3, 4, 5};
    double m = mean(ciData, 5);
    TEST_RESULT("mean(1-5) for CI check", m);
    
    cout << endl << "--- ROBUST STATISTICS ---" << endl;
    double trimData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TEST_RESULT("trimmedMean(1-10, 10%)", trimmedMean(trimData, 10, 10.0));
    double weights[] = {1, 1, 1, 1, 1};
    TEST_RESULT("weightedMean(1-5, equal weights)", weightedMean(data1, weights, n1));
    double weights2[] = {0, 0, 1, 0, 0};
    TEST_RESULT("weightedMean(1-5, middle only)", weightedMean(data1, weights2, n1));
    
    cout << endl << "--- REGRESSION ANALYSIS ---" << endl;
    TEST_RESULT("linearRegressionSlope(x=[1-5], y=[2,4,6,8,10])", linearRegressionSlope(x, y, nxy));
    TEST_RESULT("linearRegressionIntercept(x=[1-5], y=[2,4,6,8,10])", linearRegressionIntercept(x, y, nxy));
    TEST_RESULT("rSquared(x=[1-5], y=[2,4,6,8,10])", rSquared(x, y, nxy));
    
    cout << endl << "--- ARRAY OPERATIONS ---" << endl;
    double cumData[] = {1, 2, 3, 4, 5};
    double cumResult[5];
    cumulativeSum(cumData, cumResult, 5);
    cout << "cumulativeSum([1,2,3,4,5]): [";
    for (int i = 0; i < 5; i++) {
        cout << cumResult[i];
        if (i < 4) cout << ", ";
    }
    cout << "]" << endl;
    
    cout << endl << "--- VECTOR OPERATIONS ---" << endl;
    TEST_RESULT("dotProduct([1,0,0], [0,1,0])", dotProduct(v1, v2, n3d));
    TEST_RESULT("dotProduct([1-5], [1-5])", dotProduct(x, x, 5));
    
    TEST_RESULT("vectorMagnitude([3,4])", vectorMagnitude(v3, n2d));
    TEST_RESULT("vectorMagnitude([1,0,0])", vectorMagnitude(v1, n3d));
    
    TEST_RESULT("vectorDistance([1,0,0], [0,1,0])", vectorDistance(v1, v2, n3d));
    
    TEST_RESULT("vectorAngle([1,0,0], [0,1,0]) [radians]", vectorAngle(v1, v2, n3d));
    
    double normResult[3];
    normalizeVector(v3, normResult, n2d);
    cout << "normalizeVector([3,4]): [" << normResult[0] << ", " << normResult[1] << "]" << endl;
    TEST_RESULT("magnitude of normalized vector", vectorMagnitude(normResult, n2d));
    
    double crossResult[3];
    crossProduct3D(v1, v2, crossResult);
    cout << "crossProduct([1,0,0] × [0,1,0]): [" << crossResult[0] << ", " 
         << crossResult[1] << ", " << crossResult[2] << "]" << endl;
    
    double addResult[3];
    vectorAdd(v1, v2, addResult, n3d);
    cout << "vectorAdd([1,0,0] + [0,1,0]): [" << addResult[0] << ", " 
         << addResult[1] << ", " << addResult[2] << "]" << endl;
    
    double subResult[3];
    vectorSubtract(v1, v2, subResult, n3d);
    cout << "vectorSubtract([1,0,0] - [0,1,0]): [" << subResult[0] << ", " 
         << subResult[1] << ", " << subResult[2] << "]" << endl;
    
    double scaleResult[3];
    vectorScale(v1, 5.0, scaleResult, n3d);
    cout << "vectorScale([1,0,0] * 5): [" << scaleResult[0] << ", " 
         << scaleResult[1] << ", " << scaleResult[2] << "]" << endl;
    
    double projResult[3];
    vectorProjection(v1, v2, projResult, n3d);
    cout << "vectorProjection([1,0,0] onto [0,1,0]): [" << projResult[0] << ", " 
         << projResult[1] << ", " << projResult[2] << "]" << endl;
    
    cout << endl << "--- HELPER FUNCTIONS ---" << endl;
    double src[] = {1, 2, 3, 4, 5};
    double dest[5];
    copyArray(src, dest, 5);
    cout << "copyArray([1,2,3,4,5]): [" << dest[0] << ", ..." << dest[4] << "]" << endl;
    
    double sortData[] = {5, 2, 8, 1, 9};
    sortArray(sortData, 5);
    cout << "sortArray([5,2,8,1,9]): [" << sortData[0] << ", " << sortData[1] << ", " 
         << sortData[2] << ", " << sortData[3] << ", " << sortData[4] << "]" << endl;
    
    cout << endl << "--- EDGE CASES ---" << endl;
    TEST_RESULT("mean with n=0", mean(data1, 0));
    TEST_RESULT("variance with n=0", variance(data1, 0));
    TEST_RESULT("sampleVariance with n=1", sampleVariance(data1, 1));
    double emptyVec[1] = {0};
    cout << "normalizeVector([0]) returns: " << (normalizeVector(emptyVec, dest, 1) ? "true" : "false") << endl;
    cout << "vectorProjection onto [0] returns: " << (vectorProjection(v1, emptyVec, projResult, 1) ? "true" : "false") << endl;
    
    cout << endl << "--- SUMMARY STATISTICS DISPLAY ---" << endl;
    double summaryData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printSummaryStats(summaryData, 10);
    
    cout << endl << "=== TEST RESULTS ===" << endl;
    cout << "Passed: " << passed << endl;
    cout << "Failed: " << failed << endl;
    cout << "Total:  " << (passed + failed) << endl;
    
    if (failed == 0) {
        cout << endl << "*** ALL TESTS PASSED! ***" << endl;
        return 0;
    } else {
        cout << endl << "*** SOME TESTS FAILED ***" << endl;
        return 1;
    }
}
