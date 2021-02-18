#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define MAX 32
void main() {
    char **tokenized, c, str[MAX];
    int i;
		/* Enter q to quit the program  */
    while(*str != 'q') {
        printf("> ");
				/* takes in user input and stores it in character array */
        for(i = 0; (c = getchar()) !='\n' && i < MAX-1; i++){
            str[i] = c;
        }
        str[i] = '\0';
        printf("%s\n", str);
				char **test = tokenize(str);
				print_tokens(test);
//				free_tokens(test);
    }

}
  
