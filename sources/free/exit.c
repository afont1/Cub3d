/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:27:49 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 00:25:35 by bloisel          ###   ########.fr       */
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
