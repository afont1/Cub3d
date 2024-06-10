/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:56:32 by afont             #+#    #+#             */
/*   Updated: 2024/06/10 09:56:41 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_display_all(t_data *data)
{
	t_img	wall_img;
	int		k;

	wall_img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	wall_img.addr = mlx_get_data_addr(wall_img.img_ptr, \
	&wall_img.bits_per_pixel, &wall_img.line_length, &wall_img.endian);
	k = -1;
	while (++k < FOV)
		ft_put_wall(data, &wall_img, k, (WIN_HEIGHT / 2) - \
		(data->ray_data[k].line_height / 2));
	ft_fusion_img(&wall_img, &data->map.img, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	wall_img.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, wall_img.img_ptr);
}

