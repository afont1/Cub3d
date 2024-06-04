/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:47:12 by afont             #+#    #+#             */
/*   Updated: 2024/06/04 09:57:04 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_vertical_var2(t_data *data, t_coord *ray_coord, t_coord *offset, \
double ray_angle)
{
	double	n_tan;
	int		ratio;

	n_tan = -tan(ray_angle);
	ratio = WIN_HEIGHT / data->map.width;
	ray_coord->x = (((int)data->player.pos.x / ratio) * ratio) - 0.0001;
	ray_coord->y = (data->player.pos.x - ray_coord->x) * n_tan + \
	data->player.pos.y;
	offset->x = -ratio;
	offset->y = -offset->x * n_tan;
}

void	ft_vertical_var3(t_data *data, t_coord *ray_coord, t_coord *offset, \
double ray_angle)
{
	double	n_tan;
	int		ratio;

	n_tan = -tan(ray_angle);
	ratio = WIN_HEIGHT / data->map.width;
	ray_coord->x = (((int)data->player.pos.x / ratio) * ratio) + ratio;
	ray_coord->y = (data->player.pos.x - ray_coord->x) * n_tan + \
	data->player.pos.y;
	offset->x = ratio;
	offset->y = -offset->x * n_tan;
}

int	ft_vertical_var(t_data *data, t_coord *ray_coord, t_coord *offset, \
double ray_angle)
{
	if (ray_angle > M_PI2 && ray_angle < M_PI3)
		ft_vertical_var2(data, ray_coord, offset, ray_angle);
	if (ray_angle < M_PI2 || ray_angle > M_PI3)
		ft_vertical_var3(data, ray_coord, offset, ray_angle);
	if (ray_angle == 0 || ray_angle == M_PI)
	{
		ray_coord->x = data->player.pos.x;
		ray_coord->y = data->player.pos.y;
		return (0);
	}
	return (1);
}
