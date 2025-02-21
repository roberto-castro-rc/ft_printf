#include "ft_printf.h"
#include <stdio.h>


int	ft_print_pointer(void *pointer)
{
	int				count;
	unsigned long	address;

	address = (unsigned long)pointer;
	count = 0;
	if (address == 0)
	{
		count += ft_print_str("(nil)");
		return (count);
	}
	else
	{
		count += ft_print_str("0x");
	}
	count += ft_print_hex(address, 'x');
	return (count);
}

// int main()
// {
// 	unsigned long pointer = 0x123456789abcdef;
// 	printf("pointer: %p\n", 16);
// 	ft_print_pointer(16);
// 	return (0);
// }
