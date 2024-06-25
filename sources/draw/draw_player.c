/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:32:42 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 16:41:06 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_round_number(double number)
{
	if (number > 0)
	{
		if (number - (int)number < 0.5)
			return ((int)number);
		else
			return ((int)number + 1);
	}
	else
	{
		if (number - (int)number > -0.5)
			return ((int)number);
		else
			return ((int)number - 1);
	}
}

int	check_circle_collision(t_data *data, int x0, int y0, int radius)
{
	double	angle;

	angle = 0;
	while (angle < 2 * M_PI)
	{
		if (is_wall(data, x0 + radius * cos(angle), y0 + radius * sin(angle)))
			return (1);
		angle += 1;
	}
	return (0);
}

void	ft_move_player(t_data *data, double angle)
{
	int	x_mv;
	int	y_mv;

	x_mv = ft_round_number(SPEED * cos(angle) * data->player.delta_time);
	y_mv = ft_round_number(SPEED * sin(angle) * data->player.delta_time);
	if (!check_circle_collision(data, data->player.pos.x + x_mv, \
	data->player.pos.y, CIRCLE_RAD))
		data->player.pos.x += x_mv;
	if (!check_circle_collision(data, data->player.pos.x, data->player.pos.y \
	+ y_mv, CIRCLE_RAD))
		data->player.pos.y += y_mv;
}

void	ft_draw_circle(t_data *data, int x0, int y0, int color)
{
	int	x;
	int	y;

	y = -CIRCLE_RAD - 1;
	while (++y <= CIRCLE_RAD)
	{
		x = -CIRCLE_RAD - 1;
		while (++x <= CIRCLE_RAD)
			if (x * x + y * y <= CIRCLE_RAD * CIRCLE_RAD)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0 + x, y0 \
				+ y, color);
	}
}
