/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:35:13 by afont             #+#    #+#             */
/*   Updated: 2024/05/29 12:01:32 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_map_img(t_data *data, char *argv)
{
	t_img	map_img;
	int		i;
	int		j;
	int		x;
	int		y;

	ft_init_map_data(data, argv);
	map_img.img_ptr = mlx_new_image(data->mlx_ptr, MAP_SIZE, MAP_SIZE);
	map_img.addr = mlx_get_data_addr(map_img.img_ptr, &map_img.bits_per_pixel, &map_img.line_length, &map_img.endian);
	i = -1;
	while (data->map.tab_map[++i])
	{
		j = -1;
		while (data->map.tab_map[i][++j])
		{
			y = i * (MAP_SIZE / data->map.width) - 1;
			while (++y < (i + 1) * (MAP_SIZE / data->map.width))
			{
				x = j * (MAP_SIZE / data->map.width) - 1;
				while (++x < (j + 1) * (MAP_SIZE / data->map.width))
				{
					if (x % (MAP_SIZE / data->map.width) == 0 || y % (MAP_SIZE / data->map.width) == 0)
						((int *)map_img.addr)[y * map_img.line_length / 4 + x] = MAP_WALL_COLOR;
					else if (data->map.tab_map[i][j] == '1')
						((int *)map_img.addr)[y * map_img.line_length / 4 + x] = MAP_WALL_COLOR;
					else if (data->map.tab_map[i][j] == '0')
						((int *)map_img.addr)[y * map_img.line_length / 4 + x] = MAP_FLOOR_COLOR;
				}
			}
		}
	}
	data->map.img = map_img;
}

void	ft_init_map_data(t_data *data, char *argv)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		exit(0);
	}
	data->map.tab_map = malloc(sizeof(char *) * (ft_get_map_height(argv) + 1));
	j = -1;
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		j++;
		data->map.tab_map[j] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		while (line[++i] && line[i] != '\n')
			data->map.tab_map[j][i] = line[i];
		data->map.tab_map[j][i] = 0;
		line = get_next_line(fd);
	}
	data->map.tab_map[j + 1] = NULL;
	data->map.width = ft_strlen(data->map.tab_map[0]);
	close(fd);
}