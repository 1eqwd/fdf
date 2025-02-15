/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:50:34 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/13 17:00:38 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void coordinate(t_data *data)
{
    int z0;
    int z1;

    z0 = (data->map.height_map[(int)data->point.y0][(int)data->point.x0]
        * data->view.depth * data->view.scale);
    z1 = (data->map.height_map[(int)data->point.y1][(int)data->point.x1]
         * data->view.depth * data->view.scale);
    // printf("z0 %d z1 %d\n",z0,z1);
    data->point.x0 *= data->view.scale;
    data->point.y0 *= data->view.scale;
    data->point.x1 *= data->view.scale;
    data->point.y1 *= data->view.scale;
    calc_isometric(&data->point.x0, &data->point.y0, z0, data);
    calc_isometric(&data->point.x1, &data->point.y1, z1, data);
    // printf("x0 %f y0 %f x1 %f y1 %f\n", data->point.x0, data->point.y0, data->point.x1, data->point.y1);
    data->point.x0 += data->view.offset_x;
    data->point.y0 += data->view.offset_y;
    data->point.x1 += data->view.offset_x;
    data->point.y1 += data->view.offset_y;
}

void	calc_line_steps(t_data *data)
{
	double	delta_x;
	double	delta_y;
	double	step_x;
	double	step_y;
	double	max_v;

    coordinate(data);
	delta_x = fabs(data->point.x1 - data->point.x0);
	delta_y = fabs(data->point.y1 - data->point.y0);
	if (delta_x < delta_y)
		max_v = delta_y;
	else
		max_v = delta_x;
	step_x = (data->point.x1 - data->point.x0) / max_v;
	step_y = (data->point.y1 - data->point.y0) / max_v;
	while ((int)(data->point.x0 - data->point.x1) || ((int)(data->point.y0
				- data->point.y1)))
	{
		my_mlx_pixel_put(data, data->point.x0, data->point.y0,
			data->point.color);
		data->point.x0 += step_x;
		data->point.y0 += step_y;
	}
}


void set_point(int x, int y, t_data *data, int flag)
{
    if (flag == HORIZONTAL)
    {
        data->point.x0 = x;
        data->point.x1 = x + 1;
        data->point.y0 = y;
        data->point.y1 = y;
    }
    if (flag == VERTICAL)
    {
        data->point.x0 = x;
        data->point.x1 = x;
        data->point.y0 = y;
        data->point.y1 = y + 1;
    }
    calc_line_steps(data);
}

void draw_map(t_data *data)
{
    int y;
    int x;

    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width)
        {
            if ((x >= 0 && x < data->map.width) && (y >= 0 && y < data->map.height))
            {
                data->point.color = data->map.color_map[y][x];
                if(x < data->map.width - 1)
                    set_point(x, y, data, HORIZONTAL);
                if (y < data->map.height -1)
                    set_point(x, y, data, VERTICAL);
                
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	display_info(data);
}