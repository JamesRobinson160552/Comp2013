#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc > 2){
		printf("I, %s %s, have read the appropriate ", argv[1], argv[2]);
		printf("sections of the 2021-22 Academic Calendar and I understand ");
		printf("the rules of Academic Integrity at Acadia University. ");
		printf("I will only submit my own code this term and I recognize ");
		printf("that any breach of academic dishonesty will result in penalties ");
		printf("up to and including expulsion from the university.\n");
	}

	else{
		printf("You must pass in two arguments when running this program.\n");
	}

	return(EXIT_SUCCESS);
}
