#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	char *line;
	int fd;

	printf("\n====================\nTEST1\n====================\n\n");
	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
/*
	printf("\n====================\nTEST2\n====================\n\n");
	fd = open("test1.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);

	printf("\n====================\nTEST3\n====================\n\n");
	fd = open("test2.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
*/
	printf("\n====================\nTEST4\n====================\n\n");
	fd = open("test3.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
