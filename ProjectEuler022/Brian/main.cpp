// Using names.txt, a 46k text file containing over five-thousand first names,
// begin by sorting it into alphabetical order.  Then working out the
// alphabetical value for each name, multiply this value by its alphabetical
// position in the list to obtain a name score.
//
// For example, when the list is sorted into alphabetical order, COLIN, which
// is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.  So
// COLIN would obtain a score of 938 x 53 = 49714.
//
// What is the total of all the name scores in the file?

#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX 12

// function prototypes
int countEntries(const char *name);
void readNames(const char *name, char **buf);
void mergeSort(char **arr, int n);
void merge(char **arrA, char **left, int lsize, char **right, int rsize);
int compare(char *stra, int asize, char *strb, int bsize);

// program entry point
int main(int argc, char **argv) {

	// get the number of entries and allocate a memory space for this data
	int entries = countEntries("names.txt");
	char **names = (char **) malloc (entries * sizeof(char *));
	for (int i = 0; i < entries; i ++)
		names[i] = (char *) malloc (12 * sizeof(char));

	// read the contents of the file
	readNames("names.txt", names);
	// sort the names in the file in alphabetical order
	mergeSort(names, entries);

	// now that the names are in alphabetical order, get the name sum
	long int total = 0;
	// loop through all of the names
	for (int i = 0; i < entries; i ++) {
		// loop through each letter in the name
		long unsigned wtotal = 0;
		for (int j = 0; j < NAME_MAX; j ++) {
			// check if the current character is null
			if (names[i][j] == 0x00) break;
			// otherwise add the letter to the word total
			wtotal = wtotal + (names[i][j] - 0x40);
		}
		// multiply this value by the name index
		
		total = total + (wtotal * (i + 1));
	}

	// output the answer
	printf("the answer is %ld\n", total);

}

// function to determine the number of entries in the name list
int countEntries(const char *name) {

	// open the file for reading
	FILE *fp = fopen(name, "rb");
	// loop through the contents of the file, counting the commas
	int next, entries = 1;
	while (1) {
		// get the next character from the file
		next = fgetc(fp);
		// check if the end of file was reached
		if (next == EOF) break;
		// check if a comma character was reached
		if (next == 0x2C) entries = entries + 1;
	}
	// return the number of entries
	fclose(fp);
	return entries;

}

// function to read all of the names from the file
void readNames(const char *name, char **buf) {

	// open the file for reading
	FILE *fp = fopen(name, "rb");
	// loop through the file contents, reading in the names
	int next, row = 0, col = 0, nflag = 0;
	while (1) {
		// get the next character from the file
		next = fgetc(fp);
		// check if the end of file was reached
		if (next == EOF) break;
		// check if a quotation mark character was reached
		if (next == 0x22) {
			// invert the name reading flag
			nflag = !nflag;
			// if the name reading flag is now 1, reset variables
			if (nflag) {
				col = 0;
			// otherwise increment the row count
			} else {
				buf[row][col] = 0x00;
				row = row + 1;
			}
		}
		// check if an alphanumeric character was reached
		if (next > 0x40 && next <= 0x5A) {
			// check if the flag is not set (should never happen)
			if (!nflag) continue;
			// read the character into the specified index
			buf[row][col] = next;
			// increment the column count
			col = col + 1;
		}
	}
	// close the file
	fclose(fp);

}

// function to perform mergesort on the specified array
void mergeSort(char **arr, int n) {

	// check the mergesort base condition
	if (n < 2) return;

	// get the middle index of the array
	int mid = n / 2;
	// create subarrays for the left and right sides of the array
	char **left  = (char **) malloc (     mid  * sizeof(char *));
	char **right = (char **) malloc ((n - mid) * sizeof(char *));
	
	// copy the elements to the left array
	for (int i = 0; i < mid;  i ++) {
		left[i] = (char *) malloc (NAME_MAX * sizeof(char));
		for (int j = 0; j < NAME_MAX; j ++)
			left[i][j] = arr[i][j];
	}
	// copy the elements to the right array
	for (int i = mid; i < n; i ++) {
		right[i - mid] = (char *) malloc (NAME_MAX * sizeof(char));
		for (int j = 0; j < NAME_MAX; j ++)
			right[i - mid][j] = arr[i][j];
	}

	// recursively perform mergesort on the subarrays until base case
	mergeSort(left,      mid);
	mergeSort(right, n - mid);
	// merge the two arrays
	merge(arr, left, mid, right, n - mid);

	// free the memory used by the subarrays
	free(left);
	free(right);

}

// function to merge two arrays into a target array
void merge(char **arr, char **left, int lsize, char **right, int rsize) {

	// index variables for the three arrays
	int apos = 0, lpos = 0, rpos = 0;
	// enter loop to sort until one of the subarrays has been exhausted
	while (lpos < lsize && rpos < rsize) {
		// add in the smallest element from the arrays
		if (compare(left[lpos], NAME_MAX, right[rpos], NAME_MAX) == -1) 
		  arr[apos++] = left[lpos++];
		else arr[apos++] = right[rpos++];
	}

	// add in any remaining elements from the left array
	while (lpos < lsize) arr[apos++] = left[lpos++];
	// add in any remaining elements from the right array
	while (rpos < rsize) arr[apos++] = right[rpos++];

}

// function to compare two character array strings
// returns 1 if a is greater than b
//         0 if a is equal to b
//        -1 if b is equal to a
int compare(char *stra, int asize, char *strb, int bsize) {

	// loop through the elements of the two strings
	for (int i = 0; i < (asize < bsize) ? asize : bsize; i ++) {
		// catch any letters that not the same
		if (stra[i] < strb[i]) return -1;
		if (stra[i] > strb[i]) return 1;
	}

	// handle the equivalent cases
	if (asize == bsize) return 0;
	return (asize > bsize) ? 1 : -1;

}
