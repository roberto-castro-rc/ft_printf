# Nome do executável
NAME = ft_printf

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror

# Arquivos fonte
SRC =  ft_print_caracter.c ft_print_number.c

# Arquivos objeto (convertendo .c para .o)
OBJ = $(SRC:.c=.o)

FOR_WINDOWS = $(SRC:.c=.exe)

# Regra principal (compila o programa)
all: $(NAME)

# Como compilar o executável
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Como compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove arquivos objeto
clean:
	rm -f $(OBJ)

wclean:
	rm -f $(FOR_WINDOWS) $(OBJ) $(NAME)

# Remove arquivos objeto e executável
fclean: clean
	rm -f $(NAME)

# Refaz tudo do zero
re: fclean all

# Não trata arquivos como targets
.PHONY: all clean fclean re
