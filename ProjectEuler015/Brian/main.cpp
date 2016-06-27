// Starting in the top left corner of a 2x2 grid, and only being able to move
// to the right and down, there are exactly 6 routes to the bottom right corner.
//
// How many such routes are there through a 20x20 grid?

#include <stdio.h>
#include <stdlib.h>

// macros for maximum x/y coordinates
#define WIDTH  20
#define HEIGHT 20

// function prototypes
long long unsigned ncr(int n, int r);

// program entry point
int main(int argc, char **argv) {

	// get the number of paths in the 20x20 grid
	long long unsigned paths = ncr(40, 20);
	// output the solution
	printf("the answer is %llu.\n", paths);

}

// function to calculate the binomial sum given n and r
long long unsigned ncr(int n, int r) {

	// handle the base cases
	if ( r      > n) return 0;
	if ((r * 2) > n) return (n - r);
	if ( r     == 0) return 1;

	// calculate the result
	long long unsigned result = n;
	for (int i = 2; i <= r; ++i) {
		result *= (n - i + 1);
		result /= i;
	}

	// return the result
	return result;

}
