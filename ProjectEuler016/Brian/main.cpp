// 2^15 = 32768 and the sum of its digits is
//   3 + 2 + 7 + 6 + 8 = 26.
//
// What is the sum of the digits of the number 2^1000?

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

// function prototypes
void bigMultiply(int *digits, int multiplicand);
void test(int num, int *digits);

// program entry point
int main(int argc, char **argv) {

	// allocate memory for the digits of the number
	int *digits = (int *) malloc (SIZE * sizeof(int) + 1);
	for (int i=0; i<SIZE; i++) digits[i] = 0;
	digits[SIZE - 1] = 1;

	// calculate the 1000th power of the number
	for (int i=0; i<1000; i++) {
		bigMultiply(digits, 2);
	}

	// output the solution
	int total = 0;
	for (int i = 0; i < SIZE; i++) {
		total += digits[i];
	}
	printf("the answer is %d.\n", total);

}

// method to multiply the number
void bigMultiply(int *digits, int multiplicand) {

	// iterate through all of the digits and perform multiplication
	int carry = 0, temp;
	for (int i = SIZE - 1; i >= 0; i --) {
		temp = (digits[i] * 2) + carry;
		digits[i] = temp % 10;
		carry = temp / 10;
	}

}
