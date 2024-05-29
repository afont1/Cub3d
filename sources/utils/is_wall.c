/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:05:17 by afont             #+#    #+#             */
/*   Updated: 2024/05/29 12:02:04 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = x / (WIN_HEIGHT / data->map.width);
	map_y = y / (WIN_HEIGHT / data->map.width);
	return (data->map.tab_map[map_y][map_x] == '1');
}
