/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:48:20 by afont             #+#    #+#             */
/*   Updated: 2024/06/28 08:44:52 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_ray(t_data *data)
{
	int		nbr_ray;
	double	ray_angle;
	double	one_dr;
	t_coord	dist;

	ray_angle = data->player.angle - ONE_DR * (data->player.fov / 2);
	ray_angle = ft_angle_loop(ray_angle);
	nbr_ray = -1;
	one_dr = ONE_DR / (WIN_WIDTH / data->player.fov);
	while (++nbr_ray < WIN_WIDTH)
	{
		dist.x = ft_vertical_ray(data, ray_angle);
		dist.y = ft_horizontal_ray(data, ray_angle);
		ft_sort_dist(data, dist, ray_angle, nbr_ray);
		data->ray_data[nbr_ray].ray_angle = ray_angle;
		ray_angle += one_dr;
		ray_angle = ft_angle_loop(ray_angle);
	}
}

double	ft_horizontal_ray(t_data *data, double ray_angle)
{
	int		dof;
	t_pos	map_coord;
	t_coord	ray_coord;
	t_coord	offset;

	dof = -1;
	ft_horizontal_var(data, &ray_coord, &offset, ray_angle);
	while (++dof < data->map.height)
	{
		map_coord.y = (int)(ray_coord.y) / JSP;
		map_coord.x = (int)(ray_coord.x) / JSP;
		if (map_coord.x < data->map.width && map_coord.y < data->map.height \
		&& map_coord.x >= 0 && map_coord.y >= 0 && data->map.tab_map \
		[map_coord.y][map_coord.x] == '1')
		{
			data->ray_coord.hx = ray_coord.x;
			data->ray_coord.hy = ray_coord.y;
			return (ft_dist(data->player.pos.x, data->player.pos.y, \
			ray_coord.x, ray_coord.y));
		}
		ray_coord.x += offset.x;
		ray_coord.y += offset.y;
	}
	return (__DBL_MAX__);
}

double	ft_vertical_ray(t_data *data, double ray_angle)
{
	int		dof;
	t_pos	map_coord;
	t_coord	ray_coord;
	t_coord	offset;

	dof = -1;
	ft_vertical_var(data, &ray_coord, &offset, ray_angle);
	while (++dof < data->map.width)
	{
		map_coord.x = (int)(ray_coord.x) / JSP;
		map_coord.y = (int)(ray_coord.y) / JSP;
		if (map_coord.x < data->map.width && map_coord.y < data->map.height \
		&& map_coord.x >= 0 && map_coord.y >= 0 && data->map.tab_map \
		[map_coord.y][map_coord.x] == '1')
		{
			data->ray_coord.vx = ray_coord.x;
			data->ray_coord.vy = ray_coord.y;
			return (ft_dist(data->player.pos.x, data->player.pos.y, \
			ray_coord.x, ray_coord.y));
		}
		ray_coord.x += offset.x;
		ray_coord.y += offset.y;
	}
	return (__DBL_MAX__);
}

double	fish_eye(t_data *data, double ray_angle, double dist_t)
{
	double	fish_eye;

	fish_eye = data->player.angle - ray_angle;
	fish_eye = ft_angle_loop(fish_eye);
	dist_t *= cos(fish_eye);
	return (dist_t);
}
