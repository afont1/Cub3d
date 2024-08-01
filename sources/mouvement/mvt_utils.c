/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:56:07 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 01:44:27 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_mouvement(t_data *data)
{
	if (data->keys[UP] || data->keys[DOWN]
		|| data->keys[RIGHT] || data->keys[LEFT])
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

void	ft_door(t_data *data, double move_speed, int flag)
{
	static t_pos	last_door;
	int				x_move;
	int				y_move;

	x_move = (int)(data->player.x + data->player.dir_x * move_speed * 5);
	y_move = (int)(data->player.y + data->player.dir_y * move_speed * 5);
	if ((x_move >= 0 && x_move < data->map.height)
		&& (y_move >= 0 && y_move < data->map.width))
	{
		if (flag && data->map.tab_map[x_move][y_move] == '2')
		{
			data->map.tab_map[x_move][y_move] = '3';
			last_door.x = x_move;
			last_door.y = y_move;
		}
	}
	if (last_door.x && ft_dist_int((int)data->player.x,
			(int)data->player.y, last_door.x, last_door.y) > 3)
	{
		data->map.tab_map[last_door.x][last_door.y] = '2';
		last_door.x = 0;
	}
}
