/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_roof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:50:32 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 16:38:09 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_roof(t_img *img, int k, double offset)
{
	int	i;

	i = -1;
	while (++i < offset)
		if (ft_get_color(img, k, i) != MAP_SKY_COLOR)
			ft_pixel_put(*img, k, i, MAP_SKY_COLOR);
}
