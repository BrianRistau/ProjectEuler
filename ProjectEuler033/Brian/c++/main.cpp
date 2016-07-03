// The fraction 49/98 is a curious fraction, as an inexperienced mathematician
// in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which
// is correct, is obtained by cancelling the 9s.
//
// We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
//
// There are exactly four non-trivial examples of this type of fraction, less
// than one in value, and containing two digits in the numerator and
// denominator.
//
// If the product of these four fractions is given in its lowest common terms,
// find the value of the denominator.

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int check(int numerator, int denominator);
void reduce(int *numerator, int *denominator);

// program entry point
int main(int argc, char **argv) {
	// loop through all of the potential numerators
	int ntotal = 1, dtotal = 1;
	for (int n = 11; n < 100; n ++) {
		// check if the numerator is a multiple of 10 or 11
		if (n % 10 == 0 || n % 11 == 0) continue;
		// loop through all of the potential denominators
		for (int d = n + 1; d < 100; d ++) {
			// check if the denominator is a multiple of 10 or 11
			if (d % 10 == 0 || d % 11 == 0) continue;
			// check if the number reduces to an equivalent amount
			if (!check(n, d)) continue;
			// add the numerator and denominator to the totals
			ntotal = ntotal * n;
			dtotal = dtotal * d;
			printf("new totals %d/%d\n", ntotal, dtotal);
		}
	}
	// output the result before the reduction
	printf("answer before simplification is %d/%d.\n", ntotal, dtotal);
	// reduce the total numerator and denominator
	reduce(&ntotal, &dtotal);
	// output the result
	printf("the answer is %d/%d.\n", ntotal, dtotal);
}

// function to check the equivalence cases
int check(int numerator, int denominator) {
	// get the digits of the numerator
	int *ndigits = (int *) malloc (2 * sizeof(int));
	ndigits[1] = numerator % 10;
	ndigits[0] = (numerator / 10) % 10;
	// get the digits of the denominator
	int *ddigits = (int *) malloc (2 * sizeof(int));
	ddigits[1] = denominator % 10;
	ddigits[0] = (denominator / 10) % 10;
	// go through the digits of the numerator
	int ndigit = 0, ddigit = 0;
	for (int i = 0; i < 2; i ++) {
		// go through the digits of the denominator
		for (int j = 0; j < 2; j ++) {
			// check if the digits are equivalent
			if (ndigits[i] != ddigits[j]) continue;
			// if they are equivalent, set them as the digits
			ndigit = ndigits[1 - i];
			ddigit = ddigits[1 - j];
		}
	}
	// check if no digits were found
	if (ndigit == 0 || ddigit == 0) return 0;
	if (ndigit >= ddigit) return 0;
	// otherwise check if they are equivalent
	if ((ndigit * denominator) == (ddigit * numerator)) return 1;
	// return false if none of the conditions were met
	return 0;
}

// function to reduce a fraction
void reduce(int *numerator, int *denominator) {
	// fraction is less than one, use denominator as largest term
	for (int n = 2; n * n <= *denominator; n ++) {
		// check if the numerator and denominator are divisible
		if (*numerator % n != 0 || *denominator % n != 0) continue;
		// if they are, modify the numerator and denominator
		*numerator = *numerator / n;
		*denominator = *denominator / n;
		// if a factor is found, deincrement the iterator
		n = n - 1;
	}
}
