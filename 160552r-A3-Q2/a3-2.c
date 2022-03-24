/* File: a3-2.c
 * Author: James Robinson 160552r@acadiau.ca
 * Date: 2022/03/16
 * Purpose:
 * 	Prints out characters in the form of 4 different trees
 * 	The width of trees and the Character used are input from the user
 */


#include <stdio.h>
#include <stdlib.h>

//Prints an upside-down, left-justified tree of 'treeChar' with width 'width'
void printFirstTree(int width, char treeChar){
	for (int lastChar = 1; lastChar <= width; lastChar++){
		for (int i = 0; i < lastChar; i++){
			printf("%c", treeChar);
		}
		printf("\n");
	}
	printf("\n");
}

//Prints a right-justified tree of 'treeChar' with width 'width'
void printSecondTree(int width, char treeChar){
	int numSpaces = width-1;
	for (int numChars = 1; numChars <= width; numChars++){
		for (int i = 0; i < numSpaces; i++){
			printf(" ");
		}
		for (int i = 0; i < numChars; i++){
			printf("%c", treeChar);
		}
		numSpaces--;
		printf("\n");
	}
	printf("\n");

}

//Prints an upside-down, centered tree of 'treeChar' with width 'width'
void printThirdTree(int width, char treeChar){
	int numSpaces = 0;
	for (int numChars = width; numChars > 0; numChars -= 2){
		for (int i = 0; i < numSpaces; i++){
			printf(" ");
		}
		for (int i = 0; i < numChars; i++){
			printf("%c", treeChar);
		}
		numSpaces++;
		printf("\n");
	}
	printf("\n");
}

//Prints a right-side-up, centered tree of 'treeChar' with width 'width'
void printFourthTree(int width, char treeChar){
	int numSpaces;
	int numChars;

	//Ensure the tree is centered
	if(width % 2 == 0){
		numChars = 2;
		numSpaces = width/2 - 1;
	}
	else{
		numChars = 1;
		numSpaces = width/2;
	}

	while (numChars <= width){
		for (int i = 0; i < numSpaces; i++){
			printf(" ");
		}
		for (int i = 0; i < numChars; i++){
			printf("%c", treeChar);
		}
		numSpaces--;
		printf("\n");
		numChars += 2;
	}
	printf("\n");
}

int main(){
	char charToPrint;
	int  treeWidth;

	//Prompts the user for a character and a number, prints 'trees' based on the results
	printf("Please enter a character and a number to print some trees\n");

	printf("Character:\n");
	if (scanf("%c", &charToPrint) == 0){//Ensure character input
		printf("Wrong input type\n");
		return EXIT_FAILURE;
	}
	while (getchar() != '\n'){
		;
	}

	printf("Number:\n");
	if(scanf("%d", &treeWidth) == 0){//Ensure integer input
		printf("Wrong input type\n");
		return EXIT_FAILURE;	
	}
	while (getchar() != '\n'){
		;
	}
	
	printFirstTree(treeWidth, charToPrint);	
	printSecondTree(treeWidth, charToPrint);
	printThirdTree(treeWidth, charToPrint);
	printFourthTree(treeWidth, charToPrint);
}
