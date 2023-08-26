#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	if (!s)
		return (len);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if(!s)
		return (NULL);
	while (*s != (char)c && *s != '\0')
		s ++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}


char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	char	*ptr;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	else
	{
		ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
		ft_strlcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		free(s1);
		return (ptr);
	}
}

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{	
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (i);
	if (size == 0)
	{
		while (src[i] != '\0')
			i ++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	if (i < size)
		dest [i] = '\0';
	while (src[i] != '\0')
		i ++;
	return (i);
}
