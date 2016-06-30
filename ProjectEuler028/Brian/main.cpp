// Starting with the number 1 and moving to the right in a clockwise direction
// a 5 by 5 spiral is formed as follows:
//
//                21  22  23  24  25
//                20   7   8   9  10
//                19   6   1   2  11
//                18   5   4   3  12
//                17  16  15  14  13
//
// It can be verified that the sum of the numbers on the diagonals is 101.
//
// What is the sum of the numbers in a 1001 by 1001 spiral formed in the
// same way?

#include <stdio.h>
#include <stdlib.h>

// definition of the spiral width
#define SIZE 1001

// program entry point
int main(int argc, char **argv) {
	// enter a loop to calculate the sum of the diagonals
	long total = 1, val = 1001 * 1001; int offset = 1;
	for (int i = 1001; i > 1; i = i - 2) {
		// add the four diagonals
		for (int j = 0; j < 4; j ++) {
			// add the number to the total and change the number
			total = total + val;
			val = val - SIZE + offset;
		}
		// increment the offset for the next layer of the spiral
		offset = offset + 2;
	}
	// output the solution
	printf("the answer is %ld.\n", total);
}
