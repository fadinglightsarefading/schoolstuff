#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	haystack[30] = "aaabcabcd";
	printf("%s\n", ft_strnstr(haystack, "a", 1));
	return (0);
}
