/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:12:17 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/15 22:10:09 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_invalid_file(char *filename)
{
	int	fd;
	int	buf[1];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	if (read(fd, buf, 1) < 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

void	put_invalid_file(const char *msg)
{
	ft_putstr_fd((char *)msg, 2);
	exit(1);
}

void	perror_and_exit(const char *msg)
{
	perror(msg);
	exit(1);
}

void	handle_read_error(t_data *data, int row, const char *error_message)
{
	free_2d_memory(data->map.height_map, row + 1);
	free_2d_memory(data->map.color_map, row + 1);
	perror_and_exit(error_message);
}
