FILES = tokenizer.o history.o main.o
CFLAGS = -g

all: tokenizer

tokenizer: $(FILES)
					gcc -c tokenizer $(CFLAGS) $(FILES)
clean: 
	rm -f *.o tokenizer

run: tokenizer
		./tokenizer
