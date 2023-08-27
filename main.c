#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "get_next_line.h"
//#include "get_next_line_bonus.h"

void	open_and_read(char	*file)
{
	int		fd;
	char	*ptr;
	int		i;

	fd = 1;
	fd = open(file, O_RDONLY);
	i = 1;
	while (1)
	{
		ptr = get_next_line(fd);
		if (ptr == NULL)
			break ;
		printf("[%i]:%i:%s", fd, i, ptr);
		free(ptr);
		ptr = NULL;
		i++;
	}
	close (fd);
}

void	open_read_two(char	*file1, char	*file2)
{
	int		fd1;
	int		fd2;
	char	*ptr1;
	char	*ptr2;
	int		i;

	fd1 = open(file1, O_RDONLY);
	fd2 = open(file2, O_RDONLY);
	i = 1;
	while (1)
	{
		ptr1 = get_next_line(fd1);
		ptr2 = get_next_line(fd2);
		if (ptr1 == NULL && ptr2 == NULL)
			break ;
		if (ptr1)
		{
			printf("[%i]:%i:%s", fd1, i, ptr1);
			free(ptr1);
			ptr1 = NULL;
		}
		if (ptr2)
		{
			printf("[%i]:%i:%s", fd2, i, ptr2);
			free(ptr2);
			ptr2 = NULL;
		}
		i++;
	}
	close(fd1);
	close(fd2);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		printf("Where's the text file?\n");
	else if (argc == 2)
	{
		open_and_read(argv[1]);
	}
	else if (argc == 3)
	{
		open_read_two(argv[1], argv[2]);
	}
	else
		printf("Too many arguments. Can't argue all day!\n");
	return (0);
}
