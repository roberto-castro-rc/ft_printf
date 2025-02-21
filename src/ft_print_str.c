/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:55:20 by rpaulo-c          #+#    #+#             */
/*   Updated: 2025/02/21 14:55:20 by rpaulo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count = write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
