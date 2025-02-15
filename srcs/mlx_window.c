/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:08:41 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/13 16:33:27 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_info(t_data *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx.mlx;
	win = data->mlx.win;
	mlx_string_put(mlx, win, 50, y += 10, TEXT_COLOR, "To exit");
	mlx_string_put(mlx, win, 50, y += 20, TEXT_COLOR, "Press the close button or ESC");
}


void init_mlx(t_data *data)
{
    data->mlx.mlx = mlx_init();
    data->mlx.win = mlx_new_window(data->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
    data->mlx.img = mlx_new_image(data->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
    data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// printf("Drawing pixel at (%d, %d) with color %d\n", x, y, color);
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = data->mlx.addr + ((y * data->mlx.line_length)
			+ (x * (data->mlx.bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}