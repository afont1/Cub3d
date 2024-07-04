/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:27:10 by afont             #+#    #+#             */
/*   Updated: 2024/07/03 10:51:10 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_sprint(t_data *data)
{
	if (data->keys[2] && data->keys[UP] && data->player.fov < FOV + 10)
	{
		data->player.fov += 10;
		data->player.fov_factor = JSP * (float)(FOV_BASE) / \
		(float)(data->player.fov);
		data->player.speed = SPEED + 100;
	}
	else if (!data->keys[2] || !data->keys[UP])
	{
		data->player.fov = FOV;
		data->player.fov_factor = JSP * (float)(FOV_BASE) / \
		(float)(data->player.fov);
		data->player.speed = SPEED;
	}
}
