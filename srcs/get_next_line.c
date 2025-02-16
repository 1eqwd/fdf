/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:55:45 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/16 20:35:02 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_memadd(char *s1, const char *s2, size_t size)
{
	char	*str;
	size_t	len;

	if (size == 0)
		return (s1);
	if (!s1)
		len = 0;
	else
		len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + size + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, (const char *)s1, len);
	ft_memcpy(&str[len], s2, size);
	str[len + size] = '\0';
	free(s1);
	return (str);
}

char	*ft_nextl(char *str)
{
	size_t	index;
	size_t	n_flag;
	char	*buf;

	index = 0;
	if (!str[index])
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	n_flag = 0;
	if (str[index] == '\n')
		n_flag = 1;
	buf = (char *)malloc(sizeof(char) * (index + n_flag + 1));
	if (!buf)
		return (NULL);
	ft_memcpy(buf, str, index + n_flag);
	buf[index + n_flag] = '\0';
	return (buf);
}

char	*ft_save(char *str)
{
	size_t	index;
	char	*buf;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (ft_strlen(str) - index));
	if (!buf)
	{
		free(str);
		return (NULL);
	}
	index++;
	ft_memcpy(buf, &str[index], (ft_strlen(str) - index));
	buf[ft_strlen(str) - index] = '\0';
	free(str);
	return (buf);
}

char	*ft_read(int fd, char *str)
{
	char	*buf;
	ssize_t	size;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	size = 1;
	while (size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (free(buf), free(str), NULL);
		str = ft_memadd(str, (const char *)buf, size);
		if (!str)
			return (free(buf), NULL);
		if (str)
		{
			if (ft_strchr(str, '\n'))
				break ;
		}
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_nextl(str);
	str = ft_save(str);
	return (line);
}

// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("./test3.txt", O_RDONLY);
//     if (fd < 0)
//         return 1; 
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd); 
// 	return (0);
// }