/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:02:03 by afont             #+#    #+#             */
/*   Updated: 2024/06/18 11:26:09 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_all(t_data *data)
{
	int		i;
	
	ft_ray(data);
	ft_draw_map(data);
	i = -1;
	while (++i < WIN_WIDTH)
		ft_draw_wall(data, &data->all_img.wall_img, i, (WIN_HEIGHT / 2) - \
		(data->ray_data[i].line_height / 2));
	ft_fusion_img(&data->all_img.wall_img, &data->map.img, 0, 0);
	// ft_fusion_img(&data->all_img.wall_img, &data->all_img.one, 6, 6);
}
