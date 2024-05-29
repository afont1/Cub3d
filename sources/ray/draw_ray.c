/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:48:20 by afont             #+#    #+#             */
/*   Updated: 2024/05/29 12:02:04 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_ray(t_data *data)
{
	int		nbr_ray; //
	int		mx;
	int		my;
	int		dof;
	int		is_vertical;
	double	rx;
	double	ry;
	double	ray_angle; //
	double	xo;
	double	yo;
	double	a_tan;
	double 	n_tan;
	double	dist_h;
	double	dist_v;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	double	dist_t;
	double	fish_eye;

	hx = data->img.pos.x;
	hy = data->img.pos.y;
	vx = data->img.pos.x;
	vy = data->img.pos.y;
	ray_angle = data->player_angle - ONE_DR * FOV / 2;
	if (ray_angle >= 2 * M_PI)
		ray_angle -= 2 * M_PI;
	if (ray_angle < 0)
		ray_angle += 2 * M_PI;
	nbr_ray = -1;
	while (++nbr_ray < FOV)
	{
		dist_h = __DBL_MAX__;
		dist_v = __DBL_MAX__;
		dof = 0;
		a_tan = -1/tan(ray_angle);
		if (ray_angle > M_PI)
		{
			ry = (((int)data->img.pos.y / (WIN_HEIGHT / data->map.width)) * (WIN_HEIGHT / data->map.width)) - 0.0001;
			rx = (data->img.pos.y - ry) * a_tan + data->img.pos.x;
			yo = -(WIN_HEIGHT / data->map.width);
			xo = -yo * a_tan;
		}
		if (ray_angle < M_PI)
		{
			ry = (((int)data->img.pos.y / (WIN_HEIGHT / data->map.width)) * (WIN_HEIGHT / data->map.width)) + (WIN_HEIGHT / data->map.width);
			rx = (data->img.pos.y - ry) * a_tan + data->img.pos.x;
			yo = (WIN_HEIGHT / data->map.width);
			xo = -yo * a_tan;
		}
		if (ray_angle == 0 || ray_angle == M_PI)
		{
			rx = data->img.pos.x;
			ry = data->img.pos.y;
			dof = data->map.width;
		}
		while (dof < data->map.width)
		{
			my = (int)(ry) / (WIN_HEIGHT / data->map.width);
			mx = (int)(rx) / (WIN_HEIGHT / data->map.width);
			if (mx < data->map.width && my < data->map.width && mx >= 0 && my >= 0 && data->map.tab_map[my][mx] == '1')
			{
				dof = data->map.width;
				hx = rx;
				hy = ry;
				dist_h = ft_dist(data->img.pos.x, data->img.pos.y, hx, hy);
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}

		//////////

		dof = 0;
		n_tan = -tan(ray_angle);
		if (ray_angle > M_PI2 && ray_angle < M_PI3)
		{
			rx = (((int)data->img.pos.x / (WIN_HEIGHT / data->map.width)) * (WIN_HEIGHT / data->map.width)) - 0.0001;
			ry = (data->img.pos.x - rx) * n_tan + data->img.pos.y;
			xo = -(WIN_HEIGHT / data->map.width);
			yo = -xo * n_tan;
		}
		if (ray_angle < M_PI2 || ray_angle > M_PI3)
		{
			rx = (((int)data->img.pos.x / (WIN_HEIGHT / data->map.width)) * (WIN_HEIGHT / data->map.width)) + (WIN_HEIGHT / data->map.width);
			ry = (data->img.pos.x - rx) * n_tan + data->img.pos.y;
			xo = (WIN_HEIGHT / data->map.width);
			yo = -xo * n_tan;
		}
		if (ray_angle == 0 || ray_angle == M_PI)
		{
			rx = data->img.pos.x;
			ry = data->img.pos.y;
			dof = data->map.width;
		}
		while (dof < data->map.width)
		{
			mx = (int)(rx) / (WIN_HEIGHT / data->map.width);
			my = (int)(ry) / (WIN_HEIGHT / data->map.width);
			if (mx < data->map.width && my < data->map.width && mx >= 0 && my >= 0 && data->map.tab_map[my][mx] == '1')
			{
				dof = data->map.width;
				vx = rx;
				vy = ry;
				dist_v = ft_dist(data->img.pos.x, data->img.pos.y, vx, vy);
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		if (dist_v < dist_h)
		{
			rx = vx;
			ry = vy;
			dist_t = dist_v;
			is_vertical = 0;
		}
		if (dist_h < dist_v)
		{
			rx = hx;
			ry = hy;
			dist_t = dist_h;
			is_vertical = 1;
		}
		ft_draw_line(data->img.pos.x + CUBE_SIZE / 2, data->img.pos.y + CUBE_SIZE / 2, rx, ry, 0xFF0000, 1, data);
		ray_angle += ONE_DR;
		if (ray_angle >= 2 * M_PI)
			ray_angle -= 2 * M_PI;
		if (ray_angle < 0)
			ray_angle += 2 * M_PI;
		fish_eye = data->player_angle - ray_angle;
		if (fish_eye < 0)
			fish_eye += 2 * M_PI;
		if (fish_eye > 2 * M_PI)
			fish_eye -= 2 * M_PI;
		dist_t *= cos(fish_eye);
		ft_init_wall(data, dist_t, nbr_ray, is_vertical);
	}
}

void ft_draw_line(int x0, int y0, int x1, int y1, int color, int thickness, t_data *data)
{
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

void	ft_draw_circle(int x, int y, int r, int color, t_data *data)
{
	int i;
	int j;
	int d;

	i = 0;
	j = r;
	d = 3 - 2 * r;
	while (i <= j)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, color);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y - j, color);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x - i, y + j, color);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x - i, y - j, color);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + j, y + i, color);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + j, y - i, color);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x - j, y + i, color);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x - j, y - i, color);
		if (d < 0)
			d += 4 * i + 6;
		else
		{
			d += 4 * (i - j) + 10;
			j--;
		}
		i++;
	}
}
