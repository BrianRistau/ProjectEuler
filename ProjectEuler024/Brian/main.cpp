// A permutation is an ordered arrangement of objects.  For example, 3124 is
// possible permutation of the digits 1, 2, 3, and 4.  If all of the
// permutations are listed numerically or alphabetically, we call it
// lexicographic order.  The lexicographic permutations of 0, 1, and 2, are:
//
//   012, 021, 102, 120, 201, 210
//
// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3,
// 4, 5, 6, 7, 8, and 9?

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

// program entry point
int main(int argc, char **argv) {
	
	// create an array to hold all of the numbers to permutate
	int count = 0, nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// enter a loop while the millionth permutation is not yet reached
	while ((++ count) < 1000000) {
		std::next_permutation(nums, nums + 10);
	}
	// output the result
	printf("the answer is ");
	for (int i = 0; i < 10; i ++) printf("%d", nums[i]);
	printf(".\n");

}
