/* File: myMath.h
 * Author: James Robinson
 * Date: 2022/03/25
 * Purpose:
 * 	A math module containing add, subtract, multiply, and divide functions
 * 	All functions take 2 integers, all functions return an integer
 * 	Except divide which returns a float
 * Note:
 * 	Does not do any type checking, assumes this is done in the main program
*/

int add(int num1, int num2){
//Returns the sum of num1 and num2
	return (num1 + num2);
}

int subtract(int num1, int num2){
//Returns the difference of num1 and num2
	return (num1 - num2);
}

int multiply(int num1, int num2){
//Returns the product of num1 and num2
	return (num1 * num2);
}

float divide(int num1, int num2){
//Returns the quotient of num1 and num2
	return (num1 / num2);
}
