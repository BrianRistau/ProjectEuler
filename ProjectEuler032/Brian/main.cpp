// We shall say than an n-digit number is pandigital if it makes use of all
// the digits 1 to n exactly once; for example, the 5-digit number, 15234,
// is 1 through 5 pandigital.
//
// The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing
// multiplicand, multiplier, and product is 1 through 9 pandigital.
//
// Find the sum of all products whose multiplicand/multiplier/product
// identity can be written as 1 through 9 pandigital.

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int alreadyfound(int prod);
int pandigital(int a, int b);
int getdigits(int n, int *digits);

// program entry point
int main(int argc, char **argv) {
	// loop through all of the possible numbers
	int total = 0;
	for (int i = 1; i < 3333; i ++) {
		// loop up to the first number
		for (int j = 1; j < i; j ++) {
			// check if the current numbers are pandigital
			if (!pandigital(i, j)) continue;
			// check if the number has already been found
			if (alreadyfound(i * j)) continue;
			// add the number to the running total
			total = total + (i * j);
		}
	}
	// output the solution
	printf("the answer is %d.\n", total);
}

// function to check if the number was already found
int index = 0, *found = (int *) malloc (16 * sizeof(int));
int alreadyfound(int prod) {
	// loop through all the product, return if found
	for (int i = 0; i < 16; i ++)
		// check each index
		if (found[i] == prod) return 1;
	// if not found, add it to the array
	found[index ++] = prod;
	// return that the number was not found
	return 0;
}

// function to check if the numbers are pandigital
int pandigital(int a, int b) {
	// keep track of the digits that have been found
	int digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	// arrays for the digits
	int *adigits = (int *) malloc (8 * sizeof(int));
	int *bdigits = (int *) malloc (8 * sizeof(int));
	int *cdigits = (int *) malloc (8 * sizeof(int));
	// handle the digits in the first number
	for (int i = 8; i > (8 - getdigits(a, adigits)); i --) {
		digits[adigits[i - 1]] = digits[adigits[i - 1]] + 1;
	}
	// handle the digits in the second number
	for (int i = 8; i > (8 - getdigits(b, bdigits)); i --) {
		digits[bdigits[i - 1]] = digits[bdigits[i - 1]] + 1;
	}
	// handle the digits in the product
	for (int i = 8; i > (8 - getdigits(a * b, cdigits)); i --) {
		digits[cdigits[i - 1]] = digits[cdigits[i - 1]] + 1;
	}
	// check if any zeros were found
	if (digits[0] > 0) return 0;
	// check for any bad counts
	for (int i = 1; i < 10; i ++) {
		// check if any digit count is not one
		if (digits[i] != 1) return 0;
	}
	// return that a pandigital set of number has been found
	return 1;
}

// function to get the digits of the current number
int getdigits(int n, int *digits) {
	// loop through the number until it is zero
	int count = 1; for (; count <= 8; count ++) {
		// calculate thet next digit
		digits[8 - count] = n % 10;
		// recalculate the current number
		if ((n = n / 10) == 0) break;
	}
	// return the number of digits
	return count;
}
