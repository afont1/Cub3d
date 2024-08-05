/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:52:08 by afont             #+#    #+#             */
/*   Updated: 2024/08/05 14:54:24 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 256)
		data->keys[i] = 0;
	data->map.size = ((MAP_RANGE + 1) * MAP_SQUARE_SIZE);
	data->map.cen_map = (MAP_RANGE / 2) * MAP_SQUARE_SIZE + \
	MAP_SQUARE_SIZE / 2;
	data->all_img.north_wall.path = NULL;
	data->all_img.south_wall.path = NULL;
	data->all_img.west_wall.path = NULL;
	data->all_img.east_wall.path = NULL;
	data->all_img.weapon_anim[0].coord_x = 650;
	data->all_img.weapon_anim[0].sprite = 1;
	data->all_img.weapon_anim[1].coord_x = 650;
	data->all_img.weapon_anim[1].sprite = 0;
	data->all_img.weapon_anim[2].coord_x = 800;
	data->all_img.weapon_anim[2].sprite = 1;
	data->all_img.weapon_anim[3].coord_x = 650;
	data->all_img.weapon_anim[3].sprite = 0;
}

void	ft_init_player_pos_angle2(t_data *data, int i, int j)
{
	if (data->map.tab_map[i][j] == 'E' || data->map.tab_map[i][j] == 'W')
	{
		if (data->map.tab_map[i][j] == 'E')
		{
			data->player.dir_x = 0.0;
			data->player.dir_y = 1.0;
			data->player.plane_x = 0.726;
			data->player.plane_y = 0.0;
		}
		else if (data->map.tab_map[i][j] == 'W')
		{
			data->player.dir_x = 0.0;
			data->player.dir_y = -1.0;
			data->player.plane_x = -0.726;
			data->player.plane_y = 0.0;
		}
	}
}

int	ft_init_player_pos_angle(t_data *data, int i, int j)
{
	if (data->map.tab_map[i][j] == 'N' || data->map.tab_map[i][j] == 'S' \
	|| data->map.tab_map[i][j] == 'E' || data->map.tab_map[i][j] == 'W')
	{
		if (data->map.tab_map[i][j] == 'N')
		{
			data->player.dir_x = -1.0;
			data->player.dir_y = 0.0;
			data->player.plane_x = 0.0;
			data->player.plane_y = 0.726;
		}
		else if (data->map.tab_map[i][j] == 'S')
		{
			data->player.dir_x = 1.0;
			data->player.dir_y = 0.0;
			data->player.plane_x = 0.0;
			data->player.plane_y = -0.726;
		}
		ft_init_player_pos_angle2(data, i, j);
		data->map.tab_map[i][j] = '0';
		data->player.x = i + 0.5;
		data->player.y = j + 0.5;
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
	data->player.speed = SPEED;
	data->player.angle_step = ANGLE_STEP;
}
