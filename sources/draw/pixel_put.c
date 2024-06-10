/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:26:56 by afont             #+#    #+#             */
/*   Updated: 2024/06/10 09:32:08 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_pixel_put(t_img img, int x, int y, int color)
{
	int	offset;

	offset = (img.line_length * y) + (x * (img.bits_per_pixel / 8));
	*((unsigned int *)(offset + img.addr)) = color;
}
