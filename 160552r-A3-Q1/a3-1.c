/*
 * File: a3-1.c
 * Author: James Robinson 160552r@acadiau.ca
 * Date: 2022/03/16
 * Purpose: 
 * 	Reads in a file from the command line and gives a menu to manipulate it
 *	Can remove comments, remove blank lines, or insert line numbers
 *	User can continue to select these options until they choose to quit
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Declares file handles as global variables
FILE *inputFile;
FILE *tempFile;
char *inputFileName;
char tempFileName[100] = "temp_";

void showMenu(){
//Prints a selection menu
	printf("Please make a selection from the list below\n\n");
	printf("a) Remove comments\n");
	printf("b) Remove blank lines\n");
	printf("c) Add line numbers\n");
	printf("d) Quit\n\n");
}

void clearInput(){
//Clears user input to the end of a line
//Call after getting input from the user
	char c;
	while ((c = getchar() != '\n'))
		;

}

int isBlankLine(char line[]){
//Reads in a line and checks if it contains something other than space
	int isBlank = 1;
	int lineLength = strlen(line);
	if (lineLength == 0){//Ends immediately if line length is 0
		return isBlank;
	}
	//Checks each character for a non-space
	for (int i = 0; i < lineLength; i++){
		if (!(isspace(line[i]))){
			isBlank = 0;
			return isBlank;
		}
	}
	return isBlank;
}

int replaceTempFile(){
//Closes both files, replaces input file with temp file
//Creates a new temp file, and opens both files
	fclose(tempFile);
	fclose(inputFile);
	remove(inputFileName);
	rename(tempFileName, inputFileName);

	if ((inputFile = fopen(inputFileName, "r")) == NULL){
		printf("File could not be opened\n");
		return EXIT_FAILURE;
	}
	if ((tempFile = fopen(tempFileName, "w")) == NULL){
		printf("Could not open temp file\n");
		return EXIT_FAILURE;
	}
	return 0; //Indicate succes
}

void removeComments(){
	char currentLine[200];
	fseek(inputFile, 0, SEEK_SET);
	while ((fgets(currentLine, 200, inputFile)) != NULL){
		//Line contains no comment, copy to temp file
		if (strstr(currentLine, "//") == NULL && strstr(currentLine, "*") == NULL){
			fprintf(tempFile, "%s", currentLine);
		}
		//Line contains start of multi-line comment
		else if (strstr(currentLine, "/*") != NULL){
			char *startOfComment = strstr(currentLine, "/*");
			int  startAddress = startOfComment - currentLine;
			if (startAddress != 0){
				for (int i = 0; i < startAddress; i++){
					fputc(currentLine[i], tempFile);
				}
			}
			do{
				if (fgets(currentLine, 200, inputFile) == NULL){
					break;
				}
			}
			while (strstr(currentLine, "*/") == NULL);
			
			char *endOfComment = strstr(currentLine, "*/") + 2;
			int  endAddress = endOfComment - currentLine;
			int  lineLength = (int)strlen(currentLine);
			for (int i = endAddress; i < lineLength; i++){
				fputc(currentLine[i], tempFile);
			}
		}
		//Line contains a single-line comment
		else if (strstr(currentLine, "//") != NULL){
			char *startOfComment = strstr(currentLine, "//");
			int  startAddress = startOfComment - currentLine;
			if (startAddress != 0){ 
				for (int i = 0; i < startAddress-1; i++){
					fputc(currentLine[i], tempFile);
				}
			}
		}
	}
	replaceTempFile();
}

void removeBlankLines(){
//Reads through a file line-by-line
//Checks if each line in input file is blank
//Copies to tempfile if not blank
	char  currentLine[200];
	fseek(inputFile, 0, SEEK_SET);
	while ((fgets(currentLine, 200, inputFile)) != NULL){
		if (!(isBlankLine(currentLine))){
			fprintf(tempFile, "%s", currentLine);
		}
	}
	replaceTempFile();
}

void addLineNumbers(){
//Reads through the input file line-by-line
//Copies each line to the temp file with line numbers
//NOTE: will cause removeBlankLines() to do nothing
	int  lineNumber = 1;
	char currentLine[200];
	fseek(inputFile, 0, SEEK_SET);
	while ((fgets(currentLine, 200, inputFile)) != NULL){
		fprintf(tempFile, "%d.\t", lineNumber);
		fprintf(tempFile, "%s", currentLine);
		lineNumber++;
	}
	replaceTempFile();
}

int main(int argc, char *argv[]){

	char selection;

	//Check for file name on command line
	if (argc < 2){
		printf("Expected file name as command line argument\n");
		return EXIT_FAILURE;
	}
	
	inputFileName = argv[1];
	strcat(tempFileName, inputFileName);

	//File open idiom
	if ((inputFile = fopen(inputFileName, "r")) == NULL){
		printf("File could not be opened\n");
		return EXIT_FAILURE;
	}
	if ((tempFile = fopen(tempFileName, "w")) == NULL){
		printf("Could not open temp file\n");
		return EXIT_FAILURE;
	}

	//Let user choose options until quit is selected
	while (selection != 'd'){
		showMenu();
		selection = getchar();
		clearInput();
			
		if (selection == 'a'){
			removeComments();
		}

		else if (selection == 'b'){
			removeBlankLines();
		}

		else if (selection == 'c'){
			addLineNumbers();
		}

		else if (selection != 'd'){
			printf("Input did not match any option\n");
		}
	}
	remove(tempFileName);
	printf("Thank you!\n");
}
