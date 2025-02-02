#include <stdio.h>

int main() {
	int num = 42;
	float fnum = 3.14159;
	char ch = 'A';
	char str[] = "Hello";

	printf("Hello, World!\n");

	// Integers
	printf("Decimal: %+04d\n", num);
	printf("Hexadecimal: %#x\n", num);
	printf("Octal: %#o\n", num);
	printf("Unsigned: %u\n", num);

	// Floats
	printf("Float (default): %f\n", fnum);
	printf("Float (precision): %.2f\n", fnum);
	printf("Float (scientific): %e\n", fnum);
	printf("Float (hexadecimal): %a\n", fnum);
	20
	// Characters and strings
	printf("Character: %c\n", ch);
	printf("String: %s\n", str);

	// Pointers
	printf("Pointer: %p\n", (void*)&num);

	// Width and alignment
	printf("Width (right align): %10d\n", num);
	printf("Width (left align): %-10d\n", num);

	return 0;
}