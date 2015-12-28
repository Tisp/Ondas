EXEC = ondas
CC = gcc
CFLAGS = -O3
LIBS=-lm
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: build $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) $(LIBS) 
build: $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) $(LIBS) 
clean:
	rm -f $(OBJ) $(EXEC)
