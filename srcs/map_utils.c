/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:43:29 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/13 21:21:28 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hex_str_to_int(char *hex)
{
	int	len;
	int	base;
	int	decimal;

	len = ft_strlen(hex) - 1;
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

int map_height(char *filename)
{
    int height;
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        perror_and_exit(ERR_FILE);
    height = 0;
    while (get_next_line(fd) != NULL)
        height++;
    close(fd);
    return (height);
}

int map_width(char *filename)
{
    char **line;
    int x_len;
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        perror_and_exit(ERR_FILE);
    line = ft_split(get_next_line(fd), ' ');
    if (!line)
        perror_and_exit(ERR_MALLOC);
    x_len = 0;
    while (line[x_len])
        x_len++;
    free(line);
    close(fd);
    return (x_len);
}