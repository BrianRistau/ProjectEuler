// The Fibonacci sequence is defined by the recurrence relation:
//   F(n) = F(n-1) + F(n-2), where F(1) = 1 and F(2) = 1
//
// Hence the first 12 terms will be
//   F(1)  = 1
//   F(2)  = 1
//   F(3)  = 2
//   F(4)  = 3
//   F(5)  = 5
//   F(6)  = 8
//   F(7)  = 13
//   F(8)  = 21
//   F(9)  = 34
//   F(10) = 55
//   F(11) = 89
//   F(12) = 144
//
// The 12th term, F(12), is the first terms to contain three digits.
//
// What is the index of the first term in the Fibonacci sequence to contain
// 1000 digits?

#include <stdio.h>
#include <stdlib.h>

// struct for holding many digit numbers
#define LENGTH 1000
typedef struct bignum_t {
	char digits[LENGTH];
} bitnum_t;

// function prototypes
void bignum_init(bignum_t *a);
void bignum_copy(bignum_t *a, bignum_t *b);
void bignum_add(bitnum_t *a, bignum_t *b, bignum_t *c);

// program entry point
int main(int argc, char **argv) {

	// create two bignum_t entities for fibonacci calculation
	bignum_t bigfib1, bigfib2, temp;
	bignum_init(&bigfib1);
	bignum_init(&bigfib2);
	bignum_init(&temp);
	bigfib1.digits[LENGTH - 1] = 1;
	bigfib2.digits[LENGTH - 1] = 1;

	// loop until a fibonacci number with 1000 digits is found
	int index = 2; while (1) {
		// get the next fibonacci number in the sequence
		bignum_add(&bigfib1, &bigfib2, &temp);
		// update the index variable
		index = index + 1;
		// check if this number is within acceptable bounds
		if (temp.digits[0] > 0) break;
		// otherwise, setup the bignums to get the next number
		bignum_copy(&bigfib1, &bigfib2);
		bignum_copy(&temp, &bigfib1);
	}

	// output the solution
	printf("the answer is %d.\n", index);

}

// function to initialize a bignum
void bignum_init(bignum_t *a) {
	// set all of the digits equal to zero
	for (int i = 0; i < LENGTH; i ++) a->digits[i] = 0;
}

// function to copy bignum a to bignum b
void bignum_copy(bignum_t *a, bignum_t *b) {
	// copy each index of a to b
	for (int i = 0; i < LENGTH; i ++) {
		b->digits[i] = a->digits[i];
	}
}

// function to add together two bignums
void bignum_add(bignum_t *a, bignum_t *b, bignum_t *c) {
	// iterate backward through the bignum
	char temp, carry = 0; for (int i = LENGTH - 1; i >= 0; i --) {
		// calculate the sum of the current digits
		temp = a->digits[i] + b->digits[i] + carry;
		// set the digits in the bignum to hold the sum
		c->digits[i] = temp % 10;
		carry = temp / 10;
	}
}
