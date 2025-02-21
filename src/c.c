#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main() {
	int num = -1;
	char ch = 'A';
	char str[] = "Hello";



	// Pointers
	printf("%s", NULL);
	printf("retorno ft_printf %d", ft_printf("pointer max-ft: %x\n", LONG_MAX));
		printf("\n");
	printf("retorno original printf: %d", printf("pointer max-pf: %x\n", LONG_MAX));
		printf("\n");
	printf("retorno ft %d", ft_printf("min ft: %x\n", LONG_MIN));
		printf("\n");
	printf("retorno original: %d", printf("min pf: %x\n", LONG_MIN));
		printf("\n");
	printf("retorno ft %d", ft_printf("pointer min-u ft: %x\n", LONG_MIN));
		printf("\n");
	printf("retorno original: %d", printf("pointer min-u pf: %x\n", LONG_MIN));
		printf("\n");
	return 0;
}
