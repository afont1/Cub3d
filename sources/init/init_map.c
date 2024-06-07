/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:35:13 by afont             #+#    #+#             */
/*   Updated: 2024/06/07 15:42:35 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_square(t_img img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			*(unsigned int *)(img.addr + ((y + i) * img.line_length + (x + j) * (img.bits_per_pixel / 8))) = color;
			j++;
		}
		i++;
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
        *(unsigned int *)(img.addr + (y0 * img.line_length + x0 * (img.bits_per_pixel / 8))) = 0xFFFFFF; // Set pixel color to white
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
	int	start;
	int	distance;
	double	angle1;
	double	angle2;

	distance = sqrt(pow(MAP_RANGE * 20, 2) + pow(MAP_RANGE * 20, 2));
	if (distance > MAP_RANGE / 2 * 20)
		distance = MAP_RANGE / 2 * 20;
	angle1 = data->player.angle - (FOV / 2);
	angle2 = data->player.angle + (FOV / 2);
	angle1 = ft_angle_loop(angle1);
	angle2 = ft_angle_loop(angle2);
	start = (MAP_RANGE / 2) * 20 + 10;
	ft_draw_line_fov(img, start, start, start + cos(angle1) * distance, start + sin(angle1) * distance);
	ft_draw_line_fov(img, start, start, start + cos(angle2) * distance, start + sin(angle2) * distance);
}

void	ft_draw_map_square(t_data *data, t_img map_img, int i, int j)
{
	int	x;
	int	y;

	x = (i - (data->player.pos.x / data->map.width) + MAP_RANGE / 2) * 20;
	y = (j - (data->player.pos.y / data->map.width) + MAP_RANGE / 2) * 20;
	if (data->map.tab_map[j][i] == '1')
		ft_draw_square(map_img, x, y, MAP_WALL_COLOR);
	else if (data->map.tab_map[j][i] == '0')
		ft_draw_square(map_img, x, y, MAP_FLOOR_COLOR);
	if (i == data->player.pos.x / data->map.width && j == data->player.pos.y / data->map.width)
		ft_draw_square(map_img, x, y, 0x0000FF);
}

void	ft_init_map_img(t_data *data)
{
	t_img	map_img;
	int		i;
	int		j;

	map_img.img_ptr = mlx_new_image(data->mlx_ptr, (MAP_RANGE + 1) * 20, (MAP_RANGE + 1) * 20);
	map_img.addr = mlx_get_data_addr(map_img.img_ptr, &map_img.bits_per_pixel, \
	&map_img.line_length, &map_img.endian);
	i = (data->player.pos.x / data->map.width) - MAP_RANGE / 2;
	while (i < (data->player.pos.x / data->map.width) + (MAP_RANGE / 2) + 1)
	{
		j = (data->player.pos.y / data->map.width) - MAP_RANGE / 2;
		while (j < (data->player.pos.y / data->map.width) + (MAP_RANGE / 2) + 1)
		{
			if (i >= 0 && i < data->map.width && j >= 0 && j < data->map.width)
				ft_draw_map_square(data, map_img, i, j);
			j++;
		}
		i++;
	}
	ft_draw_fov(data, map_img);
	data->map.img = map_img;
}

void	ft_line_to_map(t_data *data, char *line, int j)
{
	int	i;

	i = -1;
	data->map.tab_map[j] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[++i] && line[i] != '\n')
		data->map.tab_map[j][i] = line[i];
	data->map.tab_map[j][i] = 0;
}

void	ft_init_map_data(t_data *data, char *argv)
{
	int		fd;
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
		ft_line_to_map(data, line, ++j);
		free(line);
		line = get_next_line(fd);
	}
	data->map.tab_map[j + 1] = NULL;
	data->map.width = ft_strlen(data->map.tab_map[0]);
	close(fd);
}
