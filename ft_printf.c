#include "ft_printf.h"
#include <stdio.h>


int	ft_printf(char *format, ...)
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
				write(1, "%%", 1);
			}
			else if(format[i + 1] == 'd' || format[i + 1] == 'i')
			{

			}
			else if(format[i + 1] == 'u')
			{

			}
			else if(format[i + 1] == 'c')
			{

			}
			else if(format[i + 1] == 's')
			{

			}
			else if(format[i + 1] == 'x' || format[i + 1] == 'X')
			{

			}
		}
		else
			write(1, &format[i], 1);
		i++;
	}



}
