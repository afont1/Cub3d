/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:47:12 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 15:05:27 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_vertical_var2(t_data *data, t_coord *ray_coord, t_coord *offset, \
double ray_angle)
{
	double	n_tan;

	n_tan = -tan(ray_angle);
	ray_coord->x = (((int)data->player.pos.x / JSP) * JSP) - 0.0001;
	ray_coord->y = (data->player.pos.x - ray_coord->x) * n_tan + \
	data->player.pos.y;
	offset->x = -JSP;
	offset->y = -offset->x * n_tan;
}

void	ft_vertical_var3(t_data *data, t_coord *ray_coord, t_coord *offset, \
double ray_angle)
{
	double	n_tan;

	n_tan = -tan(ray_angle);
	ray_coord->x = (((int)data->player.pos.x / JSP) * JSP) + JSP;
	ray_coord->y = (data->player.pos.x - ray_coord->x) * n_tan + \
	data->player.pos.y;
	offset->x = JSP;
	offset->y = -offset->x * n_tan;
}

void	ft_vertical_var(t_data *data, t_coord *ray_coord, t_coord *offset, \
double ray_angle)
{
	ray_coord->x = 0;
	ray_coord->y = 0;
	offset->x = 0;
	offset->y = 0;
	if (ray_angle > M_PI2 && ray_angle < M_PI3)
		ft_vertical_var2(data, ray_coord, offset, ray_angle);
	else if (ray_angle < M_PI2 || ray_angle > M_PI3)
		ft_vertical_var3(data, ray_coord, offset, ray_angle);
}
