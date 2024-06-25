/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:55:57 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 15:05:04 by afont            ###   ########.fr       */
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

void	ft_horizontal_var(t_data *data, t_coord *ray_coord, t_coord *offset, \
double ray_angle)
{
	ray_coord->x = 0;
	ray_coord->y = 0;
	offset->x = 0;
	offset->y = 0;
	if (ray_angle > M_PI)
		ft_horizontal_var2(data, ray_coord, offset, ray_angle);
	else if (ray_angle < M_PI)
		ft_horizontal_var3(data, ray_coord, offset, ray_angle);
}
