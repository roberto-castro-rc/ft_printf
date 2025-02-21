/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:00:33 by rpaulo-c          #+#    #+#             */
/*   Updated: 2025/02/21 15:00:33 by rpaulo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int number)
{
	long	copy_number;
	int		count_caracter;

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
