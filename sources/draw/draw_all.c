/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:02:03 by afont             #+#    #+#             */
/*   Updated: 2024/07/03 10:16:29 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_animate_knife(t_data *data)
{
	static int	current_sprite;
	static int	frame_counter;

	if(ft_is_mouvement(data))
		frame_counter++;
	else
		current_sprite = 1;
	if (frame_counter >= 30)
	{
		current_sprite++;
		frame_counter = 0;
		if (current_sprite >= 4)
			current_sprite = 0;
	}
	ft_fusion_img_resized(&data->all_img.env_img, &data->all_img.weapon[data->all_img.weapon_anim[current_sprite].sprite], data->all_img.weapon_anim[current_sprite].coord_x, 56, 1024, 1024);
}

void	ft_draw_all(t_data *data)
{
	int		i;

	ft_ray(data);
	ft_draw_map(data);
	i = -1;
	while (++i < WIN_WIDTH)
	{
		ft_draw_environement(data, &data->all_img.env_img, i, \
		(WIN_HEIGHT / 2) - (data->ray_data[i].line_height / 2));
	}
	ft_fusion_img(&data->all_img.env_img, &data->map.img, 0, 0);
	ft_animate_knife(data);
}
