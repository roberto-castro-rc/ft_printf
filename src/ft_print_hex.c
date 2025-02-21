#include "ft_printf.h"
#include <stdio.h>


int	ft_print_hex(unsigned long number, char X_or_x)
{
	char	result[16];
	int		count;
	int		i;

	count = 0;
	if (number == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}
	i = 0;
	while (number != 0)
	{
		if (X_or_x == 'X')
			result[i] = "0123456789ABCDEF"[number % 16];
		else
			result[i] = "0123456789abcdef"[number % 16];
		number /= 16;
		i++;
	}
	while (i-- > 0)
		count += write(1, &result[i], 1);
	return (count);
}
