// The four adjacent digits in the 1000-digit number that have the
// greatest product are 9 × 9 × 8 × 9 = 5832.
//
//   73167176531330624919225119674426574742355349194934
//   96983520312774506326239578318016984801869478851843
//   85861560789112949495459501737958331952853208805511
//   12540698747158523863050715693290963295227443043557
//   66896648950445244523161731856403098711121722383113
//   62229893423380308135336276614282806444486645238749
//   30358907296290491560440772390713810515859307960866
//   70172427121883998797908792274921901699720888093776
//   65727333001053367881220235421809751254540594752243
//   52584907711670556013604839586446706324415722155397
//   53697817977846174064955149290862569321978468622482
//   83972241375657056057490261407972968652414535100474
//   82166370484403199890008895243450658541227588666881
//   16427171479924442928230863465674813919123162824586
//   17866458359124566529476545682848912883142607690042
//   24219022671055626321111109370544217506941658960408
//   07198403850962455444362981230987879927244284909188
//   84580156166097919133875499200524063689912560717606
//   05886116467109405077541002256983155200055935729725
//   71636269561882670428252483600823257530420752963450
//
// Find the thirteen adjacent digits in the 1000-digit number that have
// the greatest product. What is the value of this product?

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// runtime-exclusive constants
const int num_digits = 1000, length = 13;

// program entry point
int main(int argc, char **argv) {

	// open the file and read in the digits to a buffer
	FILE *fp = fopen("number.file", "rb");
	uint8_t *buf = (uint8_t *) malloc 
	  (num_digits * sizeof(uint8_t));

	// loop through all of the digits in the file
	uint32_t iter = 0, next; while (1) {
		// get the next character in the file
		next = fgetc(fp);
		// check if the end-of-file was reached
		if (next == EOF) break;
		// check if the number is not a digit
		if (next < 0x30 || next > 0x39) continue;
		// store the digit in the buffer and increment the index
		buf[iter] = next - 0x30; iter ++;
	}

	// close the file
	fclose(fp);

	// keep variables for the maximum value and the current value
	uint64_t max = 0, current = 1;
	uint32_t index = num_digits - length;
	// loop through the array
	for (int index = 0; index < num_digits - length; index ++) {
		// reset the current product variable
		current = 1;
		// loop through the digits and find the product
		for (int i = 0; i < length; i ++) {
			current *= buf[index + i];
		}
		// check if the calculated value is greater than the max
		if (current > max) {
			printf("calculated new max - %lld.\n", current);
			max = current;
		}
	// loop until the index is zero
	} 
	
	// output the answer
	printf("the answer is %lld.\n", max);

}

