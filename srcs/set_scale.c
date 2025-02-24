/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:44:47 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/15 22:31:57 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calc_isometric(double *x, double *y, int z, t_data *data)
{
	double	original_x;
	double	original_y;

	original_x = *x;
	original_y = *y;
	*x = round((original_x - original_y) * cos(data->view.angle_x));
	*y = round((original_x + original_y) * sin(data->view.angle_y) - z);
}

void	update_min_max(double iso_x, double iso_y, t_data *data)
{
	if (iso_x < data->map.min_x)
		data->map.min_x = iso_x;
	if (iso_x > data->map.max_x)
		data->map.max_x = iso_x;
	if (iso_y < data->map.min_y)
		data->map.min_y = iso_y;
	if (iso_y > data->map.max_y)
		data->map.max_y = iso_y;
}

void	find_min_max_iso(t_data *data)
{
	int		y;
	int		x;
	double	iso_x;
	double	iso_y;

	data->map.min_x = 0;
	data->map.max_x = 0;
	data->map.min_y = 0;
	data->map.max_y = 0;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			iso_x = x;
			iso_y = y;
			calc_isometric(&iso_x, &iso_y, data->map.height_map[y][x]
				* data->view.depth, data);
			update_min_max(iso_x, iso_y, data);
			x++;
		}
		y++;
	}
}

double	calc_scale(t_data *data)
{
	double	scale_x;
	double	scale_y;
	double	scale;
	double	margin;

	margin = 0.9;
	scale_x = WIN_WIDTH * margin / (data->map.max_x - data->map.min_x);
	scale_y = WIN_HEIGHT * margin / (data->map.max_y - data->map.min_y);
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale);
}

void	set_scale(t_data *data)
{
	double	scale;

	find_min_max_iso(data);
	scale = calc_scale(data);
	if (scale < 1)
		scale = 1;
	data->view.scale = scale;
}
