#include <stdio.h>
#include "src/ft_printf.h"

int main() {
	int num = -42;
	char ch = 'A';
	char str[] = "Hello";

	ft_printf("Hello, World!\n");

	// Integers
	ft_printf("Decimal: %d\n", num);
	ft_printf("Hexadecimal: %x\n", num);
	printf("HEXA no printf %x\n", num);
	ft_printf("Unsigned: %u\n", num);

	// Characters and strings
	ft_printf("Character: %c\n", ch);
	ft_printf("String: %s\n", str);

	// Pointers
	ft_printf("Pointer: %p\n", (void*)&num);

	return 0;
}