/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:53:15 by afont             #+#    #+#             */
/*   Updated: 2024/07/03 11:53:04 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_mouse_hook(t_data *data)
{
	static int	last_x;
	int			delta_x;
	int			x;
	int			y;

	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &x, &y);
	// mlx_mouse_move(data->mlx_ptr, data->win_ptr, 0, 0);
	// mlx_mouse_hide(data->mlx_ptr, data->win_ptr);
	// mlx_mouse_show(data->mlx_ptr, data->win_ptr);
	delta_x = x - last_x;
	if (last_x > 0 && delta_x != 0)
		ft_turn_player(data, delta_x > 0);
	last_x = x;
	return (1);
}
