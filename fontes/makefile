# Makefile genérico para compilar o programa de ordenação
# Carlos Maziero - DINF/UFPR

CC     = gcc
CFLAGS = -Wall -Wextra -g -std=c99
SRC    = ordenacao.c
OBJ    = $(SRC:.c=.o)
BIN    = ordena

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

teste: $(BIN)
	./$(BIN)

valgrind: $(BIN)
	valgrind --leak-check=full --track-origins=yes ./$(BIN)

clean:
	rm -f *.o *~ $(BIN)
