#include "tokenizer.h"

int space_char(char c) {
	// if whitespace character return true || false
	if(c == ' ' || c == '\t' || c == '\n') return 1;
	// if zero terminator return false || 0
	return 0;
	
}

int non_space_char(char c){
	if(!sapce_char(c)) return 1;
	return 0;
}

char *word_start(char *str){
	for(int i =0; space_char(str[i]);  i++) {
		return str[i];
	}
}

char *word_end(char *str) {
	str = word_start(str);
	for(int i = 0; non_space_char(str); i++) {
		return str[i]
	}
}

int count_words(char *str) {
	int count;
	int i;
	
	for(count = 0; str != word_end(str); count++) {
		str = word_end(str);
	}
	return count;
}

char *copy_str(char *inStr, short len) {
	int i;
 	char *newSpace =	(char *) malloc(sizeof(char) * (len+1));
	for(i=0; i< len; i++) {
		newSpace[i] = inStr[i];
	}
	newSpace[i] = '\0';
	return newSpace;
}


char **tokenize(char* str) {
	int i;
	int totalWords = count_words(str);
	char **tokenized = (char *)malloc(sizeof(char*) * (totalwords++));
	char *start_word = word_start(str);
	char *end_word = word_end(str);
	int word_len = end_word - start_word;
	

	for (int = 0; i < totalWords; i++) {
	tokenized[i] = copy_str(start_word, word_len);
	start_word = word_start(end_word);
	end_word = word_end(start_word);
	}
	
	tokenized[i] = NULL;
	return tokenized;
	
}
