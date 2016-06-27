// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17
//
// Find the sum of all the primes below two million.

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int isPrime(int num);

// program entry point
int main(int argc, char **argv) {

	// keep a running total and iterate up to 2 million
	long long unsigned total = 2;
	int num = 3;
	while (num < 2000000) {
		// check if the current number is prime
		if (isPrime(num)) total += num;
		num = num + 2;
	}

	// output the result
	printf("the answer is %llu.\n", total);

}

// function to determine if the specified number is prime
int iter;
int isPrime(int num) {

	// check the base cases
	if (num == 2 || num == 3) return 1;
	if (num % 2 == 0) return 0;

	// iterate up to the square root of the number
	for (iter = 3; iter * iter <= num; iter ++) {
		if (num % iter == 0) return 0;
	}

	// return true if no factors were found
	return 1;

}
