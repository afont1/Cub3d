/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:00:23 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 16:49:39 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_exit_map(t_data *data, char *str)
{
	int	i;

	i = -1;
	while (++i < data->map.height)
		free(data->map.tab_map[i]);
	free(data->map.tab_map);
	free(data->ray_data);
	free(data);
	printf("%s", str);
	exit(0);
}

void	ft_exit_open(t_data *data, char *str)
{
	if (data->map.tab_map)
		free(data->map.tab_map);
	free(data->ray_data);
	free(data);
	printf("%s", str);
	exit(0);
}
