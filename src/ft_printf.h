/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:56:21 by rpaulo-c          #+#    #+#             */
/*   Updated: 2025/02/21 14:56:21 by rpaulo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c, int convert_number);
int	ft_print_str(char *str);
int	ft_print_nbr(int number);
int	ft_print_unsigned_int(unsigned int number);
int	ft_print_hex(unsigned long number, char X_or_x);
int	ft_print_pointer(void *pointer);

#endif
