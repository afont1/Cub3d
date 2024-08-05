/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:27:49 by afont             #+#    #+#             */
/*   Updated: 2024/08/05 15:03:15 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_exit_map(t_data *data, char *str)
{
	free(data->all_img.north_wall.path);
	free(data->all_img.south_wall.path);
	free(data->all_img.west_wall.path);
	free(data->all_img.east_wall.path);
	free(data);
	printf("%s", str);
	exit(0);
}

void	ft_exit_before(t_data *data, char *str)
{
	if (data->map.tab_map)
		free(data->map.tab_map);
	if (data)
		free(data);
	printf("%s", str);
	exit(0);
}
