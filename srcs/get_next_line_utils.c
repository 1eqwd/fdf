
#include "../includes/fdf.h"

int	get_width_from_line(char *line)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
		{
			width++;
			while (line[i] != ' ' && line[i] != '\0')
				i++;
		}
		else
		{
			while (line[i] == ' ' && line[i] != '\0')
				i++;
		}
	}
	return (width);
}

char	*gnl_remove_trailing_chars(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == ' '))
	{
		line[len - 1] = '\0';
		len--;
	}
	return (line);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	if ((char)c == '\0')
		return ((char *)&s[index]);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	if (dst == src)
		return (dst);
	index = 0;
	while (index < n)
	{
		((char *)dst)[index] = ((char *)src)[index];
		index++;
	}
	return (dst);
}

void free_str(char **str)
{
	while (*str)
	{
		free(*str);
		str++;
	}
}

void free_2d_memory(int **array, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}