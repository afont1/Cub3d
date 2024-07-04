/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:32:42 by afont             #+#    #+#             */
/*   Updated: 2024/07/03 10:30:51 by afont            ###   ########.fr       */
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
	double			angle;
	static t_pos	last;

	angle = 0;
	while (angle < 2 * M_PI)
	{
		// printf("%d, %d\n%d, %d\n%d\n\n", data->player.pos.x / JSP, data->player.pos.y / JSP, last.x, last.y, ft_dist_int(data->player.pos.x / JSP, data->player.pos.y / JSP, last.x, last.y));
		if (is_wall(data, x0 + radius * cos(angle), y0 + radius * sin(angle)) == 1)
			return (1);
		
		else if (is_wall(data, x0 + (radius + 200) * cos(angle), y0 + (radius + 200) * sin(angle)) == 2)
		{
			last.x = (x0 + (radius + 200) * cos(angle)) / JSP;
			last.y = (y0 + (radius + 200) * sin(angle)) / JSP;
			data->map.tab_map[last.y][last.x] = '3';
			return (0);
		}
		else if (last.x && ft_dist_int(data->player.pos.x / JSP, data->player.pos.y / JSP, last.x, last.y) > 3)
		{
			data->map.tab_map[last.y][last.x] = '2';
			last.x = 0;
		}
		angle += 0.4;
	}
	return (0);
}

void	ft_move_player(t_data *data, double angle)
{
	int	x_mv;
	int	y_mv;

	x_mv = ft_round_number(data->player.speed * cos(angle) * data->player.delta_time);
	y_mv = ft_round_number(data->player.speed * sin(angle) * data->player.delta_time);
	if (!check_circle_collision(data, data->player.pos.x + x_mv, \
	data->player.pos.y, CIRCLE_RAD))
		data->player.pos.x += x_mv;
	if (!check_circle_collision(data, data->player.pos.x, data->player.pos.y \
	+ y_mv, CIRCLE_RAD))
		data->player.pos.y += y_mv;
}
