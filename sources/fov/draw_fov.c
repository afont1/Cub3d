/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:34:15 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 00:23:27 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_fill_triangle(t_img img, t_pos pos1, t_pos pos2, t_pos pos3)
{
	int		y;
	int		x;
	t_pos	xes;
	t_slope	slp;

	ft_swap_pos(&pos1, &pos2, &pos3);
	slp = ft_init_slope(pos1, pos2, pos3);
	y = pos1.y - 1;
	while (++y <= pos3.y)
	{
		xes = ft_init_x_fov(slp, pos1, pos2, y);
		x = xes.x - 1;
		while (++x <= xes.y)
			ft_pixel_put(img, x, y, ft_get_color(&img, x, y) + 0x202020);
	}
}

void	ft_fill_gap(t_data *data, t_img img, t_coord angl, t_pos dist)
{
	t_pos	pos1;
	t_pos	pos2;
	t_pos	pos3;

	pos1.x = data->map.cen_map + cos(angl.x) * dist.x;
	pos1.y = data->map.cen_map + sin(angl.x) * dist.x;
	pos2.x = data->map.cen_map + cos(angl.y) * dist.y;
	pos2.y = data->map.cen_map + sin(angl.y) * dist.y;
	ft_var_pos(data, &pos3, angl.x);
	if ((angl.x <= M_PI / 4 && angl.x >= 0) || (angl.x >= 345 * (M_PI / 180)))
		ft_fill_triangle(img, pos1, pos2, pos3);
	else if (angl.x >= 75 * (M_PI / 180) && angl.x <= 3 * M_PI / 4)
		ft_fill_triangle(img, pos1, pos2, pos3);
	else if (angl.x >= 165 * (M_PI / 180) && angl.x <= 5 * M_PI / 4)
		ft_fill_triangle(img, pos1, pos2, pos3);
	else if (angl.x >= 255 * (M_PI / 180) && angl.x <= 7 * M_PI / 4)
		ft_fill_triangle(img, pos1, pos2, pos3);
}

void	ft_draw_fov(t_data *data, t_img img)
{
	t_pos	dist;
	t_pos	pos1;
	t_pos	pos2;
	t_pos	pos3;
	t_coord	angl;

	data->player.angle = ft_angle_loop(atan2(data->player.dir_x,
				data->player.dir_y));
	angl.x = ft_dist_ang(data, data->player.angle, &dist.x, 0);
	angl.y = ft_dist_ang(data, data->player.angle, &dist.y, 1);
	pos1.x = data->map.cen_map;
	pos1.y = data->map.cen_map;
	pos2.x = data->map.cen_map + cos(angl.x) * dist.x;
	pos2.y = data->map.cen_map + sin(angl.x) * dist.x;
	pos3.x = data->map.cen_map + cos(angl.y) * dist.y;
	pos3.y = data->map.cen_map + sin(angl.y) * dist.y;
	ft_fill_triangle(img, pos1, pos2, pos3);
	ft_fill_gap(data, img, angl, dist);
}
