#include "get_next_line_bonus.h"

char	*read_from_file(int fd, char *carry)
{
	char	*ptr;
	int		bytes;

	bytes = 42;
	ptr = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!ptr)
		return (NULL);
	while (bytes != 0 && !ft_strchr(carry, '\n'))
	{
		bytes = read(fd, ptr, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (carry);
			free (ptr);
			return (NULL);
		}
		ptr[bytes] = '\0';
		carry = ft_strjoin(carry, ptr);
	}
	free (ptr);
	return (carry);
}

char	*gnl_get_line(char	*carry)
{
	int		i;
	char	*line;
	char	*lb;

	i = 0;
	if (carry[0] == '\0')
		return (NULL);
	lb = ft_strchr(carry, '\n');
	if (lb)
		i = ((lb - carry) / sizeof(char)) + 1;
	else
		i = ft_strlen(carry);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
	{
		return (NULL);
	}
	ft_strlcpy(line, carry, i + 1);
	return (line);
}

char	*gnl_get_carry(char	*carry)
{
	int		i;
	char	*temp;
	char	*lb;

	i = 0;
	if (!ft_strchr(carry, '\n'))
	{
		free (carry);
		return (NULL);
	}
	lb = ft_strchr(carry, '\n');
	i = ft_strlen(lb + 1) + 1;
	temp = malloc(sizeof(char) * i);
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, lb + 1, i);
	free(carry);
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*carry[2560];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 2560)
		return (NULL);
	carry[fd] = read_from_file(fd, carry[fd]);
	if (!carry[fd])
		return (NULL);
	line = gnl_get_line(carry[fd]);
	carry[fd] = gnl_get_carry(carry[fd]);
	return (line);
}
