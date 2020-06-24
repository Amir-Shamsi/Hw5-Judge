#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "judge.h" // judge.h

int compileMe(char address[]) {
	char command[1000] = "gcc -o Terminal";
	strcat(command, address); // Create the command
	return system(command);
}


void judge(char terminalAddress[], int inputCount, int result[]) { // terminalAddress as the exe file after compile
	int count;
	char number[10] = { 10 * '/0' }, hostString[MAX_OUTPUT_LENGTH], checkString[MAX_OUTPUT_LENGTH];
	FILE* hostFile, *checkFile;


	for (count = 1; count <= inputCount; count++) {
		/*Create Command For CMD!*/
		/*File Structure ---> input1.txt*/
		sprintf(number, "%d", count); //convert int to char.
		char command[100] = ".\\Terminal.exe <..\\in\\input"; strcat(command, number); strcat(command, ".txt >..\\out\\output");
		strcat(command, number); strcat(command, ".txt");
		
		char hostFilename[1000] = "..\\generate\\out\\output"; strcat(hostFilename, number); strcat(hostFilename, ".txt");
		char checkFilename[1000] = "..\\out\\output"; strcat(hostFilename, number); strcat(hostFilename, ".txt");
	

		hostFile = fopen(hostFilename, "r");
		while (fgets(hostString, MAX_OUTPUT_LENGTH, hostFile) != NULL);
		fclose(hostFile);

		checkFile = fopen(checkFilename, "r");
		while (fgets(checkString, MAX_OUTPUT_LENGTH, checkFile) != NULL);
		fclose(checkFile);

		if (strcmp(hostString, checkString) == ACCEPTED)
			result[count - 1] = 1; // if judge output and generator out put are the same result must be 1.
		else
			result[count - 1] = 0; // zero means "not the same!".
	}
}


void judgeResult(int result[], int testCasesCount) {
	for (int index = 0; index <= testCasesCount; index) {
		if (result[index])
			printf("Test Case #%d:\nAccepted", index + 1);
		else
			printf("Test Case #%d:\nDeclined", index + 1);
	}
}


int main() {
	return 0;
}
