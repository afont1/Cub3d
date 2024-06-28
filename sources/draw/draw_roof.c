/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_roof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:50:32 by afont             #+#    #+#             */
/*   Updated: 2024/06/26 14:53:54 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_roof(t_data *data, t_img *img, int k, double offset)
{
	int	i;

	i = -1;
	while (++i < offset)
		if (ft_get_color(img, k, i) != data->all_img.ceiling_color)
			ft_pixel_put(*img, k, i, data->all_img.ceiling_color);
}
