#include "ft_printf.h"
#include <stdio.h>

int	ft_print_char(int c, int convert_number);
int	ft_print_unsigned_int(long number)
{
	int	count_caracter;
	long	copy_number;


	copy_number = number;
	if (copy_number < 0)
		copy_number = -copy_number;
	count_caracter = 0;
	if (copy_number > 9)
		count_caracter += ft_print_unsigned_int(copy_number / 10);
	count_caracter += ft_print_char(copy_number % 10, 1);
	return (count_caracter);
}

