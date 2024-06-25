/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:02:00 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 16:37:28 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_coord	ft_var_texture(t_data *data, int k)
{
	t_coord	tex;

	if (data->ray_data[k].is_vertical == 1)
	{
		tex.x = (int)data->ray_data[k].rx % JSP;
		tex.x = JSP - 1 - tex.x;
		if (data->ray_data[k].ray_angle > M_PI)
			tex.x = JSP - 1 - tex.x;
	}
	else
	{
		tex.x = (int)data->ray_data[k].ry % JSP;
		if (data->ray_data[k].ray_angle > M_PI2 && \
		data->ray_data[k].ray_angle < M_PI3)
			tex.x = JSP - 1 - tex.x;
	}
	tex.y = data->ray_data[k].ty_offset * data->ray_data[k].ty_step;
	return (tex);
}

int	ft_draw_wall(t_data *data, t_img *img, int k, double offset)
{
	int		i;
	int		i_off;
	t_coord	texture;

	texture = ft_var_texture(data, k);
	i = 0;
	i_off = i + offset;
	while (i++ < data->ray_data[k].line_height)
	{
		ft_pixel_put(*img, k, i_off++, \
		ft_get_color(&data->all_img.red_wall, texture.x, texture.y));
		texture.y += data->ray_data[k].ty_step;
	}
	return (i);
}
