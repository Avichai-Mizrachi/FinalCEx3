CC = gcc
MYFLAG = -Wall -g

.PHONY: all clean

all: isort txtfind

isort: isort.o
	$(CC) $(MYFLAG) $^ -o $@

txtfind: txtfind.o
	$(CC) $(MYFLAG) $^ -o $@

%.o: %.c
	$(CC) $(MYFLAG) -c $<

clean:
	rm -f *.o txtfind isort