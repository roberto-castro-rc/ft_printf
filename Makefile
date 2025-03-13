# Nome do arquivo final
NAME = libftprintf.a

# Compilador
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Diretórios
SRCDIR = src
INCDIR = includes
OBJDIR = obj

# Arquivos fontes
SRCS = $(SRCDIR)/ft_printf.c \
       $(SRCDIR)/ft_print_char.c \
       $(SRCDIR)/ft_print_str.c \
       $(SRCDIR)/ft_print_nbr.c \
       $(SRCDIR)/ft_print_hex.c \
	   $(SRCDIR)/ft_print_unsigned_int.c \
	   $(SRCDIR)/ft_print_pointer.c

# Objetos (convertendo .c para .o)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Regras do Makefile
all: $(NAME)

# Compilar os objetos e criar a biblioteca estática
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compilar os arquivos fontes para objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/ft_printf.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar diretório obj se não existir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Limpar arquivos objetos
clean:
	rm -rf $(OBJDIR)

# Limpar objetos e biblioteca
fclean: clean
	rm -f $(NAME)

# Recompilar tudo do zero
re: fclean all

.PHONY: all clean fclean re bonus
