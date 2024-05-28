/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:35:13 by afont             #+#    #+#             */
/*   Updated: 2024/05/28 09:38:55 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_map_img(t_data *data)
{
	t_img	map_img;
	int		i;
	int		j;
	int		x;
	int		y;
	char	map_char[8][8] = {{1,1,1,1,1,1,1,1},
							{1,1,0,1,0,0,0,1},
							{1,1,0,1,0,0,0,1},
							{1,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,1},
							{1,1,0,0,0,0,0,1},
							{1,0,1,0,0,0,0,1},
							{1,1,1,1,1,1,1,1}};

	ft_init_map_data(data, map_char);
	map_img.img_ptr = mlx_new_image(data->mlx_ptr, MAP_SIZE, MAP_SIZE);
	map_img.addr = mlx_get_data_addr(map_img.img_ptr, &map_img.bits_per_pixel, &map_img.line_length, &map_img.endian);
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
		{
			y = i * (MAP_SIZE / 8) - 1;
			while (++y < (i + 1) * (MAP_SIZE / 8))
			{
				x = j * (MAP_SIZE / 8) - 1;
				while (++x < (j + 1) * (MAP_SIZE / 8))
				{
					if (x % (MAP_SIZE / 8) == 0 || y % (MAP_SIZE / 8) == 0)
						((int *)map_img.addr)[y * map_img.line_length / 4 + x] = MAP_WALL_COLOR;
					else if (map_char[i][j] == 1)
						((int *)map_img.addr)[y * map_img.line_length / 4 + x] = MAP_WALL_COLOR;
					else if (map_char[i][j] == 0)
						((int *)map_img.addr)[y * map_img.line_length / 4 + x] = MAP_FLOOR_COLOR;
				}
			}
		}
	}
	data->map.img = map_img;
}

void	ft_init_map_data(t_data *data, char map_char[8][8])
{
	int i, j;
	data->map.tab_map = malloc(sizeof(char *) * 8);
	for (i = 0; i < 8; i++)
	{
		data->map.tab_map[i] = malloc(sizeof(char) * 8);
		for (j = 0; j < 8; j++)
		{
			data->map.tab_map[i][j] = map_char[i][j];
		}
	}
}