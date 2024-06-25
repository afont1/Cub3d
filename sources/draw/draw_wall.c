/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:21:53 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 12:10:32 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_wall(t_data *data, double dist_t, int nbr_ray, int is_vertical)
{
	float	line_height;

	line_height = ((WIN_HEIGHT / dist_t)) * data->player.fov_factor;
	// static int cpt;
	// if (nbr_ray > 0 && line_height == data->ray_data[nbr_ray - 1].line_height)
	// {
	// 	printf("%f\n", line_height);
	// 	cpt++;
	// 	data->ray_data[nbr_ray].is_vertical = 2;
	// }
	// else
	// 	data->ray_data[nbr_ray].is_vertical = is_vertical;
	// if (nbr_ray == WIN_WIDTH - 1)
	// {
	// 	// printf("%f\n", data->player.factor);
	// 	printf("%d\n", cpt);
	// 	cpt = 0;
	// }
	data->ray_data[nbr_ray].ty_step = JSP / line_height;
	data->ray_data[nbr_ray].ty_offset = 0;
	if (line_height > WIN_HEIGHT)
	{
		data->ray_data[nbr_ray].ty_offset = (line_height - WIN_HEIGHT) / 2;
		line_height = WIN_HEIGHT;
	}
	data->ray_data[nbr_ray].line_height = line_height;
	data->ray_data[nbr_ray].is_vertical = is_vertical;
}

void	ft_draw_wall(t_data *data, t_img *wall_img, int k, double offset)
{
	int	i;
	int	i_offset;
	
	float	tx;
	float	ty;
 
	i = -1;
	while (++i < offset)
	{
		if (ft_get_color(wall_img, k, i) != MAP_SKY_COLOR)
			ft_pixel_put(*wall_img, k, i, MAP_SKY_COLOR);
	}
	i = 0;
	i_offset = i + offset;
	
	if (data->ray_data[k].is_vertical == 1)
	{
		tx = (int)data->ray_data[k].rx % JSP;
		tx = JSP - 1 - tx;
		if (data->ray_data[k].ray_angle > M_PI)
			tx = JSP - 1 - tx;
	}
	else
	{
		tx = (int)data->ray_data[k].ry % JSP;
		if (data->ray_data[k].ray_angle > M_PI2 && data->ray_data[k].ray_angle < M_PI3)
			tx = JSP - 1 - tx;
	}
	ty = data->ray_data[k].ty_offset * data->ray_data[k].ty_step;
	while (i++ < data->ray_data[k].line_height)
	{
		ft_pixel_put(*wall_img, k, i_offset, ft_get_color(&data->all_img.red_wall, tx, ty));
		i_offset++;
		ty += data->ray_data[k].ty_step;
	}
	i += offset;
	while (i < WIN_HEIGHT)
	{
		if (ft_get_color(wall_img, k, i) != MAP_FLOOR_COLOR)
			ft_pixel_put(*wall_img, k, i, MAP_FLOOR_COLOR);
		i++;
	}
}
