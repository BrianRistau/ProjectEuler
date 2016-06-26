// The prime factors of 13195 are 5, 7, 13, and 29.
//
// What is the largest prime factor of the number 600851475143?

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// function prototypes
int isPrime(uint64_t num);

// program entry point
int main(int argc, char **argv) {

	// large variable to hold the number
	uint64_t number = 600851475143;
	// variable to hold the highest answer
	uint32_t max = 0;

	// loop through the number up to its square root
	uint64_t temp;
	for (uint64_t iter = 5; iter * iter < number; iter ++) {

		// loop again if the number is not a factor
		if (number % iter != 0) continue;
		// loop again if the number is not prime
		if (isPrime(iter) == 0) continue;
		max = (iter > max) ? iter : max;

	}

	// output the result
	printf("the answer is %d.\n", max);

}

// function to determine if the given number is prime
int isPrime(uint64_t num) {

	// eliminate the easy cases first
	if (num == 2 || num == 3) return 1;
	if (num % 2 == 0) return 0;

	// iterate from 5 to the square root of the number to check for factors
	for (uint64_t i = 5; i * i < num; i += 2) {
		if (num % i == 0) return 0;
	}

	// return true if a factor has not been found
	return 1;

}
