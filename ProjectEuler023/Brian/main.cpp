// A perfect number is a number for which the sum of its proper divisors is
// exactly equal to the number.  For example, the sum of the proper divisors
// of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect
// number.
//
// A number n is called deficient if the sum of its proper divisors is less
// than n and it is called abundant if this sum exceeds n.
//
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
// number that can be written as the sum of two abundant numbers is 24.  By
// mathematical analysis, it can be shown that all integers greater than 28123
// can be written as the sum of two abundant numbers.  However, this upper
// limit cannot be reduced any further by analysis even though it is known
// that the greatest number that cannot be expressed as the sum of two
// abundant numbers is less than this limit.
//
// Find the sum of all the positive integers which cannot be written as the
// sum of two abundant numbers.

#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 28124

// function prototypes
int dsum(int num);
int abundant(int num);

// program entry point
int main(int argc, char **argv) {

	// arrays for the list of abundant numbers and sums
	int nums[MAXIMUM]; int sums[MAXIMUM] = {0};
	
	// figure out the abundant numbers
	int iter = 0; for (int i = 0; i < MAXIMUM; i ++) {
		// add the number to the list of abundant numbers if abundant
		if (abundant(i)) nums[iter ++] = i;
	}

	// figure out which numbers can be represented as abundant number sums
	for (int i = 0; i < iter; i ++) {
		// loop through the second set of digits
		for (int j = i; j < iter; j ++) {
			// check if the sum is within bounds
			if (nums[i] + nums[j] < MAXIMUM) {
				// set the proper index as "summable"
				sums[nums[i] + nums[j]] = 1;
			}
		}
	}

	// get the sum of all the non-summable numbers
	int total = 0;
	for (int i = 0; i < MAXIMUM; i ++) {
		if (!sums[i]) total = total + i;
	}

	// output the total
	printf("the answer is %d.\n", total);

}

// function to return the proper divisor sum of the given number
int dsum(int num) {
	// keep a running total of the divisor sum
	int sum = 0;
	for (int i = 2; i * i <= num; i ++) {
		// check whether or not the number is evenly divisible
		if (num % i == 0) {
			// add the current number to the running sum
			sum = sum + i;
			// check if the sum has a complement
			if (i < (num / i)) sum = sum + (num / i);
		}
	}
	// return the divisor sum
	return sum;
}

// function to return whether or not the number is abundant
int abundant(int num) {
	return (num < dsum(num)) ? 1 : 0;
}
