// The sum of the squares of the first ten natural numbers is
//  1^2 + 2^2 + ... + 10^2 = 385
//
// The square of the sum of the first ten natural numbers is
//  (1 + 2 + ... + 10)^2 = 55^5 = 2035
//
// Hence the difference between the sum of the squares of the
// first ten natural numbers and the square of the sum is
// 3025 - 385 = 2640.
//
// Find the difference between the sum of the squares of the
// first one hundred natural numbers and the square of the sum.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// program entry point
int main(int argc, char **argv) {

	// calculate the sum and the sum of the squares
	uint32_t sum = 0, square_sum = 0;
	for (int i = 1; i <= 100; i ++) {
		sum += i;
		square_sum += i * i;
	}

	// calculate the square of the sums
	uint32_t square = sum * sum;

	// output the difference
	printf("the answer is %d.\n", square - square_sum);

}
