// In England the currency is made up of pound, £, and pence, p, and there
// are eight coins in general circulation.
//
//   1p, 2p, 5p, 10p, 20p, 50p, £1, and £2.
//
// It is possible to make £2 the following way:
//
//   1x£1 + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p
//
// How many different ways can £2 be made using any number of coins?

#include <stdio.h>
#include <stdlib.h>

// function prototypes
int coinsum(int target);

// program entry point
int main(int argc, char **argv) {

	// get the total number of coin sums
	int total = coinsum(200);
	// output the result
	printf("the answer is %d.\n", total);

}

// function to determine the number of coin sums
int coinsum(int target) {
	// please don't kill me
	int count = 0;
	for (int a = target; a >= 0; a -= 200) {
	 for (int b = a; b >= 0; b -= 100) {
	  for (int c = b; c >= 0; c -= 50) {
	   for (int d = c; d >= 0; d -= 20) {
	    for (int e = d; e >= 0; e -= 10) {
	     for (int f = e; f >= 0; f -= 5) {
	      for (int g = f; g >= 0; g -= 2) {
	       count = count + 1;
	      }
	     }
	    }
	   }
	  }
	 }
	}
	// return the count and never write code again
	return count;
}
