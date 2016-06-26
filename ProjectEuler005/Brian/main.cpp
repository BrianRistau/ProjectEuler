// 2520 is the smallest number the can be divided by each of the
// numbers from 1 to 10 without any remainder.
//
// What is the smallest positive number that is evenly divisible
// by all of the numbers from 1 to 20?

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// function prototypes
int divisible(int num);

// program entry point
int main(int argc, char **argv) {

	// loop until an answer is found
	int iterator = 2520;
	while (1) {
		// break until a number is found
		if (divisible(iterator)) break;
		iterator += 10;
	}

	// output the answer
	printf("the answer is %d.\n", iterator);

}

// function to determine if number is evenly divisible from 1-20
int vals = 8, arr[] = { 11, 13, 14, 16, 17, 18, 19, 20 };
int divisible(int num) {

	// loop through all of the necessary values
	for (int i = 0; i < 7; i ++) {
		// return false if a factor is found
		if (num % arr[i] != 0) return 0;
	}

	// return true if no factors values have been found
	return 1;
}
