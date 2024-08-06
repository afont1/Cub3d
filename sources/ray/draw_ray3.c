/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:05:25 by bloisel           #+#    #+#             */
/*   Updated: 2024/08/06 21:40:42 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_step_and_side_dist(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->player.x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0
				- data->player.x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->player.y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y
				+ 1.0 - data->player.y) * data->delta_dist_y;
	}
}

void	perform_dda(t_data *data)
{
	data->hit = 0;
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (ft_collision(data, data->map_x, data->map_y))
			data->hit = 1;
	}
}

void	calculate_wall_distance_x(t_data *data)
{
	if (data->side == 0)
	{
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
		if (data->step_x > 0)
		{
			if ((data->map_x > 0
					&& data->map.tab_map[data->map_x - 1][data->map_y] == '3'))
				data->all_img.side_ptr = &data->all_img.door_open;
			else
				data->all_img.side_ptr = &data->all_img.south_wall;
		}
		else
		{
			if ((data->map_x < data->map.width
					&& data->map.tab_map[data->map_x + 1][data->map_y] == '3'))
				data->all_img.side_ptr = &data->all_img.door_open;
			else
				data->all_img.side_ptr = &data->all_img.north_wall;
		}
	}
}
