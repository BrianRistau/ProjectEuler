// A palindromic number reads the same both ways.  The largest palindrome
// made from the product of two 2-digit numbers is 9009 = 91 x 99.
//
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

// function prototypes
int palindromic(int num);

// program entry point
int main(int argc, char **argv) {

	// variables to hold the iterating variables and the maximum value
	int a = 101, b = 101;
	int temp, max = 0;

	// loop while a and b are below 999
	while (a <= 999) {

		// check if the given number is palindromic
		temp = a * b;
		if (palindromic(temp)) {
			max = (temp > max) ? temp : max;
		}

		// iterate b, check if is it greater than a
		if ((b += 1) > a) {
			// iterate a, reset b to 101
			a += 1; b = 101;
		}

	}

	// output the value that was found
	printf("the answer is %d.\n", max);

}

// function to check if the specified number is palindromic
int palindromic(int num) {

	// get the number of digits in the number
	int count = ((int) log10((double) num)) + 1;
	
	// allocate a memory bank for the digits of the number
	int *digits = (int *) malloc (count * sizeof(int)),
	  index = count - 1, next;
	while (num != 0) {
		// grab the last digit in the number
		next = num % 10;
		// store it in the memory array
		digits[index] = next;
		// iterate the index iterator, recalculate 
		index -= 1; num /= 10;
	}

	// go through the digits, checking for non-palindromic digits
	int l_index = 0, r_index = count - 1, val = 1;
	do {
		// return false if the corresponding digits are not equivalent
		if (digits[l_index] != digits[r_index]) {
			val = 0; break;
		}
		// iterate the two digit iterators
		l_index += 1; r_index -= 1;
	// loop until the right index is left than the left index
	} while (l_index < r_index);

	// free the memory used by the digit array
	free(digits);
	return val;

}
