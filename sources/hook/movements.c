/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:36:04 by afont             #+#    #+#             */
/*   Updated: 2024/06/04 10:35:08 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_key_press(int key, t_data *data)
{
	if (key > 0 && key < 256)
		data->keys[key] = 1;
	else if (key == 65307)
		ft_close_window(data);
	return (0);
}

int	ft_key_release(int key, t_data *data)
{
	if (key > 0 && key < 256)
		data->keys[key] = 0;
	return (0);
}

void	ft_turn_player(t_data *data, int flag)
{
	if (flag)
	{
		if (data->player.angle < 0)
			data->player.angle += 2 * M_PI;
		data->player.angle -= data->player.angle_step;
		if (data->player.angle_step < 0.13)
			data->player.angle_step += 0.005;
	}
	else
	{
		if (data->player.angle > 2 * M_PI)
			data->player.angle -= 2 * M_PI;
		data->player.angle += data->player.angle_step;
		if (data->player.angle_step < 0.13)
			data->player.angle_step += 0.005;
	}
}

int	ft_update(t_data *data)
{
	static int	frame;

	frame++;
	if (frame == 800)
	{
		if (data->keys[UP])
			ft_move_player(data, data->player.angle);
		if (data->keys[DOWN])
			ft_move_player(data, data->player.angle + M_PI);
		if (data->keys[LEFT])
			ft_turn_player(data, 1);
		else if (!data->keys[RIGHT])
			data->player.angle_step = ANGLE_STEP;
		if (data->keys[RIGHT])
			ft_turn_player(data, 0);
		else if (!data->keys[LEFT])
			data->player.angle_step = ANGLE_STEP;
		ft_draw_map(data);
		ft_draw_circle(data, data->player.pos.x, \
		data->player.pos.y, CUBE_COLOR);
		ft_ray(data);
		frame = 0;
	}
	return (0);
}
