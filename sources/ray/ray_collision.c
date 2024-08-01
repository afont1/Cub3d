/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:34:52 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 05:05:16 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_color(t_data *data, int map_x, int map_y, int tex_x, int tex_y)
{
	int	color;

	color = 0;
	if (data->map.tab_map[map_x][map_y] == '1')
		color = ft_get_color(data->all_img.side_ptr, tex_x, tex_y);
	else if (data->map.tab_map[map_x][map_y] == '2')
		color = ft_get_color(&data->all_img.door, tex_x, tex_y);
	else if (data->map.tab_map[map_x][map_y] == '4')
		color = ft_get_color(&data->all_img.deco1, tex_x, tex_y);
	return (color);
}

int	ft_collision(t_data *data, int map_x, int map_y)
{
	int	c;

	c = data->map.tab_map[map_x][map_y];
	return (c == '1' || c == '2' || c == '4');
}
