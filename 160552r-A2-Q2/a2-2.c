
/* File: a2-2.c
 * Author: James Robinson 160552r@acadiau.ca
 * Date: 2022/03/06
 * Version 1.0
 * Purpose: Lets the user choose to enter 2 integers, 2 decimal numbers or one of each.
 *          Prompts the user to enter their numbers based on the selection.
 *          Subtracts the second number from the first and diaplays the result.
 *          Repeats until the user chooses to exit.
 */

#include <stdlib.h>
#include <stdio.h>

//Gets rid of extra input to the end of a line
//Call after reading in input to avoid user error problems
void clearInput(){
	char c;
	do {
		c = getchar();
	}
	while (c != '\n');
}

int main(){
	char  optionSelected;
	int   firstInt;
	int   secondInt;
	int   resultInt;
	float firstFloat;
	float secondFloat;
	float resultFloat;

	//Continue until the user chooses to quit
	while (optionSelected != 'd'){
		printf("Please choose an option to begin:\n\n");
		printf("a) Two Integers\n");
		printf("b) Two Decimal Numbers\n");
		printf("c) One Integer and One Decimal Number\n");
		printf("d) Quit\n\n");

		optionSelected = getchar();
		clearInput();

		if (optionSelected == 'a'){ //Two integers
			printf("First Integer:\n");
			if (scanf("%d", &firstInt)){
				clearInput();
				printf("Second Integer:\n");
				if (scanf("%d", &secondInt)){
					clearInput();
					resultInt = firstInt - secondInt;
					printf("Result: %d\n\n", resultInt);
				}
				else {
					printf("Wrong input type\n");
					clearInput();
				}
			}
			else {
				printf("Wrong input type\n");
				clearInput();
			}
		}

		else if (optionSelected == 'b'){ //Two decimal numbers
			printf("First Decimal Number:\n");
			if (scanf("%f", &firstFloat)){
				clearInput();
				printf("Second Decimal Number:\n");
				if (scanf("%f", &secondFloat)){
					clearInput();
					resultFloat = firstFloat - secondFloat;
					printf("Result: %.2f\n\n", resultFloat);
				}
				else {
					printf("Wrong input type\n");
					clearInput();
				}
			}
			else {
				printf("Wrong input type\n");
				clearInput();
			}
		}

		else if (optionSelected == 'c'){ //One number of each type
			printf("Integer:\n");
			if (scanf("%d", &firstInt)){
				clearInput();
				printf("Decimal Number:\n");
				if (scanf("%f", &firstFloat)){
					clearInput();
					resultInt = firstInt - (int)firstFloat;
					resultFloat = (float)firstInt - firstFloat;
					printf("Result 1: %d\n", resultInt);
					printf("Result 2: %.2f\n", resultFloat);
				}
				else {
					printf("Wrong input type\n");
					clearInput();
			 	}
			}
			else {
				printf("Wrong input type\n");
				clearInput();
			}
		}

		else if (optionSelected != 'd'){ //User entered invalid choice
			printf("Error - invalid option\n");
		}
	}
	printf("Thank you, goodbye!\n");
}




