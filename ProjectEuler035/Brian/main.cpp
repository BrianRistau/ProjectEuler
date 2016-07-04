// The number, 197, is called a circular prime because all rotations of the
// digits: 197, 971, and 719 are themselves prime.
//
// There are thirteen such primes below 100: 2, 3, 4, 5, 7, 11, 13, 17, 31,
// 37, 71, 73, 97, and 79.
//
// How many circular primes are there below one million?

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int isprime(int num); 
int digitize(int num, int *buf);
int rotate(int *buf, int len);
int circular(int num);

// program entry point
int main(int argc, char **argv) {
	// loop through all of the potential numbers
	int count = 0;
	for (int i = 2; i < 1000000; i ++) {
		// increment the count if a circular prime is found
		if (!circular(i)) continue;
		count = count + 1;
	}
	// output the number of circular primes
	printf("the answer is %d\n", count);
}

// function to check if the current number is a circular prime
int circular(int num) {
	// create a buffer and digitize the number
	int *buf = (int *) malloc (8 * sizeof(int));
	int count = digitize(num, buf);
	// go through all the digit permutations and check primality
	for (int i = 0; i < count; i ++) {
		// rotate the current set of digits
		int number = rotate(buf, count);
		// check if the number is prime, if not return false
		if (!isprime(number)) return 0;
	}
	// return true if all the digit rotations were prime
	return 1;
}

// function to rotate the current buffer and return it in numerical form
int rotate(int *buf, int len) {
	// go through each of the digits in the buffer
	int temp = buf[7];
	for (int i = 1; i < len; i ++) {
		// move the digit once to the right
		buf[8 - i] = buf[8 - (i + 1)];
	}
	// add the original last digit to the front
	buf[8 - len] = temp;
	// compute the number to return
	int num = 0;
	for (int i = 8 - len; i < 8; i ++) {
		// shift the digits left and add the next last digit
		num = (num * 10) + buf[i];
	}
	// return the number in decimal form
	return num;
}

// function to digitize the current number
int digitize(int num, int *buf) {
	// loop through all of the numbers digits
	int digits = 1;
	for (; digits < 8; digits ++) {
		// get the next digit to store in the buffer
		buf[8 - digits] = num % 10;
		// compute the next number to pull digits from
		num = num / 10;
		// exit the loop if the number is exhausted
		if (num == 0) break;
	}
	// return the number of digits in the number
	return digits;
}

// function to determine whether a number is prime
int isprime(int num) {
	// check the base cases
	if (num == 1) return 0;
	if (num == 2 || num == 3) return 1;
	// check the multiples of two
	if (num % 2 == 0) return 0;
	// iterate through all possible numbers
	for (int i = 3; i * i <= num; i ++) {
		// return false if a divisor is found
		if (num % i == 0) return 0;
	}
	// return true if no issues were found
	return 1;
}
