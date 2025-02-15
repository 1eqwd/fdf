/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:56:42 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/13 21:27:29 by sumedai          ###   ########.fr       */
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

int press(int keycode, t_data *var)
{
	if (!var)
		return (0);
	if (keycode == ESC_KEY)
	{
		mlx_clear_window(var->mlx.mlx, var->mlx.win);
		exit(0);
	}
	return (0);
}

int x_botton(t_data *var)
{
	if (!var)
		return (0);
	mlx_destroy_window(var->mlx.mlx, var->mlx.win);
	exit(0);
	return(0);
}


int	main(int ac, char **av)
{
	t_data	data;

	check_ac(ac);
	check_file(av[1]);
	initialize(&data);
	init_mlx(&data);
	// printf("%p %p\n",data.mlx.mlx, data.mlx.win);
	set_map(av[1], &data);
	// for (int i = 0; i < data.map.height; i++)
	// {
	// 	for (int j = 0; j < data.map.width; j++)
	// 		printf("(%d, %d, %d, 0x%x)\n",i, j, data.map.height_map[i][j], data.map.color_map[i][j]);
	// }
	set_scale(&data);
	set_offset(&data);
	// printf("scale:%f offset_x:%f offset_y:%f\n",data.view.scale , data.view.offset_x, data.view.offset_y);
	draw_map(&data);
	mlx_key_hook(data.mlx.win, press, &data);
	mlx_hook(data.mlx.win, DESTROY_NOTIFY, 1L << 17, x_botton, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}