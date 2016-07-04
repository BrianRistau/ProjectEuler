// The decimal number, 585 = 100100100 (binary), is palindromic in both bases.
//
// Find the sum of all numbers, less than one million, which are palindromic
// in base 10 and base 2.
//
// (Please note that the palindromic number, in either base, may not include
// leading zeros.)

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int palindrome2(int num);
int palindrome10(int num);
int dualpalindrome(int num);

// program entry point
int main(int argc, char **argv) {
	// go through all possible numbers
	int total = 0;
	for (int i = 1; i < 1000000; i ++) {
		if (dualpalindrome(i)) total = total + i;
	}
	// output the solution
	printf("the answer is %d.\n", total);
}

// function to check if the number is a palindrome in both bases
int dualpalindrome(int num) {
	// check if the number is even (never a palindrome)
	if (num % 2 == 0) return 0;
	// otherwise check the binary and decimal palindromes
	return palindrome2(num) && palindrome10(num);
}

// function to check if the number is a palindrome in base 10
int palindrome10(int num) {
	// digitize the number into an array
	int *buf = (int *) malloc (8 * sizeof(int));
	int digits = 1; for (; digits <= 8; digits ++) {
		// get the next digit in the number
		buf[8 - digits] = num % 10;
		num = num / 10;
		// check if the number is done calculating
		if (num == 0) break;
	}
	// iterate from both directions of the number
	for (int i = 0; i < digits; i ++) {
		// check for any non-palindromic indices
		if (buf[(8 - digits) + i] != buf[7 - i]) return 0;
	}
	// return true if no issues were found
	return 1;
}

// function to check if the number is a palindrome in base 2
int palindrome2(int num) {
	// digitize the number into an array
	int *buf = (int *) malloc (32 * sizeof(int));
	int digits = 1; for (; digits <= 32; digits++) {
		// get the last bit in the number
		buf[32 - digits] = num & 0x01;
		num = num >> 1;
		// check if the number is done calculating
		if (num == 0) break;
	}
	// iterate from both directions of the number
	for (int i = 0; i < digits; i ++) {
		// check for any non-palindromic indices
		if (buf[(32 - digits) + i] != buf[31 - i]) return 0;
	}
	// return true if no issues were found
	return 1;
}
