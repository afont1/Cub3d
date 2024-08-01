/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:49:11 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 12:29:40 by bloisel          ###   ########.fr       */
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

void	ft_fusion2(t_img *dst, t_img *src)
{
	int		i;
	int		j;
	float	px;
	float	py;

	i = -1;
	while (++i < 1024)
	{
		j = -1;
		while (++j < 1024)
		{
			px = floor(i * src->x_ratio);
			py = floor(j * src->y_ratio);
			src->color = ft_get_color(src, (int)px, (int)py);
			if (src->color != -16777216)
				ft_pixel_put(*dst, src->x + i, src->y + j, src->color);
		}
	}
}

void	ft_fusion_img_resized(t_img *dst, t_img *src, int x)
{
	src->x_ratio = src->width / (float)NEW_WIDTH;
	src->y_ratio = src->height / (float)NEW_HEIGHT;
	src->y = 56;
	src->x = x;
	ft_fusion2(dst, src);
}
