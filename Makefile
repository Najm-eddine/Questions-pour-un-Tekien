CC = gcc
CFLAGS = -Wall -Wextra -g
EXEC = qcm_tekien
SRC = main.c fonction.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c fichier.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)
