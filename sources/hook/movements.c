/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:36:04 by afont             #+#    #+#             */
/*   Updated: 2024/05/22 09:49:58 by afont            ###   ########.fr       */
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
	if (frame == 50)
	{
		if (data->keys[UP])
			ft_move(data, 0, -1);
		if (data->keys[DOWN])
			ft_move(data, 0, 1);
		if (data->keys[LEFT])
			ft_move(data, -1, 0);
		if (data->keys[RIGHT])
			ft_move(data, 1, 0);
		frame = 0;
	}
	return (0);
}

void	ft_move(t_data *data, int x_mv, int y_mv)
{
	// ft_del_img(data);
	ft_render_map(data);
	if (data->img.pos.x + x_mv < WIN_WIDTH - CUBE_SIZE && data->img.pos.x + x_mv > 0)
		data->img.pos.x += x_mv;
	if (data->img.pos.y + y_mv < WIN_HEIGHT - CUBE_SIZE && data->img.pos.y + y_mv > 0)
		data->img.pos.y += y_mv;
	ft_put_image_to_window(data, data->img, CUBE_COLOR);
}
