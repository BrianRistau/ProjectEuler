// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can
// see that the 6th prime is 13.
//
// What is the 10001st prime number?

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int nextPrime(int current);
int isPrime(int num);

// program entry point
int main(int argc, char **argv) {

	// keep track of the current prime and its index
	int num = 2, index = 1;
	while (index < 10001) {
		// keep calculating the next prime number
		num = nextPrime(num);
		index += 1;
	}

	// output the answer
	printf("the answer is %d.\n", num);

}

// function to get the next prime from the specified starting point
int nextPrime(int current) {

	// create an interation variable
	int iter = current + 1;
	// loop endlessly while a prime is being found
	while (1) {
		if (isPrime(iter)) return iter;
		else iter += 1;
	}

}

// function to return whether or not the given number is prime
int isPrime(int num) {

	// check the base cases
	if (num == 2 || num == 3) return 1;
	if (num % 2 == 0) return 0;
	if (num % 3 == 0) return 0;

	// iterate up to the number's square root, checking for factors
	for (int iter = 5; iter * iter <= num; iter += 2) {
		if (num % iter == 0) return 0;
	}

	// return true if no factors were found
	return 1;

}
