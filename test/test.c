//gcc -o test test.c -L../ -lft -I../inc
#include "libft.h"
#include "ft_printf.h"

int main() {
	int num = 123;
	char ch = 'A';

	ft_printf("Hello %d %c \t .\n", num, ch);
	ft_exit("bye!\n");
	return 0;
}
