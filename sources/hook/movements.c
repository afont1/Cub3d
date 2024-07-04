/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:36:04 by afont             #+#    #+#             */
/*   Updated: 2024/07/04 09:37:35 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_mouvement(t_data *data)
{
	if (data->keys[UP] || data->keys[DOWN] || data->keys[RIGHT] || data->keys[LEFT])
		return (1);
	return (0);
}

int	ft_key_press(int key, t_data *data)
{
	if (key > 0 && key < 256)
		data->keys[key] = 1;
	else if (key == ESC)
		ft_close_window(data);
	else if (key == R_ARROW)
		data->keys[0] = 1;
	else if (key == L_ARROW)
		data->keys[1] = 1;
	else if (key == SHIFT)
		data->keys[2] = 1;
	return (0);
}

int	ft_key_release(int key, t_data *data)
{
	if (key > 0 && key < 256)
		data->keys[key] = 0;
	else if (key == R_ARROW)
		data->keys[0] = 0;
	else if (key == L_ARROW)
		data->keys[1] = 0;
	else if (key == SHIFT)
		data->keys[2] = 0;
	return (0);
}

void	ft_turn_player(t_data *data, int flag)
{
	double	old_dir_x;
	double	old_plane_x;
	old_dir_x = data->player.dirX;
	old_plane_x = data->player.planeX;

	// data->player.dirX = cos(data->player.angle);
	// data->player.dirY = sin(data->player.angle);
	if (flag)
	{
		if (data->player.angle < 0.0)
			data->player.angle += 2 * M_PI;
		data->player.angle -= data->player.angle_step * data->player.delta_time;
		if (data->player.angle_step < 4)
			data->player.angle_step += 0.1;
			
		data->player.dirX = data->player.dirX * cos(-data->player.angle_step * data->player.delta_time) - data->player.dirY * sin(-data->player.angle_step * data->player.delta_time);
		data->player.dirY = old_dir_x * sin(-data->player.angle_step * data->player.delta_time) + data->player.dirY * cos(-data->player.angle_step * data->player.delta_time);
		data->player.planeX = data->player.planeX * cos(-data->player.angle_step * data->player.delta_time) - data->player.planeY * sin(-data->player.angle_step * data->player.delta_time);
		data->player.planeY = old_plane_x * sin(-data->player.angle_step * data->player.delta_time) + data->player.planeY * cos(-data->player.angle_step * data->player.delta_time);
	}
	else
	{
		if (data->player.angle > 2 * M_PI)
			data->player.angle -= 2 * M_PI;
		data->player.angle += data->player.angle_step * data->player.delta_time;
		if (data->player.angle_step < 4)
			data->player.angle_step += 0.1;
		data->player.dirX = data->player.dirX * cos(data->player.angle_step * data->player.delta_time) - data->player.dirY * sin(data->player.angle_step * data->player.delta_time);
		data->player.dirY = old_dir_x * sin(data->player.angle_step * data->player.delta_time) + data->player.dirY * cos(data->player.angle_step * data->player.delta_time);
		data->player.planeX = data->player.planeX * cos(data->player.angle_step * data->player.delta_time) - data->player.planeY * sin(data->player.angle_step * data->player.delta_time);
		data->player.planeY = old_plane_x * sin(data->player.angle_step * data->player.delta_time) + data->player.planeY * cos(data->player.angle_step * data->player.delta_time);
	}
}

int	ft_update(t_data *data)
{
	if (data->keys[UP])
		ft_move_player(data, data->player.angle);
	if (data->keys[DOWN])
		ft_move_player(data, data->player.angle + M_PI);
	if (data->keys[RIGHT])
		ft_move_player(data, data->player.angle + M_PI2);
	if (data->keys[LEFT])
		ft_move_player(data, data->player.angle - M_PI2);
	if (data->keys[1])
		ft_turn_player(data, 1);
	else if (!data->keys[1])
		data->player.angle_step = ANGLE_STEP;
	if (data->keys[0])
		ft_turn_player(data, 0);
	else if (!data->keys[0])
		data->player.angle_step = ANGLE_STEP;
	ft_mouse_hook(data);
	ft_sprint(data);
	ft_draw_all(data);
	ft_display_all(data);
	return (0);
}
