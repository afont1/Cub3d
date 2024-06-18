/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:39 by afont             #+#    #+#             */
/*   Updated: 2024/06/17 14:49:49 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_square(t_img img, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MAP_SQUARE_SIZE)
	{
		j = -1;
		while (++j < MAP_SQUARE_SIZE)
			ft_pixel_put(img, x + j, y + i, color);
	}
}

void	ft_draw_line(t_img img, int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy;
	int e2;

	while (1)
	{
		ft_pixel_put(img, x0, y0, 0xFFFFFF);
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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ft_fill_triangle(t_img img, int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (y2 < y1)
    {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }
    if (y3 < y1)
    {
        swap(&x1, &x3);
        swap(&y1, &y3);
    }
    if (y3 < y2)
    {
        swap(&x2, &x3);
        swap(&y2, &y3);
    }
    float slope1 = (y2 - y1 > 0) ? (float)(x2 - x1) / (y2 - y1) : 0;
    float slope2 = (y3 - y1 > 0) ? (float)(x3 - x1) / (y3 - y1) : 0;
    float slope3 = (y3 - y2 > 0) ? (float)(x3 - x2) / (y3 - y2) : 0;
    for (int y = y1; y <= y3; y++)
    {
        int xs, xe;
        if (y < y2)
        {
            xs = x1 + slope1 * (y - y1);
            xe = x1 + slope2 * (y - y1);
        }
        else
        {
            xs = x2 + slope3 * (y - y2);
            xe = x1 + slope2 * (y - y1);
        }
        if (xs > xe)
        {
            swap(&xs, &xe);
        }
        for (int x = xs; x <= xe; x++)
            ft_pixel_put(img, x, y, ft_get_color(&img, x, y) + 0x202020);
    }
}

void	ft_fill_gap(t_img img, int start, double a1, double a2, int d1, int d2)
{
	if ((a1 <= M_PI / 4 && a1 >= 0) || (a1 >= 345 * (M_PI / 180)))
		ft_fill_triangle(img, start + cos(a1) * d1, start + sin(a1) * d1, start + cos(a2) * d2, start + sin(a2) * d2, MAP_SIZE, MAP_SIZE);
	else if (a1 >= 75  * (M_PI / 180) && a1 <= 3 * M_PI / 4)
		ft_fill_triangle(img, start + cos(a1) * d1, start + sin(a1) * d1, start + cos(a2) * d2, start + sin(a2) * d2, 0, MAP_SIZE);
	else if (a1 >= 165 * (M_PI / 180) && a1 <= 5 * M_PI / 4)
		ft_fill_triangle(img, start + cos(a1) * d1, start + sin(a1) * d1, start + cos(a2) * d2, start + sin(a2) * d2, 0, 0);
	else if (a1 >= 255 * (M_PI / 180) && a1 <= 7 * M_PI / 4)
		ft_fill_triangle(img, start + cos(a1) * d1, start + sin(a1) * d1, start + cos(a2) * d2, start + sin(a2) * d2, MAP_SIZE, 0);
}

void	ft_draw_fov(t_data *data, t_img img)
{
	int		start;
	int		distance1;
	int		distance2;
	double	angle1;
	double	angle2;

	distance1 = 0;
	angle1 = ft_dist_ang(data->player.angle, &distance1, 0);
	angle2 = ft_dist_ang(data->player.angle, &distance2, 1);
	start = (MAP_RANGE / 2) * MAP_SQUARE_SIZE + MAP_SQUARE_SIZE / 2;
	ft_fill_triangle(img, start, start, start + cos(angle1) * distance1, start + sin(angle1) * distance1, start + cos(angle2) * distance2, start + sin(angle2) * distance2);
	ft_fill_gap(img, start, angle1, angle2, distance1, distance2);
}

void	ft_draw_map_square(t_data *data, t_img map_img, int i, int j)
{
	int			x;
	int			y;

	x = (i - (data->player.pos.x / data->map.width) + MAP_RANGE / 2) * MAP_SQUARE_SIZE;
	y = (j - (data->player.pos.y / data->map.width) + MAP_RANGE / 2) * MAP_SQUARE_SIZE;
	if (data->map.tab_map[j][i] == '1')
		ft_draw_square(map_img, x, y, MAP_WALL_COLOR);
	else if (data->map.tab_map[j][i] == '0')
		ft_draw_square(map_img, x, y, MAP_FLOOR_COLOR);
	else if (data->map.tab_map[j][i] == ' ')
		ft_draw_square(map_img, x, y, 0x000000);
	if (i == data->player.pos.x / data->map.width && j == data->player.pos.y / data->map.width)
		ft_draw_square(map_img, x, y, CUBE_COLOR);
}

void	ft_draw_border(t_img img, int color)
{
	int	i;
	int	j;

	j = -1;
	while (++j < BORDER_WIDTH)
	{
		i = -1;
		while (++i < MAP_SIZE)
		{
			ft_pixel_put(img, i, j, color);
			ft_pixel_put(img, i, MAP_SIZE - 1 - j, color);
		}
	}
	j = -1;
	while (++j < MAP_SIZE)
	{
		i = -1;
		while (++i < BORDER_WIDTH)
		{
			ft_pixel_put(img, i, j, color);
			ft_pixel_put(img, MAP_SIZE - 1 - i, j, color);
		}
	}
}

void	ft_draw_map(t_data *data)
{
	int		i;
	int		j;

	i = (data->player.pos.x / data->map.width) - MAP_RANGE / 2;
	while (i < (data->player.pos.x / data->map.width) + (MAP_RANGE / 2) + 1)
	{
		j = (data->player.pos.y / data->map.width) - MAP_RANGE / 2;
		while (j < (data->player.pos.y / data->map.width) + (MAP_RANGE / 2) + 1)
		{
			if (i >= 0 && i < data->map.width && j >= 0 && j < data->map.height)
				ft_draw_map_square(data, data->map.img, i, j);
			else
				ft_draw_square(data->map.img, (i - (data->player.pos.x / data->map.width) + MAP_RANGE / 2) * MAP_SQUARE_SIZE, (j - (data->player.pos.y / data->map.width) + MAP_RANGE / 2) * MAP_SQUARE_SIZE, 0x000000);
			j++;
		}
		i++;
	}
	ft_draw_fov(data, data->map.img);
	ft_draw_border(data->map.img, 0xFFFFFF);
}
