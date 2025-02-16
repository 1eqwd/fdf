/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:37:37 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/15 22:43:03 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset_gnl(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror_and_exit(ERR_FILE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

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

void	free_str(char **str, int x_len)
{
	x_len -= 1;
	while (x_len >= 0)
	{
		free(str[x_len]);
		x_len--;
	}
	free(str);
}

void	free_2d_memory(int **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
