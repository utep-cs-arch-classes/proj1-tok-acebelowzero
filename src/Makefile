all: tokenizer

tokenizer: tokenizer.c history.c main.c
	gcc $^ -g -o $@

clean:
	rm -f *.o *.c~ tokenizer 
