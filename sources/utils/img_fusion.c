/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fusion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:35:58 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 14:38:39 by afont            ###   ########.fr       */
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

	i = -1;
	while (++i < src->width)
	{
		j = -1;
		while (++j < src->height)
			ft_pixel_put(*dst, x + i, y + j, ft_get_color(src, i, j));
	}
}
