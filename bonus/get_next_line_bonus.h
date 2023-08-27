#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
size_t	ft_strlen(const char *s);

#endif