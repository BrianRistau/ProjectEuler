// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
//
// Find the sum of all numbers which are equal to the sum of the factorial
// of their digits.
//
// Note: As 1! = 1 and 2! = 2 are not sums they are not included.

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int factorial(int number);
int digitfsum(int number);
int digitize(int number, int *buffer);

// program entry point
int main(int argc, char **argv) {
	// start at 100... probably not any numbers under that... right?
	int sum = 0;
	for (int i = 1e2; i < 1e6; i ++) {
		// add to the sum if cool enough
		if (i != digitfsum(i)) continue;
		sum = sum + i;
	}
	// output the answer
	printf("the answer is %d\n", sum);
}

// recursive function to compute the factorial
int factorial(int number) {
	// check the base cases of the number
	if (number < 2) return 1;
	// return the recursive factorial
	else return number * factorial(number - 1);
}

// function to get the digit factorial sum of the current number
int digitfsum(int number) {
	// establish a buffer and get the number in digit form
	int *buf = (int *) malloc (8 * sizeof(int));
	for (int i = 0; i < 8; i ++) buf[i] = 0;
	int digits = digitize(number, buf);
	// calculate the factorial sum of each digit
	int sum = 0;
	for (int i = 7; i >= 8 - digits; i --)
		sum = sum + factorial(buf[i]);
	// return the factorial sum
	return sum;
}

// function to convert the number to a string of digits
int digitize(int number, int *buf) {
	// loop through the digits of the number (all 8)
	int digits = 1;
	for (; digits <= 8; digits ++) {
		// set the current digit from the number
		buf[8 - digits] = number % 10;
		// change the number to get the next digit
		number = number / 10;
		// check if the number is not zero. if not, increment
		if (number == 0) break;
	}
	return digits;
}
