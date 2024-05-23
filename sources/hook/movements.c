/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:36:04 by afont             #+#    #+#             */
/*   Updated: 2024/05/23 13:03:54 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_key_press(int key, t_data *data)
{
	if (key > 0 && key < 256)
		data->keys[key] = 1;
	else if (key == 65307)
		ft_close_window(data);
	return (0);
}

int ft_key_release(int key, t_data *data)
{
	if (key > 0 && key < 256)
		data->keys[key] = 0;
	return (0);
}

int	ft_update(t_data *data)
{
	static int	frame;

	frame++;
	if (frame == 800)
	{
		if (data->keys[UP])
			ft_draw_cube(data, data->player_angle);
		if (data->keys[DOWN])
			ft_draw_cube(data, data->player_angle + M_PI);
		if (data->keys[LEFT])
		{
			if (data->player_angle < 0)
				data->player_angle += 2 * M_PI;
			data->player_angle -= ANGLE_STEP;
		}
		if (data->keys[RIGHT])
		{
			if (data->player_angle > 2 * M_PI)
				data->player_angle -= 2 * M_PI;
			data->player_angle += ANGLE_STEP;
		}
		ft_draw_map(data);
		ft_put_image_to_window(data, data->img, CUBE_COLOR);
		ft_ray(data);
		frame = 0;
	}
	return (0);
}
