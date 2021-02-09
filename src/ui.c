#include <stdio.h>
#include <stdlib.h>

#define MAX 50

/* interface to take user input*/
int main() {

	char str[MAX];

	printf("Enter a string to get started or enter q to exit \n");
	
	/* checks if input is q. if true quit else continue getting input */
	while(*str != 'q') {
		printf("> ");
		fgets(str, MAX, stdin);
		printf("You entered: %s\n", str);
	}
	
	printf("System exited successfully!\n\n");
	return 0;
}

