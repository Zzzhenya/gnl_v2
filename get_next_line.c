/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:23:59 by sde-silv          #+#    #+#             */
/*   Updated: 2023/07/31 15:34:40 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_fr(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;

	//if (!s1)
	//	s1 = ft_calloc(1, sizeof(char));
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
	{
		free ((void *)s1);
		free ((void *)s2);
		return (NULL);
	}
	else
	{
		ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
		ft_strlcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		free ((void *)s1);
		return (ptr);
	}
}

char	*read_from_file(int fd, char *line)
{
	char	*buff;
	int		read_bytes;

	buff = 0;
	read_bytes = 1;
	buff = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr_v2(line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free (buff);
			return (NULL);
		}
		ft_strlcpy(line, line, ft_strlen(line) + 1);
		ft_strlcpy(line + ft_strlen(line), buff, ft_strlen(buff) + 1);
		//line = ft_strjoin_fr (line, buff);
		if (read_bytes < BUFFER_SIZE)
			break;	
	}
	free (buff);
	return (line);
}

char	*extract_left(char *line)
{
	char	*ptr;
	char	*lb;
	int		len;

	if (!ft_strlen(line))
		return (NULL);
	lb = ft_strchr_v2(line, '\n');
	if (!lb)
		return (line);
	len = (lb + 2 - line)/ sizeof(char);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, line, len);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*carry_over;
	char		*line;
	char		*temp;
	char		*lb;

	line = 0;
	lb = 0;
	temp = 0;
	if (fd < 0 || BUFFER_SIZE <= 0) 
		return (NULL);
	carry_over = read_from_file(fd, carry_over);
	if (!carry_over)
		return (NULL);
	line = extract_left(carry_over);
	lb = ft_strchr_v2(carry_over, '\n');
	if (lb)
	{
		temp = ft_calloc(ft_strlen(lb), sizeof(char));
		if (!temp)
			return (NULL);
		ft_strlcpy(temp, lb + 1, ft_strlen(lb));
		free (carry_over);
		carry_over = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
		if(!carry_over)
			return (NULL);
		ft_strlcpy(carry_over, temp, ft_strlen(temp) +1);
		free(temp);
	}
	else
		return (NULL);
	return (line);
}