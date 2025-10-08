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

#endif
