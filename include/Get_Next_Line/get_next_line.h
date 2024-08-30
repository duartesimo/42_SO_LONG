#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 100
# endif

int		ft_strlen2(char *s);
char	*ft_strchr2(char *s, int c);
char	*ft_strjoin2(char *line, char *buff);
char	*raw_line(int fd, char *line);
char	*trimmed_line(char *line);
char	*new_line(char *line);
char	*get_next_line(int fd);

#endif
