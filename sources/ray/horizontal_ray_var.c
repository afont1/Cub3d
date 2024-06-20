/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:55:57 by afont             #+#    #+#             */
/*   Updated: 2024/06/19 09:31:54 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_horizontal_var2(t_data *data, t_coord *ray_coord, t_coord *offset, \
double ray_angle)
{
	double	a_tan;

	a_tan = -1 / tan(ray_angle);
	ray_coord->y = (((int)data->player.pos.y / JSP) * JSP) - 0.0001;
	ray_coord->x = (data->player.pos.y - ray_coord->y) * a_tan + \
	data->player.pos.x;
	offset->y = -JSP;
	offset->x = -offset->y * a_tan;
}

void	ft_horizontal_var3(t_data *data, t_coord *ray_coord, t_coord *offset, \
double ray_angle)
{
	double	a_tan;

	a_tan = -1 / tan(ray_angle);
	ray_coord->y = (((int)data->player.pos.y / JSP) * JSP) + JSP;
	ray_coord->x = (data->player.pos.y - ray_coord->y) * a_tan + \
	data->player.pos.x;
	offset->y = JSP;
	offset->x = -offset->y * a_tan;
}

int	ft_horizontal_var(t_data *data, t_coord *ray_coord, t_coord *offset, \
double ray_angle)
{
	if (ray_angle > M_PI)
		ft_horizontal_var2(data, ray_coord, offset, ray_angle);
	else if (ray_angle < M_PI)
		ft_horizontal_var3(data, ray_coord, offset, ray_angle);
	else if (ray_angle == 0 || ray_angle == M_PI)
	{
		ray_coord->x = data->player.pos.x;
		ray_coord->y = data->player.pos.y;
		return (0);
	}
	return (1);
}
