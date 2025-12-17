#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	printf(" - %d\n", ft_printf("A string. (14)"));
	printf(" - %d\n", printf("A string. (14)"));
	printf(" - %d\n", ft_printf("%%"));
	printf(" - %d\n", printf("%%"));
	printf(" - %d\n", ft_printf("%c", 'c'));
	printf(" - %d\n", printf("%c", 'c'));
	printf(" - %d\n", ft_printf("%s", "cheese"));
	printf(" - %d\n", printf("%s", "cheese"));
	printf(" - %d\n", ft_printf("%p", "a"));
	printf(" - %d\n", printf("%p", "a"));

	printf(" - %d\n", ft_printf("%x", 100));
	printf(" - %d\n", printf("%x", 100));

	printf(" - %d\n", ft_printf("%X", 100));
	printf(" - %d\n", printf("%X", 100));

	printf(" - %d\n", ft_printf("%u", UINT_MAX));
	printf(" - %d\n", printf("%u", UINT_MAX));
	return (0);
}
