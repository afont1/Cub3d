/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:21:53 by afont             #+#    #+#             */
/*   Updated: 2024/06/10 09:56:44 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_wall(t_data *data, double dist_t, int nbr_ray, int is_vertical)
{
	float	line_height;

	line_height = (WIN_HEIGHT / dist_t) * (FOV / PRECISION);
	if (line_height > WIN_HEIGHT)
		line_height = WIN_HEIGHT;
	data->ray_data[nbr_ray].line_height = line_height;
	data->ray_data[nbr_ray].is_vertical = is_vertical;
}

void	ft_put_wall(t_data *data, t_img *wall_img, int k, double offset)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->ray_data[k].line_height)
	{
		j = -1;
		while (++j < WW)
		{
			if (data->ray_data[k].is_vertical == 1)
				ft_pixel_put(*wall_img, (k * WW + j), (i + offset), MAP_WALL_COLOR);
			else
				ft_pixel_put(*wall_img, (k * WW + j), (i + offset), MAP_WALL_COLOR2);
		}
	}
	while (i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WW && (i + offset) < WIN_HEIGHT)
			ft_pixel_put(*wall_img, (k * WW + j), (i + offset), MAP_FLOOR_COLOR);
		i++;
	}
}
