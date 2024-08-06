/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:55:12 by bloisel           #+#    #+#             */
/*   Updated: 2024/08/06 21:33:48 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_wall_distance_y(t_data *data)
{
	if (data->side == 1)
	{
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
		if (data->step_y > 0)
		{
			if ((data->map_y > 0
					&& data->map.tab_map[data->map_x][data->map_y - 1] == '3'))
				data->all_img.side_ptr = &data->all_img.door_open;
			else
				data->all_img.side_ptr = &data->all_img.west_wall;
		}
		else
		{
			if ((data->map_y < data->map.height
					&& data->map.tab_map[data->map_x][data->map_y + 1] == '3'))
				data->all_img.side_ptr = &data->all_img.door_open;
			else
				data->all_img.side_ptr = &data->all_img.east_wall;
		}
	}
}

void	calculate_wall_params(t_data *data)
{
	data->line_height = (int)(WIN_HEIGHT / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + WIN_HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + WIN_HEIGHT / 2;
	if (data->draw_end >= WIN_HEIGHT)
		data->draw_end = WIN_HEIGHT - 1;
	if (data->side == 0)
		data->wall_x = data->player.y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = data->player.x + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= floor(data->wall_x);
}

void	calculate_texture_params(t_data *data)
{
	data->tex_x = (int)(data->wall_x * (double)JSP);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = JSP - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = JSP - data->tex_x - 1;
	data->step = 1.0 * JSP / data->line_height;
	data->tex_pos = (data->draw_start
			- WIN_HEIGHT / 2 + data->line_height / 2) * data->step;
}

void	calculate_wall_distance_and_texture(t_data *data)
{
	calculate_wall_distance_x(data);
	calculate_wall_distance_y(data);
	calculate_wall_params(data);
	calculate_texture_params(data);
}

void	render_wall(t_data *data)
{
	data->y = data->draw_start - 1;
	while (++data->y < data->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (JSP - 1);
		data->tex_pos += data->step;
		data->color = ft_check_color(data, data->map_x, data->map_y);
		ft_pixel_put(data->all_img.env_img, data->x, data->y, data->color);
	}
}
