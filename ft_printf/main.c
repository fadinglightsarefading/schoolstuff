#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf(" - %d\n", ft_printf("A string. (14)"));
	printf(" - %d\n", ft_printf("%%"));
	printf(" - %d\n", ft_printf("%c", 'c'));
	printf(" - %d\n", ft_printf("%s", "cheese"));
	printf(" - %d\n", ft_printf("%p", 'a'));
	return (0);
}
