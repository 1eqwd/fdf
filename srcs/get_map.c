/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:22:05 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/16 21:53:25 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	row_memory(t_data *data, int y)
{
	data->map.height_map[y] = (int *)malloc(sizeof(int) * data->map.width);
	data->map.color_map[y] = (int *)malloc(sizeof(int) * data->map.width);
	if (!data->map.height_map || !data->map.color_map)
		handle_read_error(data, y, ERR_MALLOC);
}

void	put_map(int y, char *line, t_data *data)
{
	char	**split;
	char	*comma_p;
	char	*z;
	int		x;

	split = spe_split(line);
	x = 0;
	while (split[x])
	{
		comma_p = ft_strchr(split[x], ',');
		if (comma_p)
		{
			z = ft_substr(split[x], 0, comma_p - split[x]);
			data->map.height_map[y][x] = ft_atoi(z);
			free(z);
			data->map.color_map[y][x] = hex_str_to_int(comma_p + 1);
		}
		else
		{
			data->map.height_map[y][x] = ft_atoi(split[x]);
			data->map.color_map[y][x] = DEFAULT_COLOR;
		}
		x++;
	}
	free_str(split, data->map.width);
}

void	fill_map(char *filename, t_data *data)
{
	char	*line;
	int		y;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror_and_exit(ERR_FILE);
	y = 0;
	while (y < data->map.height)
	{
		row_memory(data, y);
		line = gnl_remove_trailing_chars(fd);
		if (!line)
			handle_read_error(data, y, ERR_FILE);
		if (data->map.width != get_width_from_line(line))
		{
			free(line);
			handle_read_error(data, y, ERR_FILE);
		}
		put_map(y, line, data);
		free(line);
		y++;
	}
	data->map.height_map[y] = NULL;
	close(fd);
}

void	map_memory(t_data *data)
{
	data->map.height_map = (int **)malloc(sizeof(int *)
			* (data->map.height + 1));
	data->map.color_map = (int **)malloc(sizeof(int *)
			* (data->map.height + 1));
	if (!data->map.height_map || !data->map.color_map)
	{
		if (!data->map.height_map)
			free(data->map.height_map);
		if (!data->map.color_map)
			free(data->map.color_map);
		perror_and_exit(ERR_MALLOC);
	}
}

void	set_map(char *filename, t_data *data)
{
	data->map.width = map_width(filename);
	data->map.height = map_height(filename);
	map_memory(data);
	fill_map(filename, data);
}
