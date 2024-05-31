/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:48:20 by afont             #+#    #+#             */
/*   Updated: 2024/05/30 14:30:20 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_ray(t_data *data)
{
	int		nbr_ray;
	double	ray_angle;
	double	dist_h;
	double	dist_v;
	double	dist_t;

	ray_angle = data->player_angle - ONE_DR * FOV / 2;
	ray_angle = ft_angle_loop(ray_angle);
	nbr_ray = -1;
	while (++nbr_ray < FOV)
	{
		dist_h = ft_horizontal_ray(data, ray_angle);
		dist_v = ft_vertical_ray(data, ray_angle);
		if (dist_v < dist_h)
		{
			dist_t = fish_eye_correction(data, ray_angle, dist_v);
			ft_wall(data, dist_t, nbr_ray, 0);
		}
		if (dist_h < dist_v)
		{
			dist_t = fish_eye_correction(data, ray_angle, dist_h);
			ft_wall(data, dist_t, nbr_ray, 1);
		}
		ft_draw_line(data, ray_angle, dist_t);
		ray_angle += ONE_DR;
		ray_angle = ft_angle_loop(ray_angle);
	}
}

void ft_draw_line(t_data *data, double ray_angle, double dist_t)
{
    int x0 = data->img.pos.x + CUBE_SIZE / 2;
    int y0 = data->img.pos.y + CUBE_SIZE / 2;
    int x1 = x0 + dist_t * cos(ray_angle) - CUBE_SIZE / 2;
    int y1 = y0 + dist_t * sin(ray_angle) - CUBE_SIZE / 2;
    int color = 0xFF0000;
    int thickness = 1;

    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (1)
    {
        for (int i = -thickness / 2; i <= thickness / 2; i++)
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0 + i, y0, color);
        }
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

double	ft_horizontal_ray(t_data *data, double ray_angle)
{
	int	dof;
	double	a_tan;
	t_pos	map_coord;
	t_coord	ray_coord;
	t_coord	offset;
	
	dof = 0;
	a_tan = -1/tan(ray_angle);
	if (ray_angle > M_PI)
	{
		ray_coord.y = (((int)data->img.pos.y / (WIN_HEIGHT / data->map.width)) * (WIN_HEIGHT / data->map.width)) - 0.0001;
		ray_coord.x = (data->img.pos.y - ray_coord.y) * a_tan + data->img.pos.x;
		offset.y = -(WIN_HEIGHT / data->map.width);
		offset.x = -offset.y * a_tan;
	}
	if (ray_angle < M_PI)
	{
		ray_coord.y = (((int)data->img.pos.y / (WIN_HEIGHT / data->map.width)) * (WIN_HEIGHT / data->map.width)) + (WIN_HEIGHT / data->map.width);
		ray_coord.x = (data->img.pos.y - ray_coord.y) * a_tan + data->img.pos.x;
		offset.y = (WIN_HEIGHT / data->map.width);
		offset.x = -offset.y * a_tan;
	}
	if (ray_angle == 0 || ray_angle == M_PI)
	{
		ray_coord.x = data->img.pos.x;
		ray_coord.y = data->img.pos.y;
		dof = data->map.width;
	}
	while (dof < data->map.width)
	{
		map_coord.y = (int)(ray_coord.y) / (WIN_HEIGHT / data->map.width);
		map_coord.x = (int)(ray_coord.x) / (WIN_HEIGHT / data->map.width);
		if (map_coord.x < data->map.width && map_coord.y < data->map.width && map_coord.x >= 0 && map_coord.y >= 0 && data->map.tab_map[map_coord.y][map_coord.x] == '1')
			return (ft_dist(data->img.pos.x, data->img.pos.y, ray_coord.x, ray_coord.y));
		else
		{
			ray_coord.x += offset.x;
			ray_coord.y += offset.y;
			dof += 1;
		}
	}
	return (__DBL_MAX__);
}

double	ft_vertical_ray(t_data *data, double ray_angle)
{
	int	dof;
	double	n_tan;
	t_pos	map_coord;
	t_coord	ray_coord;
	t_coord	offset;

	dof = 0;
	n_tan = -tan(ray_angle);
	if (ray_angle > M_PI2 && ray_angle < M_PI3)
	{
		ray_coord.x = (((int)data->img.pos.x / (WIN_HEIGHT / data->map.width)) * (WIN_HEIGHT / data->map.width)) - 0.0001;
		ray_coord.y = (data->img.pos.x - ray_coord.x) * n_tan + data->img.pos.y;
		offset.x = -(WIN_HEIGHT / data->map.width);
		offset.y = -offset.x * n_tan;
	}
	if (ray_angle < M_PI2 || ray_angle > M_PI3)
	{
		ray_coord.x = (((int)data->img.pos.x / (WIN_HEIGHT / data->map.width)) * (WIN_HEIGHT / data->map.width)) + (WIN_HEIGHT / data->map.width);
		ray_coord.y = (data->img.pos.x - ray_coord.x) * n_tan + data->img.pos.y;
		offset.x = (WIN_HEIGHT / data->map.width);
		offset.y = -offset.x * n_tan;
	}
	if (ray_angle == 0 || ray_angle == M_PI)
	{
		ray_coord.x = data->img.pos.x;
		ray_coord.y = data->img.pos.y;
		dof = data->map.width;
	}
	while (dof < data->map.width)
	{
		map_coord.x = (int)(ray_coord.x) / (WIN_HEIGHT / data->map.width);
		map_coord.y = (int)(ray_coord.y) / (WIN_HEIGHT / data->map.width);
		if (map_coord.x < data->map.width && map_coord.y < data->map.width && map_coord.x >= 0 && map_coord.y >= 0 && data->map.tab_map[map_coord.y][map_coord.x] == '1')
			return (ft_dist(data->img.pos.x, data->img.pos.y, ray_coord.x, ray_coord.y));
		else
		{
			ray_coord.x += offset.x;
			ray_coord.y += offset.y;
			dof += 1;
		}
	}
	return (__DBL_MAX__);
}

double	fish_eye_correction(t_data *data, double ray_angle, double dist_t)
{
	double	fish_eye;
	
	fish_eye = data->player_angle - ray_angle;
	if (fish_eye < 0)
		fish_eye += 2 * M_PI;
	if (fish_eye > 2 * M_PI)
		fish_eye -= 2 * M_PI;
	dist_t *= cos(fish_eye);
	return (dist_t);
}