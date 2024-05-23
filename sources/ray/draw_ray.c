/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:48:20 by afont             #+#    #+#             */
/*   Updated: 2024/05/23 13:24:38 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_ray(t_data *data)
{
	int		nbr_ray; //
	int		mx;
	int		my;
	int		dof;
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
	// double	dist_t;

	dist_h = __DBL_MAX__;
	dist_v = __DBL_MAX__;
	hx = data->img.pos.x;
	hy = data->img.pos.y;
	vx = data->img.pos.x;
	vy = data->img.pos.y;
	ray_angle = data->player_angle - ONE_DR * 30;
	if (ray_angle >= 2 * M_PI)
		ray_angle -= 2 * M_PI;
	if (ray_angle < 0)
		ray_angle += 2 * M_PI;
	nbr_ray = -1;
	while (++nbr_ray < 90)
	{
		dof = 0;
		a_tan = -1/tan(ray_angle);
		if (ray_angle > M_PI)
		{
			ry = (((int)data->img.pos.y >> 6) << 6) - 0.0001;
			rx = (data->img.pos.y - ry) * a_tan + data->img.pos.x;
			yo = -64;
			xo = -yo * a_tan;
		}
		if (ray_angle < M_PI)
		{
			ry = (((int)data->img.pos.y >> 6) << 6) + 64;
			rx = (data->img.pos.y - ry) * a_tan + data->img.pos.x;
			yo = 64;
			xo = -yo * a_tan;
		}
		if (ray_angle == 0 || ray_angle == M_PI)
		{
			rx = data->img.pos.x;
			ry = data->img.pos.y;
			dof = 8;
		}
		while (dof < 8)
		{
			my = (int)(ry) >> 6;
			mx = (int)(rx) >> 6;
			if (mx < 8 && my < 8 && mx >= 0 && my >= 0 && data->map.tab_map[my][mx] == 1)
			{
				dof = 8;
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
			rx = (((int)data->img.pos.x >> 6) << 6) - 0.0001;
			ry = (data->img.pos.x - rx) * n_tan + data->img.pos.y;
			xo = -64;
			yo = -xo * n_tan;
		}
		if (ray_angle < M_PI2 || ray_angle > M_PI3)
		{
			rx = (((int)data->img.pos.x >> 6) << 6) + 64;
			ry = (data->img.pos.x - rx) * n_tan + data->img.pos.y;
			xo = 64;
			yo = -xo * n_tan;
		}
		if (ray_angle == 0 || ray_angle == M_PI)
		{
			rx = data->img.pos.x;
			ry = data->img.pos.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			if (mx < 8 && my < 8 && mx >= 0 && my >= 0 && data->map.tab_map[my][mx] == 1)
			{
				dof = 8;
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
		if (dist_v <= dist_h)
		{
			rx = vx;
			ry = vy;
			// dist_t = dist_v;
		}
		if (dist_h <= dist_v)
		{
			rx = hx;
			ry = hy;
			// dist_t = dist_h;
		}
		draw_line(data->img.pos.x + CUBE_SIZE / 2, data->img.pos.y + CUBE_SIZE / 2, rx, ry, 0xFF0000, 1, data);
		ray_angle += ONE_DR;
		if (ray_angle >= 2 * M_PI)
			ray_angle -= 2 * M_PI;
		if (ray_angle < 0)
			ray_angle += 2 * M_PI;
	}
}

void draw_line(int x0, int y0, int x1, int y1, int color, int thickness, t_data *data)
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

// void	ft_draw_horizontal_ray(t_data *data, )