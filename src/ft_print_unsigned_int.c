#include "ft_printf.h"

#include <stdio.h>


int	ft_print_unsigned_int(unsigned int number)
{
	int	count;

	count = 0;
	if (number > 9)
		count += ft_print_unsigned_int(number / 10);
	count += ft_print_char(number % 10, 1);
	return (count);
}
