#include "ft_printf.h"
#include <stdio.h>
int	ft_print_nbr(int number)
{
	int	count_caracter;
	long	copy_number;

	copy_number = number;
	count_caracter = 0;
	if (copy_number < 0)
	{
		write(1, "-", 1);
		copy_number = -copy_number;
		count_caracter++;
	}
	if (copy_number > 9)
	{
		count_caracter += ft_print_nbr(copy_number / 10);
	}
	count_caracter += ft_print_char(copy_number % 10, 1);
	return (count_caracter);
}
