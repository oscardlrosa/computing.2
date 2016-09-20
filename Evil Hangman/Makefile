CFLAGS = -Wall --std=c99 -g
HANGMAN_OBJECTS 	= mystring.o dictionary.o generic_vector.o assocarray.o hangman.o
GENERAL_OBJECT		= hangman

all: hangman

hangman : $(HANGMAN_OBJECTS)
	$(CC) -g -o hangman $(HANGMAN_OBJECTS)

clean:
	rm -rf *o *~ $(GENERAL_OBJECT)
