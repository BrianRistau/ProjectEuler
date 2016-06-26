// A pythagorean triplet is a set of three natural numbers, a < b < c, for
// which a^2 + b^2 = c^2
//
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product a*b*c.

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int isSquare(int num);

// program entry point
int main(int argc, char **argv) {

	int a = 1, b = 1, c;
	// enter a while loop to search for the solution
	while (1) {

		// calculate c, check if it is a square
		c = (a * a) + (b * b);
		if (c = isSquare(c)) {
			// check if they all add up to 1000
			if (a + b + c == 1000) {
				// output the answer and exit
				printf("the answer is %d", a * b * c);
				exit(0);
			}
		}


		// increment b until it is at the same level as a
		if ((b += 1) > a) {
			a += 1;
			b = 1;
		}

		// check if a has reached its limit
		if (a > 1000) {
			printf("no answer was found\n");
			exit(1);
		}

	}

}

// function to determine if a number is a square
// if yes, returns the square root (whole number)
// if not, returns 0
int isSquare(int num) {

	// iterate through until the iterator is larger than the number itself
	int iterator = 1;
	while (1) {

		// check if the square root has been found
		if (iterator * iterator == num) return iterator;
		// check fi the iterator exceeds the number
		if (iterator * iterator > num) return 0;

		// otherwise, add one to the iterator and loop again
		iterator += 1;

	}

}
