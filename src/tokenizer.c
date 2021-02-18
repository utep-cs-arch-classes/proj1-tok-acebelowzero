#include "tokenizer.h"
#include  <stdlib.h>
#include <stdio.h>
int space_char(char c) {
	// if whitespace character return true || false
	if((c == ' ' || c == '\t') && c != '\0') {
		 return 1;
	}
	// if zero terminator return false || 0
	return 0;
	
}
/* 
checks if character is not a white space character
*/
int non_space_char(char c){
	if((c != '\t' && c != ' ') && c != '\0') {
		return 1;
	}
	return 0;
}

// returns starting word of str
char *word_start(char *str){
//	for(int i =0; space_char(str[i]);  i++) {
	//	return &str[i]; // returns character
//	}
	int i = 0;
	while(space_char(str[i])) {
		i++;
	}
	return &str[i];
}

//retruns end word of str
char *word_end(char *str) {
	//printf("%s", str);
	str = word_start(str);
	//printf("%s", str);
	int i =0;
	while(non_space_char(str[i])){
		i++;
	}
	return &str[i];
	//for(int i = 0; non_space_char(str[i]); i++) {
	//	return &str[i];
	//}
}
/*
 returns the total number of words by 
 counting total number of spaces
*/
int count_words(char *str) {
	int count;
	
	for(count = 0; str != word_end(str); count++) {
		str = word_end(str);
	}
	return count;
}

// returns a array with a word in it
char *copy_str(char *inStr, short len) {
	int i;
 	char *newSpace =	(char *)malloc(sizeof(char) * (len+1)); // create a block of memory
	for(i=0; i< len; i++) {
		newSpace[i] = inStr[i]; // adds each character to memory
	}
	newSpace[i] = '\0'; // ends the block will a zero terminator
	return newSpace;
}

// returns an array of words
char **tokenize(char *str) {
	
	int i;
	int totalWords = count_words(str); //gets the total count of all the words
	char **tokenized = malloc(sizeof(char **) * (++totalWords)); // creates a block or memory 
	char *start_word = word_start(str); // gets the starting word
	printf("%s", start_word);
	char *end_word = word_end(str); // gets the ending character
	//int word_len = end_word - start_word; // gets the length of the word
//	printf("%d", word_len);

	for (i = 0; i < totalWords; i++) {
		tokenized[i] = copy_str(start_word, end_word-start_word); // creates a char "array" and stores it in postion i of tokenized
		start_word = word_start(end_word); // gets the new starting word
		end_word = word_end(start_word); // gets the new ending word
	}
	
	tokenized[i] = NULL;
	return tokenized;
}

void print_tokens(char **tokens){
	for(int i = 0; tokens[i] != NULL; i++) {
		printf("%s\n", tokens[i]);
	}
}

void free_tokens(char **tokens) {
	for(int i = 0; tokens[i] != NULL; i++) {
		free(tokens[i]);
	}
	free(tokens);	
}

// testing purposes
//void main() {
//	char str[32];
//	char c;
//	int i;
//	for(i = 0; (c = getchar()) != '\n'; i++){
//		str[i] = c;
//	}
//	str[i] = '\0';
//	char **test = tokenize(str);
//	print_tokens(test);
//	free_tokens(test);
////	//char *t = word_end(str);
////	//printf("%s", t);
////
//}
