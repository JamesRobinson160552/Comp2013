/* File: myMath.c
 * Author: James Robinson 160552r@acadiau.ca
 * Date: 2022/03/25
 * Purpose:
 * 	Demonstrates the use of modules using a basic math module
 * 	Gives the user a menu of operations and prompts them for 2 numbers
 * 	Prints out the result of the operation
*/

//Definitions if compiled in debug mode
#ifdef DEBUG
#define ADD(num1, num2) (num1 + num2)
#define SUBTRACT(num1, num2) (num1 - num2)
#define MULTIPLY(num1, num2) (num1 * num2)
#define DIVIDE(num1, num2) (num1 / num2)
//Definitions if not compiled in debug mode
#else
#include "myMath.h"
#define ADD(num1, num2) (add(num1, num2))
#define SUBTRACT(num1, num2) (subtract(num1, num2))
#define MULTIPLY(num1, num2) (multiply(num1, num2))
#define DIVIDE(num1, num2) (divide(num1, num2))
#endif

#include <stdio.h>
#include <stdlib.h>

int getInteger(){
//Reads in a number from the user and ensures it is an integer
//Clears input afterwards
//Call as int someNumber = getInteger()
	int number;
	char c;
	printf("Please enter an integer\n");
	while (scanf("%d",&number) == EOF){
		printf("Error: could not read integer - please try again\n");
	}
	while ((c = getchar()) != '\n')
		;
	return number;
}

int main(){
#ifdef DEBUG
	printf("\n\nRUNNING IN DEBUG MODE...\n\n");
#endif
	int  firstNum;
	int  secondNum;
	char operationSelected;
	char c;
	
	while (operationSelected != 'e'){
		printf("Please select an operation from the menu below\n");
		printf("a)\tAdd\nb)\tSubtract\nc)\tMultiply\nd)\tDivide\n");
		printf("e)\tQuit\n");

		operationSelected = getchar();
		while ((c = getchar()) != '\n')
			;
		if (operationSelected == 'a'){
			int result;
			firstNum = getInteger();
			secondNum = getInteger();
			result = ADD(firstNum, secondNum);
			printf("Your result is: %d\n", result);
		}

		else if (operationSelected == 'b'){
			int result;
			firstNum = getInteger();
			secondNum = getInteger();
			result = SUBTRACT(firstNum, secondNum);
			printf("Your result is: %d\n", result);
		}

		else if (operationSelected == 'c'){
			int result;
			firstNum = getInteger();
			secondNum = getInteger();
			result = MULTIPLY(firstNum, secondNum);
			printf("Your result is: %d\n", result);
		}

		else if (operationSelected == 'd'){
			float result;
			firstNum = getInteger();
			secondNum = getInteger();
			result = DIVIDE(firstNum, secondNum);
			printf("Your result is: %.2f\n", result);
		}

		else if (operationSelected != 'e'){
			printf("Invalid option selected\n");
		}
	}
	printf("Thank you - goodbye!\n");
}
