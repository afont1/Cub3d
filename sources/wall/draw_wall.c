/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:21:53 by afont             #+#    #+#             */
/*   Updated: 2024/05/29 12:02:04 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_wall(t_data *data, double dist_t, int nbr_ray, int is_vertical)
{
	float			line_height;
	// static float	list_height[FOV];

	line_height = (WIN_HEIGHT * (WIN_HEIGHT / data->map.width)) / dist_t;
	if (line_height > WIN_HEIGHT)
		line_height = WIN_HEIGHT;
	data->ray_data[nbr_ray].line_height = line_height;
	data->ray_data[nbr_ray].is_vertical = is_vertical;
	// list_height[nbr_ray] = line_height;
	if (nbr_ray == FOV - 1)
		ft_draw_rectangle(data);
}

void	ft_draw_rectangle(t_data *data)
{
	t_img	player_img;
	int		i;
	int		j;
	int		k;
	float	offset;
	
	player_img.img_ptr = mlx_new_image(data->mlx_ptr, 512, 512);
	player_img.addr = mlx_get_data_addr(player_img.img_ptr, &player_img.bits_per_pixel, &player_img.line_length, &player_img.endian);
	k = -1;
	while (++k < FOV)
	{
		i = -1;
		offset = (512 / 2) - (data->ray_data[k].line_height / 2);
		while (++i < data->ray_data[k].line_height)
		{
			j = -1;
			while (++j < (512 / FOV))
			{
				if (data->ray_data[k].is_vertical == 1)
					ft_pixel_put(player_img, (k * (512 / FOV) + j), (i + offset), 0x2e2e2e);
				else
					ft_pixel_put(player_img, (k * (512 / FOV) + j), (i + offset), 0x212121);
			}
		}
		while (i < 512)
		{
			j = -1;
			while (++j < (512 / FOV))
			{
				if ((i + offset) < 512)
					ft_pixel_put(player_img, (k * (512 / FOV) + j), (i + offset), 0x474747);
			}
			i++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, player_img.img_ptr, 512, 0);
	mlx_destroy_image(data->mlx_ptr, player_img.img_ptr);
}
