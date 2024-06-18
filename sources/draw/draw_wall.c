/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:21:53 by afont             #+#    #+#             */
/*   Updated: 2024/06/17 10:12:40 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_wall(t_data *data, double dist_t, int nbr_ray, int is_vertical)
{
	float	line_height;

	line_height = (WIN_HEIGHT / dist_t) * FOV;
	if (line_height > WIN_HEIGHT)
		line_height = WIN_HEIGHT;
	data->ray_data[nbr_ray].line_height = line_height;
	data->ray_data[nbr_ray].is_vertical = is_vertical;
}

void	ft_draw_wall(t_data *data, t_img *wall_img, int k, double offset)
{
	int	i;

	i = -1;
	while (++i < offset)
	{
		if (ft_get_color(wall_img, k, i) != MAP_SKY_COLOR)
			ft_pixel_put(*wall_img, k, i, MAP_SKY_COLOR);
	}
	i = -1;
	while (++i < data->ray_data[k].line_height)
	{
		if (data->ray_data[k].is_vertical == 1 && ft_get_color(wall_img, k, i + offset) != MAP_WALL_COLOR)
			ft_pixel_put(*wall_img, k, (i + offset), MAP_WALL_COLOR);
		else if (data->ray_data[k].is_vertical == 0 && ft_get_color(wall_img, k, i + offset) != MAP_WALL_COLOR2)
			ft_pixel_put(*wall_img, k, (i + offset), MAP_WALL_COLOR2);
	}
	while ((i + offset) < WIN_HEIGHT)
	{
		if (ft_get_color(wall_img, k, i + offset) != MAP_FLOOR_COLOR)
			ft_pixel_put(*wall_img, k, (i + offset), MAP_FLOOR_COLOR);
		i++;
	}
}
