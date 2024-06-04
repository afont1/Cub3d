/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:48:20 by afont             #+#    #+#             */
/*   Updated: 2024/06/04 10:34:36 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_ray(t_data *data)
{
	int		nbr_ray;
	double	ray_angle;
	double	dist_h;
	double	dist_v;

	ray_angle = data->player.angle - ONE_DR * FOV / 2;
	ray_angle = ft_angle_loop(ray_angle);
	nbr_ray = -1;
	while (++nbr_ray < FOV)
	{
		dist_h = ft_horizontal_ray(data, ray_angle);
		dist_v = ft_vertical_ray(data, ray_angle);
		if (dist_v < dist_h)
		{
			ft_init_wall(data, fish_eye_correction(data, ray_angle, dist_v), \
			nbr_ray, 0);
			// ft_draw_line(data, ray_angle, dist_v);
		}
		if (dist_h < dist_v)
		{
			ft_init_wall(data, fish_eye_correction(data, ray_angle, dist_h), \
			nbr_ray, 1);
			// ft_draw_line(data, ray_angle, dist_h);
		}
		ray_angle += ONE_DR;
		ray_angle = ft_angle_loop(ray_angle);
	}
	ft_draw_wall(data);
}

double	ft_horizontal_ray(t_data *data, double ray_angle)
{
	int		dof;
	t_pos	map_coord;
	t_coord	ray_coord;
	t_coord	offset;

	dof = -1;
	if (ft_horizontal_var(data, &ray_coord, &offset, ray_angle))
	{
		while (++dof < data->map.width)
		{
			map_coord.y = (int)(ray_coord.y) / (WIN_HEIGHT / data->map.width);
			map_coord.x = (int)(ray_coord.x) / (WIN_HEIGHT / data->map.width);
			if (map_coord.x < data->map.width && map_coord.y < data->map.width \
			&& map_coord.x >= 0 && map_coord.y >= 0 && data->map.tab_map \
			[map_coord.y][map_coord.x] == '1')
				return (ft_dist(data->player.pos.x, data->player.pos.y, \
				ray_coord.x, ray_coord.y));
			ray_coord.x += offset.x;
			ray_coord.y += offset.y;
		}
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
	if (ft_vertical_var(data, &ray_coord, &offset, ray_angle))
	{
		while (++dof < data->map.width)
		{
			map_coord.x = (int)(ray_coord.x) / (WIN_HEIGHT / data->map.width);
			map_coord.y = (int)(ray_coord.y) / (WIN_HEIGHT / data->map.width);
			if (map_coord.x < data->map.width && map_coord.y < data->map.width \
			&& map_coord.x >= 0 && map_coord.y >= 0 && data->map.tab_map \
			[map_coord.y][map_coord.x] == '1')
				return (ft_dist(data->player.pos.x, data->player.pos.y, \
				ray_coord.x, ray_coord.y));
			ray_coord.x += offset.x;
			ray_coord.y += offset.y;
		}
	}
	return (__DBL_MAX__);
}

double	fish_eye_correction(t_data *data, double ray_angle, double dist_t)
{
	double	fish_eye;

	fish_eye = data->player.angle - ray_angle;
	if (fish_eye < 0)
		fish_eye += 2 * M_PI;
	if (fish_eye > 2 * M_PI)
		fish_eye -= 2 * M_PI;
	dist_t *= cos(fish_eye);
	return (dist_t);
}

// void	ft_draw_line(t_data *data, double ray_angle, double dist_t)
// {
// 	int	x0 = data->player.pos.x;
// 	int	y0 = data->player.pos.y;
// 	int	x1 = x0 + dist_t * cos(ray_angle);
// 	int	y1 = y0 + dist_t * sin(ray_angle);

// 	int dx = abs(x1 - x0);
// 	int sx = x0 < x1 ? 1 : -1;
// 	int dy = -abs(y1 - y0);
// 	int sy = y0 < y1 ? 1 : -1;
// 	int err = dx + dy;
// 	int e2;

// 	while (1)
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0xFF0000);
// 		if (x0 == x1 && y0 == y1)
// 			break;
// 		e2 = 2 * err;
// 		if (e2 >= dy)
// 		{
// 			err += dy;
// 			x0 += sx;
// 		}
// 		if (e2 <= dx)
// 		{
// 			err += dx;
// 			y0 += sy;
// 		}
// 	}
// }