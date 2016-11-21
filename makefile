CC=gcc
CFLAGS=-g -Wall -pedantic -Wextra #-ansi
TARGET=forkbomb
OBJ=$(patsubst %.c,%.o,$(wildcard *.c))

.PHONY: all
all: $(TARGET)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

.PHONY: clean
clean:
	rm -f core *.o $(TARGET)
