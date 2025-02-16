/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:43:29 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/16 23:15:20 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hex_str_to_int(char *hex)
{
	int	len;
	int	base;
	int	decimal;

	len = ft_strlen(hex)- 1;
	base = 1;
	decimal = 0;
	while (len >= 0)
	{
		if (hex[len] >= '0' && hex[len] <= '9')
			decimal += (hex[len] - '0') * base;
		if (hex[len] >= 'A' && hex[len] <= 'F')
			decimal += (hex[len] - 'A' + 10) * base;
		if (hex[len] >= 'a' && hex[len] <= 'f')
			decimal += (hex[len] - 'a' + 10) * base;
		base *= 16;
		len--;
	}
	return (decimal);
}

int	map_height(char *filename)
{
	int		height;
	int		fd;
	char	*line;

	reset_gnl(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror_and_exit(ERR_FILE);
	height = 0;
	line = gnl_remove_trailing_chars(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = gnl_remove_trailing_chars(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	map_width(char *filename)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror_and_exit(ERR_FILE);
	line = gnl_remove_trailing_chars(fd);
	width = get_width_from_line(line);
	free(line);
	close(fd);
	return (width);
}

char	**spe_split(char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (!split)
		perror_and_exit(ERR_MALLOC);
	return (split);
}

void map_free(t_data *data)
{
	int i;

	i = 0;
	while(i < data->map.height)
	{
		free(data->map.height_map[i]);
		free(data->map.color_map[i]);
		i++;
	}
	free(data->map.height_map);
	free(data->map.color_map);
}
