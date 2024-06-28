/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:52:08 by afont             #+#    #+#             */
/*   Updated: 2024/06/28 08:34:22 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 256)
		data->keys[i] = 0;
	data->ray_data = malloc(sizeof(t_ray_data) * WIN_WIDTH);
	ft_protect_malloc(data->ray_data);
	data->map.cen_map = (MAP_RANGE / 2) * MAP_SQUARE_SIZE + \
	MAP_SQUARE_SIZE / 2;
	data->map.size = ((MAP_RANGE + 1) * MAP_SQUARE_SIZE);
	data->all_img.ceiling_color = -1;
	data->all_img.floor_color = -1;
	data->all_img.north_wall.path = NULL;
	data->all_img.south_wall.path = NULL;
	data->all_img.west_wall.path = NULL;
	data->all_img.east_wall.path = NULL;
}

int	ft_init_player_pos_angle(t_data *data, int i, int j)
{
	if (data->map.tab_map[i][j] == 'N' || data->map.tab_map[i][j] == 'S' \
	|| data->map.tab_map[i][j] == 'E' || data->map.tab_map[i][j] == 'W')
	{
		if (data->map.tab_map[i][j] == 'N')
			data->player.angle = M_PI3;
		else if (data->map.tab_map[i][j] == 'S')
			data->player.angle = M_PI2;
		else if (data->map.tab_map[i][j] == 'E')
			data->player.angle = 0;
		else if (data->map.tab_map[i][j] == 'W')
			data->player.angle = M_PI;
		data->map.tab_map[i][j] = '0';
		data->player.pos.x = j * JSP + JSP / 2;
		data->player.pos.y = i * JSP + JSP / 2;
		return (1);
	}
	return (0);
}

void	ft_init_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.tab_map[++i])
	{
		j = -1;
		while (data->map.tab_map[i][++j])
			if (ft_init_player_pos_angle(data, i, j))
				break ;
	}
	data->player.fov = FOV;
	data->player.radius = CIRCLE_RAD;
	data->player.color = 0x00FF00;
	data->player.angle_step = ANGLE_STEP;
	data->player.fov_factor = JSP * (float)(FOV_BASE) / \
	(float)(data->player.fov);
}
