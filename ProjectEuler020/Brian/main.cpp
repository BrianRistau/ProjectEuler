// n! means n * (n-1) * ... * 3 * 2 * 1
//
// For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800, and the sum
// of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27
//
// Find the sum of the digits in the number 100!

#include <stdio.h>
#include <stdlib.h>

#define DIGITS 1000

// struct for processing the big numbers
typedef struct bignum_t {
	int value[DIGITS];
} bignum_t;

// function prototypes
void bigMultiply(bignum_t *bignum, int multiplicand);

// program entry point
int main(int argc, char **argv) {

	// create a bignum struct for holding the running product
	bignum_t *product = (bignum_t *) malloc (sizeof(bignum_t));
	for (int i = 0; i < DIGITS; i ++) product->value[i] = 0;
	product->value[DIGITS - 1] = 1;

	// iterate through the numbers to compute the factorial
	for (int i = 100; i > 1; i --) {
		bigMultiply(product, i);
	}

	// iterate through the numbers and compute the digit sum
	int digitSum = 0;
	for (int i = 0; i < DIGITS; i ++) digitSum += product->value[i];
	printf("the answer is %d.\n", digitSum);

}

// function to multiply the big number
void bigMultiply(bignum_t *bignum, int multiplicand) {

	// iterate through all of the digits and perform multiplication
	int carry = 0, temp;
	for (int i = DIGITS - 1; i >= 0; i --) {
		// perform the multiplication and store the result in a buffer
		temp = (bignum->value[i] * multiplicand) + carry;
		// separate the components of the product
		bignum->value[i] = temp % 10;
		carry = temp / 10;
	}

}
