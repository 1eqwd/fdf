/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:16:53 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/15 22:34:31 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_offset(t_data *data)
{
	double	map_width;
	double	map_height;

	map_width = (data->map.max_x - data->map.min_x) * data->view.scale;
	map_height = (data->map.max_y - data->map.min_y) * data->view.scale;
	data->view.offset_x = (((WIN_WIDTH - map_width) / 2)
			- (data->map.min_x * data->view.scale));
	data->view.offset_y = (((WIN_HEIGHT - map_height) / 2)
			- (data->map.min_y * data->view.scale));
}
