/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:53:51 by afont             #+#    #+#             */
/*   Updated: 2024/06/26 14:54:40 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_floor(t_data *data, t_img *img, int k, int i)
{
	while (i < WIN_HEIGHT)
	{
		if (ft_get_color(img, k, i) != data->all_img.floor_color)
			ft_pixel_put(*img, k, i, data->all_img.floor_color);
		i++;
	}
}
