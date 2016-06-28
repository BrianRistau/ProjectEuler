// By starting at the top of the triangle below and moving to adjacent numbers
// on the row below, the maximum total from top to bottom is 23.
//
//                                 3
//                                7 4
//                               2 4 6
//                              8 5 9 3
//
// That is, 3 + 7 + 4 + 9 = 23.
//
// Find the maximum total from top to bottom of the triangle below.
//
//                                75
//                              95  64
//                            17  47  82
//                               ....

#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 15

// function prototypes
void readTriangle(const char *name, int **triangle);

// program entry point
int main(int argc, char **argv) {

	// allocate memory to hold the triangle values
	int **triangle = (int **) malloc (HEIGHT * sizeof(int *));
	for (int i=0; i<HEIGHT; i++) {
		triangle[i] = (int *) malloc ((i + 1) * sizeof(int));
	}

	// read the contents of the triangle from the file
	readTriangle("triangle", triangle);

	// loop through each row of the triangle
	for (int i = (HEIGHT - 2); i >= 0; i --) {
		// iterate through each element of the row
		for (int j = 0; j <= i; j ++) {
			triangle[i][j] =
			  // check whether the right or left child is greater
			  (triangle[i+1][j] > triangle[i+1][j+1]) ?
			    // add to the left child if it is greater
			    triangle[i][j] + triangle[i+1][j] :
			    // add to the right child if it is greater
			    triangle[i][j] + triangle[i+1][j+1];
		}
	}

	// output the solution
	printf("the answer is %d.\n", triangle[0][0]);

}

// function to read in the data from the file
void readTriangle(const char *name, int **triangle) {

	// open the file for reading
	FILE *fp = fopen(name, "rb");

	// enter a loop to read the numers of the triangle
	int next, carry = 0, row = 0, col = 0;
	while (1) {

		// get the next character from the file
		int next = fgetc(fp);

		// check if the end-of-file was reached
		if (next == EOF) {
			// commit the current number to the triangle (if > 0)
			if (carry != 0) triangle [row][col] = carry;
			break;
		}

		// check if a newline character was reached
		if (next == 0x0A) {
			// commit the current number to the triangle
			triangle[row][col] = carry;
			// reset the carry and column and increment the row
			carry = 0; col = 0;
			row += 1;
		}

		// check if a space character was reached
		if (next == 0x20) {
			// commit the current number to the triangle
			triangle[row][col] = carry;
			// reset the carry and increment the column
			carry = 0; col += 1;
		}

		// check if a numeric character was reached
		if (next > 0x2F && next < 0x3A) {
			carry = (carry * 10) + (next - 0x30);
		}

	}

	// close the file stream
	fclose(fp);

}
