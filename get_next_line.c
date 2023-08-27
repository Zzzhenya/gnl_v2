#include "get_next_line.h"

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
		//free (carry);
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
	i = (lb - carry) / sizeof(char);
	temp = malloc(sizeof(char) * (ft_strlen(carry) - i + 1));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, lb + 1, ft_strlen(lb + 1) + 1);
	free(carry);
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*carry;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	carry = read_from_file(fd, carry);
	if (!carry)
		return (NULL);
	line = gnl_get_line(carry);
	carry = gnl_get_carry(carry);
	return (line);
}
