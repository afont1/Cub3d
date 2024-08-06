/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:48:20 by afont             #+#    #+#             */
/*   Updated: 2024/08/06 21:20:34 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_floor_params(t_data *data)
{
	data->ray_dir_x0 = data->player.dir_x - data->player.plane_x;
	data->ray_dir_y0 = data->player.dir_y - data->player.plane_y;
	data->ray_dir_x1 = data->player.dir_x + data->player.plane_x;
	data->ray_dir_y1 = data->player.dir_y + data->player.plane_y;
	data->p = data->y - WIN_HEIGHT / 2;
	data->player_z = 0.5 * WIN_HEIGHT;
	data->row_distance = data->player_z / data->p;
	data->floor_step_x = data->row_distance * (data->ray_dir_x1
			- data->ray_dir_x0) / WIN_WIDTH;
	data->floor_step_y = data->row_distance * (data->ray_dir_y1
			- data->ray_dir_y0) / WIN_WIDTH;
	data->floor_x = data->player.x + data->row_distance * data->ray_dir_x0;
	data->floor_y = data->player.y + data->row_distance * data->ray_dir_y0;
}

void	render_floor_and_ceiling(t_data *data)
{
	data->x = -1;
	while (++data->x < WIN_WIDTH)
	{
		data->texture_x = (int)(JSP * (data->floor_x
					- (int)data->floor_x)) & (JSP - 1);
		data->texture_y = (int)(JSP * (data->floor_y
					- (int)data->floor_y)) & (JSP - 1);
		data->floor_x += data->floor_step_x;
		data->floor_y += data->floor_step_y;
		data->color = ft_get_color(&data->all_img.floor,
				data->texture_x, data->texture_y);
		ft_pixel_put(data->all_img.env_img, data->x, data->y, data->color);
		data->color = ft_get_color(&data->all_img.ceiling,
				data->texture_x, data->texture_y);
		ft_pixel_put(data->all_img.env_img, data->x,
			WIN_HEIGHT - data->y, data->color);
	}
}

void	initialize_ray_params(t_data *data)
{
	data->camera_x = 2 * data->x / (double)WIN_WIDTH - 1;
	data->ray_dir_x = (data->player.dir_x
			+ data->player.plane_x * data->camera_x);
	data->ray_dir_y = (data->player.dir_y
			+ data->player.plane_y * data->camera_x);
	data->map_x = (int)data->player.x;
	data->map_y = (int)data->player.y;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->ray_dir_y);
}

void	ft_draw_ray(t_data *data)
{
	data->y = WIN_HEIGHT / 2;
	while (++data->y < WIN_HEIGHT)
	{
		calculate_floor_params(data);
		render_floor_and_ceiling(data);
	}
	data->x = -1;
	while (++data->x < WIN_WIDTH)
	{
		initialize_ray_params(data);
		calculate_step_and_side_dist(data);
		perform_dda(data);
		calculate_wall_distance_and_texture(data);
		render_wall(data);
	}
}
