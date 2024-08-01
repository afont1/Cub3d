/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:25:29 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 01:47:46 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_color(t_img *img, int x, int y)
{
	return (*((unsigned int *)(img->addr
			+ (y * img->line_length + x * (img->bits_per_pixel / 8)))));
}

void	ft_pixel_put(t_img img, int x, int y, int color)
{
	*((unsigned int *)((img.line_length * y)
				+ (x * (img.bits_per_pixel / 8)) + img.addr)) = color;
}
