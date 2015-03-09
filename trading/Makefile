#Makefile with basic concepts

# Define compiler and options
CC=gcc
CFLAGS= -W -Wall -Wextra -std=gnu99
GTK= `pkg-config --cflags --libs gtk+-2.0`
CURL= `curl-config --cflags`
EXEC=trading
.PHONY: all clean
# avoid calling make without option
# ONLY FOR THIS EXERCICE
all: $(EXEC)

$(EXEC): interface.o parsing.o action.o reseau.o main.c
	$(CC) $(CFLAGS) -o $@ $^ $(GTK) 

parsing.o: parsing.c reseau.o action.o
	$(CC) $(CFLAGS) -o $@ -c $^ 

reseau.o: reseau.c
	$(CC) $(CFLAGS) $(CURL) -o $@ -c $^ -lcurl

interface.o: interface.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(GTK)

action.o: action.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean::
	rm -f *~ *.o
	rm -f $(EXEC)
# END (do not delete)


