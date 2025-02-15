#include "ft_printf.h"

int	ft_print_number(int number)
{
	int	count_caracter;
	long	copy_number;

	copy_number = number;
	if (copy_number < 0)
	{
		write(1, "-", 1);
		copy_number = copy_number * -1;
		count_caracter = 1;
	}
	if (copy_number > 9)
	{
		ft_print_number(number / 10);
		return (count_caracter + ft_print_caracter(copy_number, 1));
	}
	ft_print_number(number % 10);
	return (count_caracter++);
}


int main()
{
	ft_print_number(-123456);
}