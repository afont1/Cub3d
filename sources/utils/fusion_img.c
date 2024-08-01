/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:49:11 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 02:36:56 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fusion_img(t_img *dst, t_img *src, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < src->width)
	{
		j = -1;
		while (++j < src->height)
		{
			color = ft_get_color(src, i, j);
			if (color != -16777216)
				ft_pixel_put(*dst, x + i, y + j, color);
		}
	}
}

void	ft_fusion_img_resized(t_img *dst, t_img *src, int x, int y, int new_width, int new_height)
{
	float	x_ratio;
	float	y_ratio;
	int		i;
	int		j;
	float	px;
	float	py;
	int		color;

	x_ratio = src->width / (float)new_width;
	y_ratio = src->height / (float)new_height;
	i = -1;
	while (++i < new_width)
	{
		j = -1;
		while (++j < new_height)
		{
			px = floor(i * x_ratio);
			py = floor(j * y_ratio);
			color = ft_get_color(src, (int)px, (int)py);
			if (color != -16777216)
				ft_pixel_put(*dst, x + i, y + j, color);
		}
	}
}
