#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// struct for the current key context
struct keyval_t {
	uint8_t a;
	uint8_t b;
	uint8_t c;
};

// union for easier processing
typedef union key_t {
	struct keyval_t keyval;
	uint8_t keyarr[3];
} key_t;

void iterate(union key_t *);
int done(union key_t *);

// program entry point
int main(int argc, char **argv) {

	// attempt to open the file
	FILE *fp = fopen("cipher.txt", "rb");
	if (!fp) {
		printf("unable to open cipher.txt\n");
		exit(1);
	}

	// get the size of the file
	fseek(fp, 0, SEEK_END);
	uint32_t size = ftell(fp);
	rewind(fp);

	// create a chunk of memory large enough to hold the file's contents
	char *contents = (char *) malloc ((size * sizeof(char)) + 1);
	fread(contents, size, 1, fp);
	fclose(fp);
	contents[size] = 0;

	// find out how many entries in the file
	uint32_t values = 0, iter;
	for(iter = 0; iter < size; iter ++) {
		// check if a comma character was found
		if (contents[iter] == 0x2C) {
			values ++;
		}
	}

	// create buffers for encrypted and decrypted elements
	uint8_t *encrypt = (uint8_t *) malloc (values * sizeof(uint8_t));
	uint8_t *decrypt = (uint8_t *) malloc (values * sizeof(uint8_t));

	// parse the contents of the file and store in the encrypt buffer
	uint16_t carry = 0, position = 0;
	for (iter = 0; iter < size; iter ++) {
		// check if the null character was found
		if (contents[iter] == 0x00) {
			encrypt[position] = carry;
			break;
		}
		// check if the comma character was found
		if (contents[iter] == 0x2C) {
			encrypt[position] = carry;
			carry = 0; position ++;
		}
		// check if a numeric character was found
		if (contents[iter] >= 0x30 && contents[iter] < 0x40) {
			carry = (10 * carry) + (contents[iter] - 0x30);
		}
	}

	// enter a loop to test the different keys
	key_t solution, context;
	context.keyval.a = context.keyval.b = context.keyval.c = 0;
	uint8_t running = 1, local_key;
	while (running) {
		// iterate through each element until a bad character is found
		for (iter = 0; iter < values; iter ++) {
			// get the local key for the current character
			local_key = context.keyarr[2 - (iter % 3)] + 0x61;
			decrypt[iter] = encrypt[iter] ^ local_key;
			// check if there are any undesirable elements in the current parsed list
			if (decrypt[iter] > 0x7F || decrypt[iter] < 0x20) {
				break;
			}
		}
		// check if the word " the " is found
		if (match(decrypt, values)) {
			// if it is, add together all of the ascii values in the decrypted string
			uint32_t sum = 0;
			for (iter = 0; iter < values; iter ++) {
				sum += decrypt[iter];
				printf("%c", decrypt[iter]);
			} printf(".");
			// add another period to complete the chain
			sum += '.';
			// output the solution to the user
			printf("\n-> the solution is %d.\n", sum);
		}
		// iterate the key and check if the current context is complete
		iterate(&context);
		if (done(&context)) running = 0;
	}


}

// function to iterate the key
void iterate(union key_t *key) {
	key->keyval.c = (key->keyval.c + 1) % 25;
	if (key->keyval.c == 0) {
		key->keyval.b = (key->keyval.b + 1) % 25;
		if (key->keyval.b == 0) {
			key->keyval.a = (key->keyval.a + 1);
		}
	}
}

// function to check if we are done iterating
int done(union key_t *key) {
	return key->keyval.a == 26;
}

// function to match the character string "the" in a dynamic character array
int match(char *buf, int len) {
	int iter = 0; for (iter = 0; iter < len - 5; iter ++) {
		if ((buf[iter + 0] == ' ') &&
		    (buf[iter + 1] == 't') &&
		    (buf[iter + 2] == 'h') &&
		    (buf[iter + 3] == 'e') &&
		    (buf[iter + 4] == ' ')) return 1;
	} return 0;
}
