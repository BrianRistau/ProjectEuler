// Surprisingly there are only three numbers that can be written as the sum
// of the fourth powers of their digits:
//
//   1634 = 1 ^ 4 + 6 ^ 4 + 3 ^ 4 + 4 ^ 4
//   8208 = 8 ^ 4 + 2 ^ 4 + 0 ^ 4 + 8 ^ 4
//   9474 = 9 ^ 4 + 4 ^ 4 + 7 ^ 4 + 4 ^ 4
//
// As 1 = 1 ^ 4 is not a sum it is not included.
//
// The sum of these numbers is 1634 + 8208 + 9474 = 19316.
//
// Find the sum of all the numbers that can be written as the sum of fifth
// powers of their digits.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// function prototypes
#define DIGITS 8
int getDigits(int num, int *digits);
long getPowerSum(int *digits, int size);

// program entry point
int main(int argc, char **argv) {
	// create an array to hold the digits of the number
	int total = 0, count, *digits = (int *) malloc (DIGITS * sizeof(int));
	// loop through all of the possible numbers
	for (int i = 2; i < 300000; i ++) {
		// get the digits of the current number
		count = getDigits(i, digits);
		// get the power sum of the current number
		if (i == getPowerSum(digits, count))
			total = total + i;
	}
	// output the solution
	printf("the answer is %d.\n", total);
}

// function to get the digits of the current number
int getDigits(int num, int *digits) {
	// loop while there are still digits left
	int count = 0;
	while (num != 0) {
		// set the current digit
		count = count + 1;
		digits[DIGITS - count] = num % 10;
		// modify the number to get the next digit
		num = num / 10;
	}
	// return the number of digits in the number
	return count;
}

// function to get the power sum of the current number's digits
long getPowerSum(int *digits, int size) {
	// loop through all of the number's digits
	int total = 0;
	for (int i = 1; i <= size; i ++) {
		// add the current digit to the digit sum
		total = total + pow(digits[DIGITS - i], 5);
	}
	// return the total
	return total;
}
