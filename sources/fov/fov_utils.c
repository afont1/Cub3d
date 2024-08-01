/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:05:19 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 00:24:57 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_dist_ang(t_data *data, double player_angle, int *d, int flag)
{
	double	a;

	if (flag)
		a = player_angle + ((60 * (M_PI / 180)) / 2);
	else
		a = player_angle - ((60 * (M_PI / 180)) / 2);
	a = ft_angle_loop(a);
	if ((a <= (5 * M_PI / 4) && a >= (3 * M_PI / 4))
		|| (a >= (7 * M_PI / 4) && a <= 2 * (M_PI))
		|| (a <= (M_PI / 4) && a >= 0))
		*d = abs((int)(((data->map.size) / 2) / cos(a)));
	else
		*d = abs((int)(((data->map.size) / 2) / sin(a)));
	return (a);
}

void	ft_var_pos(t_data *data, t_pos *pos, double a1)
{
	if ((a1 <= M_PI / 4 && a1 >= 0) || (a1 >= 345 * (M_PI / 180)))
	{
		pos->x = data->map.size;
		pos->y = data->map.size;
	}
	else if (a1 >= 75 * (M_PI / 180) && a1 <= 3 * M_PI / 4)
	{
		pos->x = 0;
		pos->y = data->map.size;
	}
	else if (a1 >= 165 * (M_PI / 180) && a1 <= 5 * M_PI / 4)
	{
		pos->x = 0;
		pos->y = 0;
	}
	else if (a1 >= 255 * (M_PI / 180) && a1 <= 7 * M_PI / 4)
	{
		pos->x = data->map.size;
		pos->y = 0;
	}
}

void	ft_swap_pos(t_pos *pos1, t_pos *pos2, t_pos *pos3)
{
	if (pos2->y < pos1->y)
	{
		swap(&pos1->x, &pos2->x);
		swap(&pos1->y, &pos2->y);
	}
	if (pos3->y < pos1->y)
	{
		swap(&pos1->x, &pos3->x);
		swap(&pos1->y, &pos3->y);
	}
	if (pos3->y < pos2->y)
	{
		swap(&pos2->x, &pos3->x);
		swap(&pos2->y, &pos3->y);
	}
}

t_slope	ft_init_slope(t_pos pos1, t_pos pos2, t_pos pos3)
{
	t_slope	slope;

	slope.s1 = 0;
	if (pos2.y - pos1.y > 0)
		slope.s1 = (float)(pos2.x - pos1.x) / (pos2.y - pos1.y);
	slope.s2 = 0;
	if (pos3.y - pos1.y > 0)
		slope.s2 = (float)(pos3.x - pos1.x) / (pos3.y - pos1.y);
	slope.s3 = 0;
	if (pos3.y - pos2.y > 0)
		slope.s3 = (float)(pos3.x - pos2.x) / (pos3.y - pos2.y);
	return (slope);
}

t_pos	ft_init_x_fov(t_slope slp, t_pos pos1, t_pos pos2, int y)
{
	t_pos	xes;

	if (y < pos2.y)
	{
		xes.x = pos1.x + slp.s1 * (y - pos1.y);
		xes.y = pos1.x + slp.s2 * (y - pos1.y);
	}
	else
	{
		xes.x = pos2.x + slp.s3 * (y - pos2.y);
		xes.y = pos1.x + slp.s2 * (y - pos1.y);
	}
	if (xes.x > xes.y)
		swap(&xes.x, &xes.y);
	return (xes);
}
