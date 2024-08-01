/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:52:55 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 11:46:05 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_weapon(t_data *data)
{
	static int		current_sprite;
	static double	diff;

	if (ft_is_mouvement(data))
		diff += data->elapsed_time;
	else
		current_sprite = 1;
	if (diff >= 300)
	{
		current_sprite++;
		diff = 0;
		if (current_sprite >= 4)
			current_sprite = 0;
	}
	ft_fusion_img_resized(&data->all_img.env_img, &data->all_img.weapon
	[data->all_img.weapon_anim[current_sprite].sprite],
		data->all_img.weapon_anim[current_sprite].coord_x);
}
