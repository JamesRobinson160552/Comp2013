
/* Author: James Robinson
 * File: a5-2.c
 * Date: 2022/04/01
 * Purpose:
 * 	Creates a stack of ints with basic push/pop funtionality
 * 	Allows the user to add or remove from the stack
 * 	Dynamically changes size based on the number of elements
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* stack;
int  stackTop;
int  stackSize;

//Allocates a new block of memory double the size of the stack
//Copies the stack elements to the new block
void increaseSize(){
	int  newSize = stackSize * 2;
	int* temp = malloc(newSize * sizeof(int));
	memcpy(temp, stack, newSize * sizeof(int));
	free(stack);
	stack = malloc(newSize * sizeof(int));
	memcpy(stack, temp, newSize * sizeof(int));
	free(temp);
	printf("Changed stack size from %d to %d\n", stackSize, newSize);
	stackSize = newSize;
}

//Allocates a new block of memory half the size of the stack
//Copies the stack elements to the new block
void decreaseSize(){
	int  newSize = stackSize / 2;
	int* temp = malloc(newSize * sizeof(int));
	memcpy(temp, stack, newSize * sizeof(int));
	free(stack);
	stack = malloc(newSize * sizeof(int));
	memcpy(stack, temp, newSize * sizeof(int));
	free(temp);
	printf("Changed stack size from %d to %d\n", stackSize, newSize);
	stackSize = newSize;
}

//Adds an item to the top of the stack
//Increases stack size if the stack is full
void push(int num){
	if (stackTop == stackSize - 1){
		increaseSize();
	}
	stackTop++;
	stack[stackTop] = num;
}

//Removes and returns the item at the top of the stack
//Decreases stack size if less than 25% of space is in use
void pop(){
	int result = stack[stackTop];
	stackTop --;
	if (stackTop < (stackSize/4)){
		decreaseSize();
	}
	printf("I found: %d\n", result);
}

//Prints each item in the stack
void printStack(){
	printf("\nHere is your stack:\n\n");
	for (int index = stackTop; index >= 0; index--){
		printf("%d.\t%d\n", index, stack[index]);
	}
	printf("\n");
}

int main(){
	char userSelection;
	int  userNum;
	char c;
	stackSize = 5;
	stackTop = -1;
	stack = malloc(stackSize * sizeof(int));
	while (userSelection != 'd'){
		printf("Please select from the options below\n");
		printf("a)\tPush\nb)\tPop\nc)\tPrint\nd)\tQuit\n");
		userSelection = getchar();
		while ((c = getchar()) != '\n')
			;
		if (userSelection == 'a'){
			printf("What would you like to add?\n");
			scanf("%d", &userNum);
			while ((c = getchar() != '\n'))
				;
			push(userNum);
		}

		else if (userSelection == 'b'){
			if (stackTop == -1){
				printf("The stack is empty\n");
			}
			else{
				pop();
			}
		}

		else if (userSelection == 'c'){
			printStack();
		}

		else if (userSelection != 'd'){
			printf("Could not recognize selection\n");
		}
	}
	printf("Thank you - Goodbye!\n");
	free(stack);
}
