
#ifndef GET_NETXT_LINE
#define GET_NETXT_LINE

// # define FD_MAX 256 
// # define BUF_MAX INT_MAX
# define BUFFER_SIZE 4

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*gnl_remove_trailing_chars(int fd);
char    *get_next_line(int fd);
char	*ft_read(int fd, char *str);
char	*ft_save(char *str);
char	*ft_nextl(char *str);
char	*ft_memadd(char *s1, const char *s2, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void free_str(char **str);
void free_2d_memory(int **array, int row);
#endif