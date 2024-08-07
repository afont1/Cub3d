/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:39 by afont             #+#    #+#             */
/*   Updated: 2024/08/07 16:47:26 by afont            ###   ########.fr       */
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

	x = (i - (data->player.pos.x / JSP) + MAP_RANGE / 2) * MAP_SQUARE_SIZE;
	y = (j - (data->player.pos.y / JSP) + MAP_RANGE / 2) * MAP_SQUARE_SIZE;
	if (data->map.tab_map[j][i] == '1')
		ft_draw_square(map_img, x, y, MAP_WALL_COLOR);
	if (data->map.tab_map[j][i] == '0')
		ft_draw_square(map_img, x, y, MAP_FLOOR_COLOR);
	if (data->map.tab_map[j][i] == ' ')
		ft_draw_square(map_img, x, y, 0x000000);
	if (i == data->player.pos.x / JSP && j == data->player.pos.y / JSP)
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

	i = (data->player.pos.x / JSP) - MAP_RANGE / 2;
	while (i < (data->player.pos.x / JSP) + (MAP_RANGE / 2) + 1)
	{
		j = (data->player.pos.y / JSP) - MAP_RANGE / 2;
		while (j < (data->player.pos.y / JSP) + (MAP_RANGE / 2) + 1)
		{
			if (i >= 0 && i < data->map.width && j >= 0 && j < data->map.height)
				ft_draw_map_square(data, data->map.img, i, j);
			else
				ft_draw_square(data->map.img, (i - (data->player.pos.x / JSP) \
				+ MAP_RANGE / 2) * MAP_SQUARE_SIZE, (j - (data->player.pos.y / \
				JSP) + MAP_RANGE / 2) * MAP_SQUARE_SIZE, 0x000000);
			j++;
		}
		i++;
	}
	ft_draw_fov(data, data->map.img);
	ft_draw_border(data, data->map.img, 0xFFFFFF);
}
