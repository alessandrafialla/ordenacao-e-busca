# Variáveis
CC     = gcc
CFLAGS = -Wall -Wextra -g -std=c99
SRC    = ordenacao.c main.c
OBJ    = $(SRC:.c=.o)
BIN    = ordena

# Regra principal
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

# Regra para criar objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Executar o programa
teste: $(BIN)
	./$(BIN)

# Testar com Valgrind
valgrind: $(BIN)
	valgrind --leak-check=full --track-origins=yes ./$(BIN)

# Limpeza dos arquivos gerados
clean:
	rm -f *.o *~ $(BIN)
