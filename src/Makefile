all: tokenizer

tokenizer: tokenizer.c main.c
	gcc $^ -g -o $@

clean:
	rm -f *.o *.c~ tokenizer 
