/* File: a4-1.c
 * Author: James Robinson 160552r@acadiau.ca
 * Date: 2022/03/25
 * Purpose:
 * 	Demonstrates the use of modules using a basic math module
 * 	Gives the user a menu of operations and prompts them for 2 numbers
 * 	Prints out the result of the operation
*/

#include <stdio.h>
#include <stdlib.h>
#include "myMath.h"

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
			result = add(firstNum, secondNum);
			printf("Your result is: %d\n", result);
		}

		else if (operationSelected == 'b'){
			int result;
			firstNum = getInteger();
			secondNum = getInteger();
			result = subtract(firstNum, secondNum);
			printf("Your result is: %d\n", result);
		}

		else if (operationSelected == 'c'){
			int result;
			firstNum = getInteger();
			secondNum = getInteger();
			result = multiply(firstNum, secondNum);
			printf("Your result is: %d\n", result);
		}

		else if (operationSelected == 'd'){
			float result;
			firstNum = getInteger();
			secondNum = getInteger();
			result = divide(firstNum, secondNum);
			printf("Your result is: %.2f\n", result);
		}

		else if (operationSelected != 'e'){
			printf("Invalid option selected\n");
		}
	}
	printf("Thank you - goodbye!\n");
}
