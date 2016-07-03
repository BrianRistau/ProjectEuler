// If we list all of the natural numbers below 10 that are multiples
// of 3 or 5, we get 3, 5, 6, and 9.  The sum of these multiples is 23.

// Find the sum of all the multiples of 3 or 5 below 1000.

#include <stdio.h>
#include <stdlib.h>

// program entry point
int main(int argc, char **argv) {

	// initialize a running total
	int total = 0;
	// loop through all the numbers from 0 to 999
	for (int iter=0; iter<1000; iter++) {
		// add the current number if it is evenly divisible
		if (iter % 3 == 0 || iter % 5 == 0) total += iter;
	}

	// output the result
	printf("the solution is %d\n", total);

}
