#Makefile with basic concepts

# Define compiler and options
CC=gcc
CFLAGS= -W -Wall -Wextra -std=gnu99
GTK= `pkg-config --cflags --libs gtk+-2.0`
CURL= `curl-config --cflags --libs`
LDFLAGS= $(CURL) $(GTK)
EXEC=trading
.PHONY: all clean
# avoid calling make without option
# ONLY FOR THIS EXERCICE
all: $(EXEC)

$(EXEC): interface.o parsing.o action.o reseau.o main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 

parsing.o: reseau.o action.o parsing.c
	$(CC) $(CFLAGS) -o $@ -c $^  

%.o: %.c 
	$(CC) -o $@ -c $< $(LDFLAGS)

clean::
	rm -f *~ *.o
	rm -f $(EXEC)
# END (do not delete)


