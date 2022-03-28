/* File: a5-1.c
 * Author: James Robinson 160552r@acadiau.ca
 * Date: 2022/04/01
 * Purpose:
 * 	Demonstrate the use of memory allocation and pointers
 * 	Allows the user to call functions to allocate memory,
 * 	change the value of a location or retrieve the value at a location
 * 	Warns the user if they try to manipulate unallocated memory, but
 * 	allows them to continue anyway 
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

//Allocates memory for n integers and returns a pointer to the block
int* allocate(int n){
	int* ptr = malloc(n * sizeof(int));
	return ptr;
}

//Sets the memory location to int
void set(int* block, int index, int number){
	block[index] = number;
}

//Returns the value stored at the specified memory location
int get(int* block, int index){
	return block[index];
}

//Prints a warning and returns true if the user chooses to continue
int warn(char* message){
	char userChoice;
	char c;
	printf("%s", message);
	printf("Continue? (y/n)\n");
	userChoice = getchar();
	while ((c = getchar()) != '\n')
		;
	if (userChoice == 'y' || userChoice == 'Y')
		return 1;
	else
		return 0;
}

int main(){
	int  blockSize;
	int  currNum;
	int* block;
	int  index;
	char optionSelected;
	char c;
	printf("Hello! Please select an option to get started\n");
	while (optionSelected != 'd'){
		printf("a)\tAllocate a block of memory\n");
		printf("b)\tStore a number in a memory location\n");
		printf("c)\tRead the value of a memory location\n");
		printf("d)\tQuit\n");
		optionSelected = getchar();
		while ((c = getchar()) != '\n')
			;
		if (optionSelected == 'a'){
			printf("Allocate for how many numbers?\n");
			scanf("%d", &blockSize);
			while ((c = getchar()) != '\n')
				;
			if (blockSize < 1){
				if(warn("You entered a value less than 1\n")){
					block = allocate(blockSize);
					printf("Allocation complete\n\n");
				}
			}
			else{
				block = allocate(blockSize);
				printf("Allocation complete\n\n");
			}
		}

		else if (optionSelected == 'b'){
			printf("What number would you like to store?\n");
			scanf("%d", &currNum);
			while ((c = getchar()) != '\n')
				;
			if (currNum > INT_MAX){
				if (warn("This number is too big to be stored")){		
					printf("What position should it be?\n");
					scanf("%d", &index);
					while ((c = getchar()) != '\n')
						;
					if (index < 0 || index > blockSize-1){
						if (warn("This is outside your allocated memory\n")){
							set(block, index, currNum);
							printf("Storage completed\n");
						}
					}
					else{
						set(block, index, currNum);
						printf("Storage completed\n");
					}
				}
			}
			else{
				
				printf("What position should it be?\n");
				scanf("%d", &index);
				while ((c = getchar()) != '\n')
					;
				if (index < 0 || index > blockSize-1){
					if (warn("This is outside your allocated memory\n")){
						set(block, index, currNum);
						printf("Storage completed\n");
					}
				}
				else{
					set(block, index, currNum);
					printf("Storage completed\n");
				}
			}
		}
		else if (optionSelected == 'c'){
			printf("Which position would you like to read from?\n");
			scanf("%d", &index);
			while ((c = getchar()) != '\n')
				;
			if (index < 0 || index > blockSize-1){
				if (warn("This is outside of your allocated memory\n")){
					printf("I found: %d\n", get(block, index));
				}
			}
			else{
				printf("I found: %d\n", get(block, index));
			}
		}

		else if (optionSelected != 'd'){
			printf("\nInvalid selection\n\n");
		}
	}
}
