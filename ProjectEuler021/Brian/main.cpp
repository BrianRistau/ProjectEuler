// Let d(n) be defined as the sum of proper divisors of n (numbers less than
// n which devide evenly into n).
// If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair
// and each of a and b are called amicable numbers.
//
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 20, 22, 44, 55,
// and 110; therefore d(220) = 284.  The proper divisors of 284 are 1, 2, 4,
// 71, and 142; so d(284) = 220.
//
// Evaluate the sum of all of the amicable numbers under 10000.

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int divisorSum(int num);

// program entry point
int main(int argc, char **argv) {

	// allocate memory for a digit array
	int *arr = (int *) malloc (20000 * sizeof(int));
	for (int i = 0; i < 20000; i ++) arr[i] = 0;
	// loop through all of the numbers in the designated range
	int sum1, sum2;
	for (int i = 0; i < 10000; i ++) {
		// check if the number has already been computed
		if (arr[i] != 0) continue;
		// get the divisor sum for the number
		sum1 = divisorSum(i);
		// check the range on the divisor sum
		if (sum1 == i) continue;
		if (sum1 > 19999) continue;
		// check if the divisor sum has already been computed
		if (arr[sum1] != 0) {
			// make the array index -1 to indicate not amicable
			arr[i] = -1;
		}
		// get the divisor sum for the current divisor sum
		sum2 = divisorSum(sum1);
		// check the range on the divisor sum
		if (sum2 > 19999) {
			// make the array index -1 to indicate not amicable
			arr[i]    = -1;
			arr[sum1] = -1;
		}
		// check if the numbers are not amicable
		if (sum2 != i) {
			// make the array index -1 to indicate not amicable
			arr[i]    = -1;
		} else {
			// make the array index with their values for amicable
			arr[i]    = i;
			arr[sum1] = sum1;
		}
	}
	// loop through all of the numbers and compute the end sum
	int total = 0;
	for (int i = 0; i < 10000; i ++) {
		// check if the number is an amicable number
		if (arr[i] != -1) total = total + arr[i];
	}
	// output the result
	printf("the answer is %d.\n", total);
}

// function to return the divisor sum of the current number
int divisorSum(int num) {
	// running total for the digit sum
	int sum = 1;
	// loop through all of the numbers up to the square root
	for (int i = 2; i * i <= num; i ++) {
		// check if the number is a perfect square root
		if (i * i == num) {
			sum = sum + i;
		}
		// check if the number is a non-perfect divisor
		else if (num % i == 0) {
			sum = sum + i;
			sum = sum + (num / i);
		}
	}
	// return the digit sum to the user
	return sum;
}
