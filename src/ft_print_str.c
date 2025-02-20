#include "ft_printf.h"
#include <stdio.h>

int	ft_print_str(char *str)
{
	int	count_caracter;

	count_caracter = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		count_caracter++;
	}
	return (count_caracter);
}
