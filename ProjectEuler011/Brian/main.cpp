// In the 20x20 grid below, four numbers along a diagonal line have been
// marked in red.
//
//   08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
//   49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
//   81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
//   52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
//   22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
//   24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
//   32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
//   67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
//   24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
//   21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
//   78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
//   16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
//   86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
//   19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
//   04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
//   88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
//   04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
//   20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
//   20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
//   01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
//
// The product of these numbers is 26 x 63 x 78 x 14 = 1788696.
//
// What is the greatest product of four adjacent numbers in the same
// direction (up, down, left, right, or diagonally) in the 20x20 grid?

#include <stdio.h>
#include <stdlib.h>

#define WIDTH  20
#define HEIGHT 20
#define LENGTH 4

// function prototypes
void readGrid(const char *name, int **arr);
int checkDirections(int x, int y, int **arr);
int checkHorizontals(int x, int y, int **arr);
int checkVerticals(int x, int y, int **arr);
int checkDiagonals(int x, int y, int **arr);

// program entry point
int main(int argc, char **argv) {

	// allocate memory in an array to hold each row of the grid
	int **arr = (int **) malloc (HEIGHT * sizeof(int *));
	// allocate memory for the cells of each row
	for (int i = 0; i < HEIGHT; i ++) {
		*(arr + i) = (int *) malloc (WIDTH * sizeof(int));
	}

	// read the grid from the file
	readGrid("grid.file", arr);

	// iterate through all array indices
	int temp, max = 0;
	for (int y = 3; y < 17; y ++) {
		for (int x = 3; x < 17; x ++) {
			temp = checkDirections(x, y, arr);
			max = (temp > max) ? temp : max;
		}
	}

	// output the result
	printf("the answer is %d.\n", max);


}

// function to read the contents of the grid from a file
void readGrid(const char *name, int **arr) {

	// open the file
	FILE *fp = fopen(name, "rb");
	int row = 0, col = 0;

	// loop through the contents of the file
	int carry, next; 
	while (1) {

		// get the next character from the file
		next = fgetc(fp);

		// check if the end of file was reached
		if (next == EOF) break;
		// check if a space character was reached
		if (next == 0x20) {
			// finalize the value that is in the carry variable
			arr[row][col] = carry;
			carry = 0;
			// modify the index variables
			col += 1;
		}
		// check if a newline character was reached
		if (next == 0x0A) { 
			// finalize the value that is in the carry variable
			arr[row][col] = carry;
			carry = 0;
			// modify the index variables
			col = 0; row += 1;
		}
		// check if a numeric character is reached
		if (next > 0x2F && next < 0x3A) {
			// add the new character to the carry variable
			carry = (carry * 10) + (next - 0x30);
		}

	}

}

// function to check all of the directions under facade design
int checkDirections(int x, int y, int **arr) {
	// check the horizontal direction values
	int max = checkHorizontals(x, y, arr);
	// compare against the vertical direction values
	int temp = checkVerticals(x, y, arr);
	max = (temp > max) ? temp : max;
	// compare against the diagonal direction values
	temp = checkDiagonals(x, y, arr);
	return (temp > max) ? temp : max;
}

// function to check the horizontals off the current coordinates
int checkHorizontals(int x, int y, int **arr) {

	// variable to hold the maximum of the current criteria
	int temp, max = 0;

	// check the left horizontal direction
	if ((x - (LENGTH - 1)) >= 0) {
		temp = arr[y][x-3] * arr[y][x-2] *
		  arr[y][x-1] * arr[y][x];
		max = (temp > max) ? temp : max;
	}

	// check the right horizontal direction
	if ((x + LENGTH) < WIDTH) {
		temp = arr[y][x+3] * arr[y][x+2] *
		  arr[y][x+1] * arr[y][x];
		max = (temp > max) ? temp : max;
	}

	// return the calculated maximum
	return max;

}

// function to check the verticals off the current coordinates
int checkVerticals(int x, int y, int **arr) {

	// variable to hold the maximum of the current criteria
	int temp, max = 0;

	// check the up vertical direction
	if ((y - (LENGTH - 1)) >= 0) {
		temp = arr[y-3][x] * arr[y-2][x] *
		  arr[y-1][x] * arr[y][x];
		max = (temp > max) ? temp : max;
	}

	// check the down vertical direction
	if ((y + LENGTH) < HEIGHT) {
		temp = arr[y+3][x] * arr[y+2][x] *
		  arr[y+1][x] * arr[y][x];
		max = (temp > max) ? temp : max;
	}

	// return the calculated maximum
	return max;

}

// function to check the diagonals off the current coordinates
int checkDiagonals(int x, int y, int **arr) {

	// variable to hold the maximum of the current criteria
	int temp, max = 0;

	// check the up-left direction
	if ((y - (LENGTH - 1)) >= 0 && (x - (LENGTH - 1)) >= 0) {
		temp = arr[y-3][x-3] * arr[y-2][x-2] *
		  arr[y-1][x-1] * arr[y][x];
		max = (temp > max) ? temp : max;
	}

	// check the down-left direction
	if ((y + LENGTH) < HEIGHT && (x - (LENGTH - 1)) >= 0) {
		temp = arr[y+3][x-3] * arr[y+2][x-2] *
		  arr[y+1][x-1] * arr[y][x];
		max = (temp > max) ? temp : max;
	}

	// check the up-right direction
	if ((y - (LENGTH - 1)) >= 0 && (x + LENGTH) < WIDTH) {
		temp = arr[y-3][x+3] * arr[y-2][x+2] *
		  arr[y-1][y+1] * arr[y][x];
		max = (temp > max) ? temp : max;
	}

	// check the down-right direction
	if ((y + LENGTH) < HEIGHT && (x + LENGTH) < WIDTH) {
		temp = arr[y+3][x+3] * arr[y+2][x+2] *
		  arr[y+1][x+1] * arr[y][x];
		max = (temp > max) ? temp : max;
	}

	// return the calculated value
	return max;

}
