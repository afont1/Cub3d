/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:12:17 by afont             #+#    #+#             */
/*   Updated: 2024/08/05 14:15:04 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_cub3d(t_data *data, char *argv)
{
	int	cpt;

	cpt = ft_init_texture(data, argv);
	ft_check_texture(data);
	ft_init_map_data(data, argv, cpt);
	ft_check_map(data, data->map.tab_map);
	data->mlx_ptr = mlx_init();
	ft_protect_malloc(data->mlx_ptr);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	WIN_WIDTH, WIN_HEIGHT, "cub3D");
	ft_protect_malloc(data->win_ptr);
	ft_init_img(data);
	ft_init_player(data);
	mlx_mouse_hide(data->mlx_ptr, data->win_ptr);
	mlx_hook(data->win_ptr, 2, (1L << 0), ft_key_press, data);
	mlx_hook(data->win_ptr, 3, (1L << 1), ft_key_release, data);
	mlx_hook(data->win_ptr, 17, (1L << 2), ft_close_window, data);
	mlx_hook(data->win_ptr, 6, (1L << 6), ft_mouse_hook, data);
	mlx_loop_hook(data->mlx_ptr, ft_update, data);
	mlx_loop(data->mlx_ptr);
}
