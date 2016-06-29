// A unit fraction contains 1 in the numerator.  The decimal representation
// of the unit fractions with denominators 2 to 10 are given:
//
//   1/2  = 0.5
//   1/3  = 0.(3)
//   1/4  = 0.25
//   1/5  = 0.2
//   1/6  = 0.1(6)
//   1/7  = 0.(142857)
//   1/8  = 0.125
//   1/9  = 0.(1)
//   1/10 = 0.1
//
// Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.  It can
// be seen that 1/7 has a 6-digit recurring cycle.
//
// Find the value of d < 1000 for which 1/d contains the longest recurring
// cycle in its decimal fraction part.

// Note: https://mathworld.wolfram.com/DecimalExpansion.html

#include <stdio.h>
#include <stdlib.h>

// program entry point
int main(int argc, char **argv) {

	// iterate through all of the possible numbers (no evens)
	int maxnum = 0, maxlength = 0;
	for (int iter = 11; iter < 1000; iter ++) {
		// don't check this number if it is evenly divisible by 5
		if (iter % 5 == 0) continue;
		// Since we know that the maximum path length for a given
		// number is n-1 digits long, assume that this is the
		// current number's path length and calculate the remainder
		// for the entirity of the number (modified long division)
		// This is equivalent to (10^n - 1) % n
		int remainder, temp = 1, length = 0;
		for (int n = 0; n < iter; n ++)
			temp = (temp * 10) % iter;
		// store the remainder as it is given after n-1 decimal digits
		remainder = temp;
		// iterate again until we reach the same remainder, at which
		// time we will have figured out the recurrence length
		do {
			// recalculate the running remainder
			temp = (temp * 10) % iter;
			// increment the current recurrance length
			length = length + 1;
		// loop until the remainder is the same as the calculated one
		} while (temp != remainder);
		// check if this is the longest path length
		if (length > maxlength) {
			// set the values if it is
			maxnum = iter;
			maxlength = length;
		}
	}

	// output the solution
	printf("the answer is %d (%d).\n", maxnum, maxlength);

}
