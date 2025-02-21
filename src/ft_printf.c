/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:32:20 by rpaulo-c          #+#    #+#             */
/*   Updated: 2025/02/21 16:32:20 by rpaulo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_ifs(char format, va_list *args)
{
	int	count;

	count = 0;
	if (format == '%')
		count += ft_print_char('%', 0);
	else if (format == 'c')
		count += ft_print_char(va_arg(*args, int), 0);
	else if (format == 's')
		count += ft_print_str(va_arg(*args, char *));
	else if (format == 'd' || format == 'i')
		count += ft_print_nbr(va_arg(*args, int));
	else if (format == 'u')
		count += ft_print_unsigned_int(va_arg(*args, int));
	else if (format == 'x')
		count += ft_print_hex(va_arg(*args, unsigned int), 'x');
	else if (format == 'X')
		count += ft_print_hex(va_arg(*args, unsigned int), 'X');
	else if (format == 'p')
		count += ft_print_pointer(va_arg(*args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += ft_printf_ifs(format[i + 1], &args);
			i += 2;
			continue ;
		}
			count += ft_print_char(format[i], 0);
			i++;
	}
	va_end(args);
	return (count);
}
