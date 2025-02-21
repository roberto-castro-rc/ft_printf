#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c, int convert_number);
int	ft_print_str(char *str);
int	ft_print_nbr(int number);
int ft_print_unsigned_int(unsigned int number);
int	ft_print_hex(unsigned long number, char X_or_x);

int	ft_print_pointer(void *pointer);
#endif
