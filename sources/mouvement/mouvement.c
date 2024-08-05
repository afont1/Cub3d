/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:11:42 by afont             #+#    #+#             */
/*   Updated: 2024/08/05 13:40:48 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_move_player(t_data *data, double move_speed, int flag)
{
	if (flag)
	{
		if (!ft_collision(data, (int)(data->player.x + data->player.dir_x
				* move_speed), (int)data->player.y))
			data->player.x += data->player.dir_x * move_speed;
		if (!ft_collision(data, (int)data->player.x,
				(int)(data->player.y + data->player.dir_y * move_speed)))
			data->player.y += data->player.dir_y * move_speed;
		ft_door(data, move_speed, 1);
	}
	else
	{
		if (!ft_collision(data, (int)(data->player.x
				- data->player.dir_x * move_speed), (int)data->player.y))
			data->player.x -= data->player.dir_x * move_speed;
		if (!ft_collision(data, (int)data->player.x, (int)(data->player.y
				- data->player.dir_y * move_speed)))
			data->player.y -= data->player.dir_y * move_speed;
		ft_door(data, move_speed, 0);
	}
}

void	ft_turn_player2(t_data *data, double rot_s, double old_d, double old_pl)
{
	data->player.dir_x = (data->player.dir_x
			* cos(rot_s) - data->player.dir_y * sin(rot_s));
	data->player.dir_y = (old_d
			* sin(rot_s) + data->player.dir_y * cos(rot_s));
	data->player.plane_x = (data->player.plane_x
			* cos(rot_s) - data->player.plane_y * sin(rot_s));
	data->player.plane_y = (old_pl
			* sin(rot_s) + data->player.plane_y * cos(rot_s));
}

void	ft_turn_player(t_data *data, double rot_speed, int flag)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	if (flag)
	{
		data->player.dir_x = (data->player.dir_x
				* cos(-rot_speed) - data->player.dir_y * sin(-rot_speed));
		data->player.dir_y = (old_dir_x
				* sin(-rot_speed) + data->player.dir_y * cos(-rot_speed));
		data->player.plane_x = (data->player.plane_x
				* cos(-rot_speed) - data->player.plane_y * sin(-rot_speed));
		data->player.plane_y = (old_plane_x
				* sin(-rot_speed) + data->player.plane_y * cos(-rot_speed));
		if (data->player.angle_step < 0.0055)
			data->player.angle_step += 0.00003;
	}
	else
	{
		ft_turn_player2(data, rot_speed, old_dir_x, old_plane_x);
		if (data->player.angle_step < 0.0055)
			data->player.angle_step += 0.00003;
	}
}

void	ft_sprint(t_data *data)
{
	if (data->keys[2] && data->keys[UP] && data->player.speed < SPEED + 0.002)
	{
		data->player.speed = SPEED + 0.002;
		data->player.plane_x *= 1.1;
		data->player.plane_y *= 1.1;
	}
	else if ((!data->keys[2] || !data->keys[UP]) && data->player.speed > SPEED)
	{
		data->player.speed = SPEED;
		data->player.plane_x /= 1.1;
		data->player.plane_y /= 1.1;
	}
}

void	ft_mouvement(t_data *data)
{
	double	move_speed;

	data->player.rot_speed = data->elapsed_time * data->player.angle_step;
	move_speed = data->elapsed_time * data->player.speed;
	if (data->keys[UP])
		ft_move_player(data, move_speed, 1);
	if (data->keys[DOWN])
		ft_move_player(data, move_speed, 0);
	if (data->keys[RIGHT])
		ft_turn_player(data, data->player.rot_speed, 1);
	else if (!data->keys[LEFT])
		data->player.angle_step = ANGLE_STEP;
	if (data->keys[LEFT])
		ft_turn_player(data, data->player.rot_speed, 0);
	else if (!data->keys[RIGHT])
		data->player.angle_step = ANGLE_STEP;
	ft_sprint(data);
}
