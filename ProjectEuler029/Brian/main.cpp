// Consider all integer combinations of a^b for 2 <= a <= 5 and 2 <= b <= 5:
//
//   2 ^ 2 = 4,  2 ^ 3 = 8,   2 ^ 4 = 16,  2 ^ 5 = 32
//   3 ^ 2 = 9,  3 ^ 3 = 27,  3 ^ 4 = 81,  3 ^ 5 = 243
//   4 ^ 2 = 16, 4 ^ 3 = 64,  4 ^ 4 = 256, 4 ^ 5 = 1024
//   5 ^ 2 = 25, 5 ^ 3 = 125, 5 ^ 4 = 625, 5 ^ 5 = 3125
//
// If they are then placed in numerical order, with any repeats removed, we
// get the following sequence of items of 15 distinct terms:
//
//   4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125
//
// How many distinct terms are in the sequence generated by a^b for
// 2 <= a <= 100 and 2 <= b <= 100

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void mergesort(double *arr, int size);
void merge(double *arr, double *left, int lsize, double *right, int rsize);

// program entry point
int main(int argc, char **argv) {

	// loop through the base numbers
	int amount = 0;
	double elements[10000];
	for (double i = 2; i < 101; i ++) {
		// loop through the exponent numbers
		for (double j = 2; j < 101; j ++) {
			// set the ith element
			elements[amount] = pow(i, j);
			amount = amount + 1;
		}
	}
	// sort the elements in the array
	mergesort(elements, amount);
	// check for any duplicate elements
	int count = amount;
	for (int i = 1; i < amount; i ++) {
		// handle if a duplicate element was found
		if (elements[i] == elements[i-1]) count = count - 1;
	}
	// output the number of unique elements
	printf("the answer is %d.\n", count);

}

// function to perform mergesort on an array
void mergesort(double *arr, int size) {

	// check the base condition of mergesort
	if (size < 2) return;
	// get the middle index of the array
	int mid = size / 2;

	// create the right and left subarrays
	double *left  = (double *) malloc (        mid  * sizeof(double));
	double *right = (double *) malloc ((size - mid) * sizeof(double));
	// move the elements into the proper array
	for (int i = 0  ; i < mid ; i ++) left[i]  = arr[i];
	for (int i = mid; i < size; i ++) right[i - mid] = arr[i];
	// perform recursive mergesort on the left and right subarrays
	mergesort(left, mid);
	mergesort(right, size - mid);
	// merge these two arrays together
	merge(arr, left, mid, right, size - mid);
	// free the memory used by the temporary arrays
	free(left); free(right);

}

// function to merge two arrays into a larger array
void merge(double *arr, double *left, int lsize, double *right, int rsize) {

	// index markers for the three arrays
	int aindex = 0, lindex = 0, rindex = 0;
	// loop while one of the arrays is not fully exhausted
	while (lindex < lsize && rindex < rsize) {
		// handle if the left element is less than the right element
		if (left[lindex] < right[rindex])
			arr[aindex ++] = left[lindex ++];
		// handle if the right element is less than the left element
		else arr[aindex ++] = right[rindex ++];
	}
	// clean up any remaining array elements
	while (lindex < lsize) arr[aindex ++] = left[lindex ++];
	while (rindex < rsize) arr[aindex ++] = right[rindex ++];

}
