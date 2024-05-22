/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:43:55 by afont             #+#    #+#             */
/*   Updated: 2024/05/21 13:09:47 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	ft_new_img(t_data *data, int width, int height, int x, int y)
{
	t_img	img;

	img.img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.pos.x = x;
	img.pos.y = y;
	img.width = width;
	img.height = height;
	return (img);
}
