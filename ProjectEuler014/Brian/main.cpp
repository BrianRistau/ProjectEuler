// The following iterative sequence is defined for the set of positive integers:
//
//   (n is even) n -> n/2
//   (n is odd)  n -> 3*n + 1
//
// Using the rule above and starting with 13, we generate the following
// sequence:
//
//   13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
//
// It can be seen that this sequence (starting at 13 and finishing at 1)
// contains 10 terms.  Although it has not been proved yet (Collatz Problem),
// it is thought that all starting numbers finish at 1.
//
// Which starting number, under one million, produces the longest chain?

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// function prototypes
uint32_t collatz(uint32_t num);

// program entry point
int main(int argc, char **argv) {

	// variables for finding the longest path
	uint32_t maxnum = 0, maxlength = 0, length;

	// loop through all the numbers from one to one million
	for (uint32_t iter = 500001; iter < 1000000; iter += 2) {
		// get the collatz path length of the current number
		length = collatz(iter);
		// check if it is the new longest collatz path
		if (length > maxlength) {
			maxlength = length;
			maxnum = iter;
		}
	}

	// output the answer
	uint32_t temp = collatz(837799u);
	printf("the answer is %d (%d).\n", maxnum, maxlength);

}

// function to determine the collatz path length of a number
uint32_t collatz(uint32_t num) {

	// loop until the full collatz path length is found
	uint32_t length = 1;
	for (; num > 1; length ++) {
		// compute the next collatz digit
		if (num % 2 == 0) num = num / 2;
		else num = (num * 3) + 1;
	}

	// return the path length for the current number
	return length;

}
