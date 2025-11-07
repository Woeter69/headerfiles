#ifndef PROBABILITY_H
#define PROBABILITY_H

// Factorial function for probability calculations
long long factorial(int n);

// Permutation: nPr = n! / (n-r)!
long long permutation(int n, int r);

// Combination: nCr = n! / (r! * (n-r)!)
long long combination(int n, int r);

// Binomial probability: P(X=k) = nCr * p^k * (1-p)^(n-k)
double binomialProbability(int n, int k, double p);

// Expected value for discrete distribution
double expectedValue(int values[], double probabilities[], int size);

// Variance for discrete distribution
double variance(int values[], double probabilities[], int size);

// Standard deviation
double standardDeviation(int values[], double probabilities[], int size);

#endif
