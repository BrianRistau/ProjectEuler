// If the numbers 1 to 5 are written out in words:
//   one, two, three, four, five
// then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//
// If all the numbers fromm 1 to 1000 (one thousand) inclusive were written
// out in words, how many letters would be used?

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int enumerate(int num);

// program entry point
int main(int argc, char **argv) {

	// calculate the sum of all of the "words"
	int total = 0;
	for (int i=0; i<=1000; i++) {
		total += enumerate(i);
	}

	// output the answer
	printf("the answer is %d.\n", total);

}

// arrays to assist the enumerate function
int ones[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
int tens[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
// function to convert the number to the amount of letters
int enumerate(int num) {

	// handle if the number is between 1 and 9
	if (num >= 0 && num < 10) return ones[num];
	// handle if the number is between 10 and 19
	if (num >= 10 && num < 20) {
		if (num == 10) return 3;
		if (num == 11) return 6;
		if (num == 12) return 6;
		if (num == 13) return 8;
		if (num == 14) return 8;
		if (num == 15) return 7;
		if (num == 16) return 7;
		if (num == 17) return 9;
		if (num == 18) return 8;
		if (num == 19) return 8;
	}
	// handle if the number is between 20 and 99
	if (num >= 20 && num < 100) {
		return (tens[num/10] + ones[num%10]);
	}
	// handle if the number is between 100 and 999
	if (num >= 100 && num < 1000) {
		// calculate the "hundred [and]"
		int temp = 10;
		if (num % 100 == 0) temp = 7;
		// recursively calculate the solution
		return enumerate(num/100) + temp + enumerate(num%100);
	}
	// handle if the number is 1000
	if (num == 1000) return 11;

}
