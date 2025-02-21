#include "ft_printf.h"
#include <stdio.h>

int	ft_print_str(char *str)
{
	int	count;

	if (!str)
	{
		count = write(1, "(null)", 6);
		return (count);
	}
	count = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
