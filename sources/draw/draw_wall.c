/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:02:00 by afont             #+#    #+#             */
/*   Updated: 2024/07/02 13:54:44 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_var_texture_vertical(t_data *data, int k)
{
	double	tex_x;
	t_pos	map_coord;

	map_coord.x = (int)data->ray_data[k].rx / JSP;
	map_coord.y = (int)data->ray_data[k].ry / JSP;
	tex_x = (int)data->ray_data[k].rx % JSP;
	tex_x = JSP - 1 - tex_x;
	if (data->ray_data[k].ray_angle > M_PI)
	{
		tex_x = JSP - 1 - tex_x;
		if (map_coord.y > 0 && data->map.tab_map[map_coord.y + 1][map_coord.x] == '3')
			data->all_img.side_ptr = &data->all_img.door_open;
		else
			data->all_img.side_ptr = &data->all_img.north_wall;
		return (tex_x);
	}
	if (map_coord.y < data->map.height && data->map.tab_map[map_coord.y - 1][map_coord.x] == '3')
		data->all_img.side_ptr = &data->all_img.door_open;
	else
		data->all_img.side_ptr = &data->all_img.south_wall;
	return (tex_x);
}

double	ft_var_texture_horizontal(t_data *data, int k)
{
	double	tex_x;
	t_pos	map_coord;

	map_coord.x = (int)data->ray_data[k].rx / JSP;
	map_coord.y = (int)data->ray_data[k].ry / JSP;
	tex_x = (int)data->ray_data[k].ry % JSP;
	if (data->ray_data[k].ray_angle > M_PI2 && \
	data->ray_data[k].ray_angle < M_PI3)
	{
		tex_x = JSP - 1 - tex_x;
		if (map_coord.x > 0 && data->map.tab_map[map_coord.y][map_coord.x + 1] == '3')
			data->all_img.side_ptr = &data->all_img.door_open;
		else
			data->all_img.side_ptr = &data->all_img.west_wall;
		return (tex_x);
	}
	if (map_coord.x < data->map.width && data->map.tab_map[map_coord.y][map_coord.x - 1] == '3')
		data->all_img.side_ptr = &data->all_img.door_open;
	else
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
	if (data->ray_data[k].carac == '2')
		data->all_img.side_ptr = &data->all_img.door;
	if (data->ray_data[k].carac == '3')
	{
		printf("Door open\n");
		data->all_img.side_ptr = &data->all_img.door_open;
	}
	return (tex);
}

int	ft_draw_wall(t_data *data, t_img *img, int k, double offset)
{
	int		i;
	int		color;
	t_coord	texture;

	texture = ft_var_texture(data, k);
	i = -1;
	while (++i < data->ray_data[k].line_height)
	{
		color = ft_get_color(data->all_img.side_ptr, texture.x, texture.y);
		if (color != -16777216)
			ft_pixel_put(*img, k, offset++, color);
		texture.y += data->ray_data[k].ty_step;
	}
	return (i);
}
