/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:13:42 by afont             #+#    #+#             */
/*   Updated: 2024/07/30 09:08:53 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_update(t_data *data)
{
	struct timeval			start;
	struct timeval			end;
	
	gettimeofday(&start, NULL);
	ft_draw_all(data);
	gettimeofday(&end, NULL);
	data->elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
	
	ft_display_all(data);
	ft_mouvement(data);
	// printf("%f, %f\n", data->player.plane_x, data->player.plane_y);
	ft_fps_counter(data);
	return (0);
}