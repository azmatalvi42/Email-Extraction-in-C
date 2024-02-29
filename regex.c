
#include <stdio.h>
#include <stdlib.h>




int main() {
char inFile[30];
char outFile[30];
char command[350];
FILE *file= NULL;



// User input

while(file== NULL) {
	printf("Enter the name of the input file: ");
    	scanf("%s", inFile);
    	file=fopen(inFile, "r");
	if (file == NULL) {
		printf("Error opening input file: No such file or directory\n");
		}
		
	}
	
printf("Enter the name of the output file for valid emails: ");
scanf("%s", outFile);

// Extract with grep
	sprintf(command, "grep -o '\\b[A-Za-z0-9._%%+-]\\+@[A-Za-z0-9.-]\\+\\.[A-Za-z]\\{2,\\}\\b' %s | xargs -I{} echo {} > %s", inFile, outFile);

	system(command);
	
	printf("Valid emails extracted and saved to %s\n", outFile);

	return 0;
}


