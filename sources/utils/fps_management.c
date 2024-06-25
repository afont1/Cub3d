/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:33:03 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 14:40:46 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*fps_counter(t_data *data)
{
	static struct timeval	last_update;
	struct timeval			now;
	long					elapsed_time;
	static int				fps;

	gettimeofday(&now, NULL);
	elapsed_time = (now.tv_sec - last_update.tv_sec) * \
	1000000 + (now.tv_usec - last_update.tv_usec);
	if (elapsed_time < (1000000 / FPS))
	{
		usleep((1000000 / FPS) - elapsed_time);
		gettimeofday(&now, NULL);
	}
	elapsed_time = (now.tv_sec - last_update.tv_sec) * \
	1000000 + (now.tv_usec - last_update.tv_usec);
	if ((now.tv_sec - last_update.tv_sec) >= 1)
	{
		fps = 1000000.0 / elapsed_time;
	}
	data->player.delta_time = (double)elapsed_time / 1000000.0;
	last_update = now;
	return (ft_itoa(fps));
}
