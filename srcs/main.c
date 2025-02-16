/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:56:42 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/16 23:08:42 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_ac(int ac)
{
	if (ac != 2)
		perror_and_exit(ERR_ARGS);
}

void	initialize(t_data *data)
{
	data->point.center_x = WIN_WIDTH / 2;
	data->point.center_y = WIN_HEIGHT / 2;
	data->view.depth = 1;
	data->view.angle_x = ANGLE_30;
	data->view.angle_y = ANGLE_30;
	data->view.offset_x = 0;
	data->view.offset_y = 0;
	data->view.scale = 1;
}

int	press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		if (data->mlx.img)
			mlx_destroy_image(data->mlx.mlx, data->mlx.img);
		if (data->mlx.win)
			mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		if (data->mlx.mlx)
			mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
		map_free(data);
		exit(0);
	}
	return (0);
}

int	x_botton(t_data *data)
{
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	if (data->mlx.mlx)
		mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
	map_free(data);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_ac(ac);
	check_file(av[1]);
	initialize(&data);
	init_mlx(&data);
	set_map(av[1], &data);
	set_scale(&data);
	set_offset(&data);
	draw_map(&data);
	mlx_key_hook(data.mlx.win, press, &data);
	mlx_hook(data.mlx.win, DESTROY_NOTIFY, 1L << 17, x_botton, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
