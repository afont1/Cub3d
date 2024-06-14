/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:39 by afont             #+#    #+#             */
/*   Updated: 2024/06/14 14:31:42 by afont            ###   ########.fr       */
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

void	ft_draw_line_fov(t_img img, int x0, int y0, int x1, int y1)
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
	start = (MAP_RANGE / 2) * MAP_SQUARE_SIZE + 10;
	ft_draw_line_fov(img, start, start, start + cos(angle1) * distance1, start + sin(angle1) * distance1);
	ft_draw_line_fov(img, start, start, start + cos(angle2) * distance2, start + sin(angle2) * distance2);
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
	t_img	map_img;
	int		i;
	int		j;

	map_img.img_ptr = mlx_new_image(data->mlx_ptr, MAP_SIZE, MAP_SIZE);
	map_img.addr = mlx_get_data_addr(map_img.img_ptr, &map_img.bits_per_pixel, \
	&map_img.line_length, &map_img.endian);
	i = (data->player.pos.x / data->map.width) - MAP_RANGE / 2;
	while (i < (data->player.pos.x / data->map.width) + (MAP_RANGE / 2) + 1)
	{
		j = (data->player.pos.y / data->map.width) - MAP_RANGE / 2;
		while (j < (data->player.pos.y / data->map.width) + (MAP_RANGE / 2) + 1)
		{
			if (i >= 0 && i < data->map.width && j >= 0 && j < data->map.height)
				ft_draw_map_square(data, map_img, i, j);
			j++;
		}
		i++;
	}
	ft_draw_fov(data, map_img);
	ft_draw_border(map_img, 0xFFFFFF);
	data->map.img = map_img;
}
