/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:24:27 by afont             #+#    #+#             */
/*   Updated: 2024/06/14 14:27:56 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_angle_loop(double angle)
{
	if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}


double	ft_dist_ang(double player_angle, int *d, int flag)
{
	double	a;

	if (flag)
		a = player_angle + ((FOV * (M_PI / 180)) / 2);
	else
		a = player_angle - ((FOV * (M_PI / 180)) / 2);
	a = ft_angle_loop(a);
	if ((a <= (5 * M_PI / 4) && a >= (3 * M_PI / 4)) || (a >= (7 * M_PI / 4) \
	&& a <= 2 * (M_PI)) || (a <= (M_PI / 4) && a >= 0))
		*d = abs((int)(((MAP_SIZE) / 2) / cos(a)));
	else
		*d = abs((int)(((MAP_SIZE) / 2) / sin(a)));
	return (a);
}
