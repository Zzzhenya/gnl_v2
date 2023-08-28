/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:10:09 by sde-silv          #+#    #+#             */
/*   Updated: 2023/08/28 15:11:56 by sde-silv         ###   ########.fr       */
/*                                                  	                          */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include "get_next_line.h"
//#include "get_next_line_bonus.h"

char	*print_line(int fd, int i, char	*ptr)
{
	printf("[%i]:%i:%s", fd, i, ptr);
	free(ptr);
	ptr = NULL;
	return (ptr);
}

void	open_and_read(char	*file)
{
	int		fd;
	char	*ptr;
	int		i;

	fd = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		fd = 0;
	i = 1;
	while (1)
	{
		ptr = get_next_line(fd);
		if (ptr == NULL)
			break ;
		ptr = print_line(fd, i, ptr);
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
			ptr1 = print_line(fd1, i, ptr1);
		if (ptr2)
			ptr2 = print_line(fd2, i, ptr2);
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
