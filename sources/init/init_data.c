/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:52:08 by afont             #+#    #+#             */
/*   Updated: 2024/06/05 10:44:31 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 256)
		data->keys[i] = 0;
	data->ray_data = malloc(sizeof(t_ray_data) * FOV);
	ft_protect_malloc(data->ray_data);
}

void	ft_init_player(t_data *data)
{
	data->player.pos.x = 500;
	data->player.pos.y = 500;
	data->player.radius = CIRCLE_RAD;
	data->player.color = 0x00FF00;
	data->player.angle = M_PI;
	data->player.angle_step = ANGLE_STEP;
}
