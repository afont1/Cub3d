/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fusion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:35:58 by afont             #+#    #+#             */
/*   Updated: 2024/07/03 09:14:21 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_color(t_img *img, int x, int y)
{
	return (*((unsigned int *)(img->addr + (y * img->line_length \
	+ x * (img->bits_per_pixel / 8)))));
}

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
	int i, j;
	float x_ratio = src->width / (float)new_width;
	float y_ratio = src->height / (float)new_height;
	float px, py;
	int color;

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
