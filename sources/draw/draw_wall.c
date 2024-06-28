/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:02:00 by afont             #+#    #+#             */
/*   Updated: 2024/06/27 16:30:09 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_var_texture_vertical(t_data *data, int k)
{
	double	tex_x;

	tex_x = (int)data->ray_data[k].rx % JSP;
	tex_x = JSP - 1 - tex_x;
	if (data->ray_data[k].ray_angle > M_PI)
	{
		tex_x = JSP - 1 - tex_x;
		data->all_img.side_ptr = &data->all_img.north_wall;
		return (tex_x);
	}
	data->all_img.side_ptr = &data->all_img.south_wall;
	return (tex_x);
}

double	ft_var_texture_horizontal(t_data *data, int k)
{
	double	tex_x;

	tex_x = (int)data->ray_data[k].ry % JSP;
	if (data->ray_data[k].ray_angle > M_PI2 && \
	data->ray_data[k].ray_angle < M_PI3)
	{
		tex_x = JSP - 1 - tex_x;
		data->all_img.side_ptr = &data->all_img.west_wall;
		return (tex_x);
	}
	data->all_img.side_ptr = &data->all_img.east_wall;
	return (tex_x);
}

t_coord	ft_var_texture(t_data *data, int k)
{
	t_coord	tex;

	tex.y = data->ray_data[k].ty_offset * data->ray_data[k].ty_step;
	if (data->ray_data[k].is_vertical == 1)
		tex.x = ft_var_texture_vertical(data, k);
	else
		tex.x = ft_var_texture_horizontal(data, k);
	return (tex);
}

int	ft_draw_wall(t_data *data, t_img *img, int k, double offset)
{
	int		i;
	t_coord	texture;

	texture = ft_var_texture(data, k);
	i = -1;
	while (++i < data->ray_data[k].line_height)
	{
		ft_pixel_put(*img, k, offset++, \
		ft_get_color(data->all_img.side_ptr, texture.x, texture.y));
		texture.y += data->ray_data[k].ty_step;
	}
	return (i);
}
