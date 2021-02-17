#include <stdio.h>
#define MAX 40
void main() {
    char c, str[MAX];
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
    }

}
  
