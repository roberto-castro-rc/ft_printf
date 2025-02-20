#include "ft_printf.h"
#include <stdio.h>


int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;
	va_list	args;

	if (!format)
	{
		return(-1);
	}

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if(format[i] == '%')
		{
			if(format[i + 1] == '%')
			{
				count += ft_print_char('%', 0);
			}
			else if(format[i + 1] == 'c')
			{
				count += ft_print_char(va_arg(args, int), 0);
			}
			else if(format[i + 1] == 's')
			{
				count += ft_print_str(va_arg(args, char *));
			}
			else if(format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				count += ft_print_nbr(va_arg(args, int));
			}
			else if(format[i + 1] == 'u')
			{
				ft_print_unsigned_int(va_arg(args, int));
			}
			else if(format[i + 1] == 'x')
			{
				ft_print_hex(va_arg(args, int), 'x');
			}
			else if(format[i + 1] == 'X')
			{
				ft_print_hex(va_arg(args, int), 'X');
			}
			else if(format[i + 1] == 'p')
			{
				ft_print_pointer(va_arg(args, void *));
			}
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}
