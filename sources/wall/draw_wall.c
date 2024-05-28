/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:21:53 by afont             #+#    #+#             */
/*   Updated: 2024/05/28 09:38:20 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_wall(t_data *data, double dist_t, int nbr_ray)
{
	float			line_height;
	static float	list_height[FOV];

	line_height = (WIN_HEIGHT * 64) / dist_t;
	if (line_height > WIN_HEIGHT)
		line_height = WIN_HEIGHT;
	list_height[nbr_ray] = line_height;
	if (nbr_ray == FOV - 1)
		ft_draw_rectangle(data, list_height);
}

void	ft_draw_rectangle(t_data *data, float *list_height)
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
		offset = (512 / 2) - (list_height[k] / 2);
		while (++i < list_height[k])
		{
			j = -1;
			while (++j < (512 / FOV))
			{
				ft_pixel_put(player_img, (k * (512 / FOV) + j), (i + offset), 0x00FF00);
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, player_img.img_ptr, 512, 0);
	mlx_destroy_image(data->mlx_ptr, player_img.img_ptr);
}
