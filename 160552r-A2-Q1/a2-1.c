
/* File: a2-1.c
 * Author: James Robinson 160552r@acadiau.ca
 * Date: 2022/03/06
 * Version: 1.0
 * Purpose: 
 *         Displays the number of each type of character in a file.
 *         Opens the file, counts characters of each type, closes the file
 *         and prints out the totals counted.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char** argv){
	int digitCount = 0;
	int alphaCount = 0;
	int punctuationCount = 0;
	int otherCount = 0;
	int totalCount = 0;
	int currentChar;
	FILE *fileHandle;

	//Checek for input file
	if (argc < 2){
		fprintf(stderr, "Error - expected file name as second argument.\n");
		return EXIT_FAILURE;
	}
	
	//Ensure file opens
	if ((fileHandle = fopen(argv[1], "r")) == NULL) {
	       fprintf(stderr, "Could not open file.\n");
	       return EXIT_FAILURE;
	}

	//Count characters of each type
	while ((currentChar = fgetc(fileHandle)) != EOF) {
		totalCount++;
		if (isdigit(currentChar)) {
			digitCount++;
		}
		else if (isalpha(currentChar)) {
			alphaCount++;
		}
		else if(ispunct(currentChar)) {
			punctuationCount++;
		} 
		else {
			otherCount++;
		}
	}

	//Display character type counts
	printf("Character breakdown:\n\n");
	printf("Digits:               %6d\n", digitCount);
	printf("Letters:              %6d\n", alphaCount);
	printf("Punctuation:          %6d\n", punctuationCount);
	printf("Other Characters:     %6d\n", otherCount);
	printf("Total:                %6d\n\n", totalCount);
	
	//Ensure file closes properly
	if (fclose(fileHandle) == EOF) {
		fprintf(stderr, "File %s could not be closed.\n", "t");
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
