/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:27:10 by afont             #+#    #+#             */
/*   Updated: 2024/06/27 16:22:31 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fov(t_data *data)
{
	if (data->keys[113] && data->player.fov < 158)
	{
		data->player.fov += 2;
		data->player.fov_factor = JSP * (float)(FOV_BASE) / \
		(float)(data->player.fov);
	}
	if (data->keys[101] && data->player.fov > 2)
	{
		data->player.fov -= 2;
		data->player.fov_factor = JSP * (float)(FOV_BASE) / \
		(float)(data->player.fov);
	}
}
