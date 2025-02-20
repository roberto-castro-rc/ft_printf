#include "ft_printf.h"

int	ft_print_char(int c, int convert_number)
{
	if (convert_number == 1)
		c += '0';
	write(1, &c, 1);
	return (1);
}