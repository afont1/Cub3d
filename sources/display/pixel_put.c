/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:26:56 by afont             #+#    #+#             */
/*   Updated: 2024/05/21 16:19:10 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_pixel_put(t_img img, int x, int y, int color)
{
	int	offset;

	offset = (img.line_length * y) + (x * (img.bits_per_pixel / 8));
	*((unsigned int *)(offset + img.addr)) = color;
}

void	ft_put_image_to_window(t_data *data, t_img img, int color)
{
	int		x;
	int		y;

	x = -1;
	while (++x < img.width)
	{
		y = -1;
		while (++y < img.height)
			ft_pixel_put(img, x, y, color);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.img_ptr, img.pos.x, img.pos.y);
}
