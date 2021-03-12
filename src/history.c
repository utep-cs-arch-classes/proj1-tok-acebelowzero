#include <stdio.h>
#include <stdlib.h>
#include "history.h"


// Initializes list and sets root to NULL;
List *init_history(){
  List *list =malloc(sizeof(List));
  list->root = NULL;
  return list;
}


void add_history(List *list, char *str)
{
  Item *item = malloc(sizeof(Item)); 
  Item *temp = list->root; 

  // set str field value of new item
  item->str = str; 

  // sets next field null since we do not know next filed yet
  item->next = NULL; 
  int i = 0;
  // if list is empty
  if (list->root == NULL) {
    // then set new item to root
    item->id = i;   
    list->root = item;
  } else {             
    i = 1;
    // else parse through list until we find Null
    for(i = 1; temp->next != NULL; i++){
      temp = temp->next;
    }
    temp->next = item;
    item->id = i;
  }
}


// Gets the string at position id of linked list
char *get_history(List *list, int id)
{
  // assign root
  Item *temp = list->root; 
  // pasrse linked list
  while (temp != NULL) {
    // check if id matched
    if (temp->id == id) {  
      return temp->str;  
    }
    temp = temp->next; 
    // else return null if provided index is not found
  }
  printf("Error: Index out of bounds, Index must be less than %d\n", list->root->id);
  return NULL; 
}



void print_history(List *list)
{
  // start at root
  Item *temp = list->root; 

  printf("\n");
  while (temp != NULL) { 
    // Print id and str of that item
    printf("%d: %s\n", temp->id, temp->str); 
    temp = temp->next;
  }
  printf("\n");
}

// Frees the allocated memory of history
void free_history(List *list)
{
  Item *temp; 
  while (list->root != NULL) { 
    // assign root
    temp = list->root;       // the root to be the next of current root
    // new root is now the next of root
    list->root = list->root->next; 
    // frees the  root item
    free(temp);              
  }
  // frees the memory allocated for list 
  free(list);                
}