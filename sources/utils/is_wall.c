/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:05:17 by afont             #+#    #+#             */
/*   Updated: 2024/06/19 09:25:11 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = x / (JSP);
	map_y = y / (JSP);
	if (map_x < 0 || map_y < 0 || map_x >= data->map.width || \
	map_y >= data->map.height)
		return (1);
	return (data->map.tab_map[map_y][map_x] == '1');
}
