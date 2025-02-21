/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:54:45 by rpaulo-c          #+#    #+#             */
/*   Updated: 2025/02/21 14:54:45 by rpaulo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_int(unsigned int number)
{
	int	count;

	count = 0;
	if (number > 9)
		count += ft_print_unsigned_int(number / 10);
	count += ft_print_char(number % 10, 1);
	return (count);
}
