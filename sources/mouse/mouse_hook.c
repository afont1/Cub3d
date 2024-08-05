/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:00:24 by afont             #+#    #+#             */
/*   Updated: 2024/08/05 14:11:02 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_mouse_hook(int x, int y, t_data *data)
{
	(void)y;
    float dx = x - WIN_WIDTH / 2;

	mlx_mouse_move(data->mlx_ptr, data->win_ptr, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (dx > 0)
		ft_turn_player(data, data->player.rot_speed * fabs(dx) / 700, 1);
	else if (dx < 0)
		ft_turn_player(data, data->player.rot_speed * fabs(dx) / 700, 0);
    return (0);
}