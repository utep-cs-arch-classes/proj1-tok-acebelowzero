#include <stdio.h>
#include <stdlib.h>

#define MAX 50

/* interface to take user input*/
void main() {

	char c, str[MAX];
	int i = 0;
	printf("Enter a string to get started or enter $ to exit \n");
	
	

	for(;;) {
		// get users input
		//printf("> ");
		c = getchar();
		if(c=='$') {
			break;
		}
		printf("%c",c);
	}
	
}

