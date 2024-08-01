/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:39 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 00:17:08 by bloisel          ###   ########.fr       */
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

void	ft_draw_map_square(t_data *data, t_img map_img, int i, int j)
{
	int			x;
	int			y;

	y = (i - (int)data->player.x + MAP_RANGE / 2) * MAP_SQUARE_SIZE;
	x = (j - (int)data->player.y + MAP_RANGE / 2) * MAP_SQUARE_SIZE;
	if (data->map.tab_map[i][j] == '1')
		ft_draw_square(map_img, x, y, MAP_WALL_COLOR);
	else if (data->map.tab_map[i][j] == '0')
		ft_draw_square(map_img, x, y, MAP_FLOOR_COLOR);
	else if (data->map.tab_map[i][j] == ' ')
		ft_draw_square(map_img, x, y, 0x000000);
	else if (data->map.tab_map[i][j] == '2')
		ft_draw_square(map_img, x, y, MAP_WALL_COLOR * 0.5);
	else if (data->map.tab_map[i][j] == '3')
		ft_draw_square(map_img, x, y, MAP_FLOOR_COLOR);
	if (i == (int)data->player.x && j == (int)data->player.y)
		ft_draw_square(map_img, x, y, CUBE_COLOR);
}

void	ft_draw_border(t_data *data, t_img img, int color)
{
	int	i;
	int	j;

	j = -1;
	while (++j < BORDER_WIDTH)
	{
		i = -1;
		while (++i < data->map.size)
		{
			ft_pixel_put(img, i, j, color);
			ft_pixel_put(img, i, data->map.size - 1 - j, color);
		}
	}
	j = -1;
	while (++j < data->map.size)
	{
		i = -1;
		while (++i < BORDER_WIDTH)
		{
			ft_pixel_put(img, i, j, color);
			ft_pixel_put(img, data->map.size - 1 - i, j, color);
		}
	}
}

void	ft_draw_map(t_data *data)
{
	int		i;
	int		j;

	i = (int)data->player.x - MAP_RANGE / 2;
	while (i < (int)data->player.x + (MAP_RANGE / 2) + 1)
	{
		j = (int)data->player.y - MAP_RANGE / 2;
		while (j < (int)data->player.y + (MAP_RANGE / 2) + 1)
		{
			if (j >= 0 && j < data->map.width && i >= 0 && i < data->map.height)
				ft_draw_map_square(data, data->map.img, i, j);
			else
				ft_draw_square(data->map.img,
					(j - (int)data->player.y + MAP_RANGE / 2)
					* MAP_SQUARE_SIZE,
					(i - (int)data->player.x + MAP_RANGE / 2)
					* MAP_SQUARE_SIZE, 0x000000);
			j++;
		}
		i++;
	}
	ft_draw_fov(data, data->map.img);
	ft_draw_border(data, data->map.img, 0xFFFFFF);
}
