/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_is_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:52:12 by afont             #+#    #+#             */
/*   Updated: 2024/06/27 15:54:00 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_texture_is_init(t_data *data, char *line)
{
	if (data->all_img.north_wall.path && data->all_img.south_wall.path && \
	data->all_img.west_wall.path && data->all_img.east_wall.path && \
	data->all_img.floor_color != -1 && data->all_img.ceiling_color != -1)
	{
		free(line);
		return (1);
	}
	return (0);
}
