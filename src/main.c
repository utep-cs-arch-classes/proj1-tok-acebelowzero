#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 32

int compare_string(char *str1, char *str2)
{
  int i;
  for (i = 0; str1[i] == str2[i]; i++) { // Compares each character while they are the same
    if ( str1[i] == '\0') return 0; // If loops reaches null terminal character, the strings are
  }                                //  equal.
  return -1; 
}

int str_to_num(char *a)
{
 int c, sign, offset, n;
  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }
  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }
  n = 0;
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }

  if (sign == -1) {
    n = -n;
  }

  return n;
}

void main() {
    char  c, str[MAX];
    int i, index = 0;
    List *history = init_history();
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
  

