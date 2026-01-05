#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	for (int i = 10; i; i--)
		printf("%s", get_next_line(fd));
	printf("\n");
	return (0);
}
