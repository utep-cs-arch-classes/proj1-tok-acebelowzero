#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 120

int compare_string(char *str1, char *str2)
{
  int i;
  for (i = 0; str1[i] == str2[i]; i++) { // Compares each character while they are the same
    if ( str1[i] == '\0') return 0; // If loops reaches null terminal character, the strings are
  }                                //  equal.
  return -1; 
}

int str_to_num(char *str)
{

  int i = 0;
  int num = 0;
  for(i=0; str[i] != '\0'; i++) {
    num = num*10;
    num = num+(str[i]-48);

    // how it works 23 0*10+2=2 2*10=20+3=23
    
  }
  return num;
}

void main() {
    char  c, str[MAX];
    int i, index = 0;
    List *history = init_history();
    printf("Welcome, Enter a string to get started. Enter q to exit \n");
    printf("To view history type history and to select and historic item use !n -> n is the id of your choice \n");
		/* Enter q to quit the program  */
    while(*str != 'q') {
        printf("> ");
				/* takes in user input and stores it in character array */
        for(i = 0; (c = getchar()) !='\n' && i < MAX-1; i++){
            str[i] = c;
        }
        str[i] = '\0';
        // input is not !3 then continue
        if (compare_string("history", str) == 0) {
          print_history(history);
        } else if (str[0] == '!') {
            index  = str_to_num(str+1);          // If string begins with !, get string of item
            printf("%s\n", get_history(history,index)); // with id of the number that follows !
        }
        else {  
          char **test = tokenize(str);
          print_tokens(test);
          free_tokens(test);
          add_history(history,copy_str(str,i));
        }
    }
    free_history(history);
}
  

