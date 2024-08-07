/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_environement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:21:53 by afont             #+#    #+#             */
/*   Updated: 2024/08/07 17:04:08 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_sort_dist(t_data *data, t_coord dist, double ray_angle, int nbr_ray)
{
	(void)ray_angle;
	if (dist.x < dist.y)
	{
		ft_init_wall(data, fish_eye(data, ray_angle, dist.x), nbr_ray, 0);
		data->ray_data[nbr_ray].rx = data->ray_coord.vx;
		data->ray_data[nbr_ray].ry = data->ray_coord.vy;
	}
	else
	{
		ft_init_wall(data, fish_eye(data, ray_angle, dist.y), nbr_ray, 1);
		data->ray_data[nbr_ray].rx = data->ray_coord.hx;
		data->ray_data[nbr_ray].ry = data->ray_coord.hy;
	}
}

void	ft_init_wall(t_data *data, double dist_t, int nbr_ray, int is_vertical)
{
	float	line_height;

	line_height = ((WIN_HEIGHT / dist_t)) * data->player.fov_factor;
	data->ray_data[nbr_ray].ty_step = JSP / line_height;
	data->ray_data[nbr_ray].ty_offset = 0;
	if (line_height > WIN_HEIGHT)
	{
		data->ray_data[nbr_ray].ty_offset = ((line_height - (WIN_HEIGHT)) / 2);
		line_height = WIN_HEIGHT;
	}
	data->ray_data[nbr_ray].line_height = line_height;
	data->ray_data[nbr_ray].is_vertical = is_vertical;
}

void	ft_draw_environement(t_data *data, t_img *env_img, int k, double off)
{
	int	i;

	if (off <= 0)
		off = 0;
	ft_draw_roof(data, env_img, k, off);
	i = ft_draw_wall(data, env_img, k, off);
	ft_draw_floor(data, env_img, k, i + off);
}
