// Euler discovered the remarkable quadratic formula:
//
//   n^2 + n + 41
//
// It turns out that the formula will produce 40 primes for the consecutive
// values n = 0 to 39.  However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41
// is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly
// divisible by 41.
//
// The incredible formula n^2 - 79n + 1601 was discovered, which produces 80
// primes for the consecutive values n = 0 to 79.  The product of the
// coefficients, -79 and 1601, is -126479.
//
// Considering quadratics of the form:
//
//   n^2 + an + b, where |a| < 1000 and |b| < 1000
//
//   where |n| is the modulus/absolute value of n
//   e.g. |11| = 11 and |-4| = 4
//
// Find the product of the coefficients, a and b, for the quadratic expression
// that produces the maximum number of primes for consecutive values of n,
// starting with n = 0.

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int getCount(int a, int b);
int isPrime(int n);

// program entry point
int main(int argc, char **argv) {
	// loop through the coefficients for a
	int maxcount = 0, maxa = 0, maxb = 0;
	for (int a = -999; a <= 999; a = a + 2) {
		// loop through the coefficients for b
		for (int b = -999; b <= 999; b = b + 2) {
			// start to count the consecutive primes
			int count = getCount(a, b);
			// handle if the next count is higher
			if (count > maxcount) {
				// set the max a and max b
				maxcount = count;
				maxa = a; maxb = b;
			}
		}
	}
	// output the result
	printf("the answer is %d x %d = %d.\n", maxa, maxb, maxa * maxb);
}

// function to perform the mathematical expression
int getCount(int a, int b) {
	// loop until a non-prime number is found
	int count = 0; for (int i = 0; ; i ++) {
		// calculate the next term
		int num = i * (i + a) + b;
		// break if this number is not prime
		if (!isPrime(num)) break;
		// increment the count
		count = count + 1;
	}
	// return the count
	return count;
}

// function to determine if the specified number is prime
int isPrime(int n) {
	// check the base cases
	if (n < 2) return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 2 == 0) return 0;
	// iterate up to the square root
	for (int i = 3; i * i <= n; i ++) {
		// if any even divisor is found, return false
		if (n % i == 0) return 0;
	}
	// return true if none of the other conditions are met
	return 1;
}
