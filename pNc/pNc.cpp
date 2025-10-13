#include "pNc.h"

int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n * factorial(n-1);
	}
}

int permutation(int n,int r) {
	return factorial(n)/factorial(r)*factorial(n-r);
}

int combination(int n,int r) {
	return factorial(n)/factorial(n-r);
}




