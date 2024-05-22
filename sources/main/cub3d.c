/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:12:17 by afont             #+#    #+#             */
/*   Updated: 2024/05/22 09:49:25 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_cub3d(t_data *data, char *map)
{
	(void)map;
	data->mlx_ptr = mlx_init();
	ft_protect_malloc(data->mlx_ptr);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	ft_protect_malloc(data->win_ptr);
	
	ft_init_map(data);
	ft_render_map(data);
	data->img = ft_new_img(data, CUBE_SIZE, CUBE_SIZE, 100, 100);
	ft_put_image_to_window(data, data->img, CUBE_COLOR);

	mlx_hook(data->win_ptr, 2, 1L<<0, ft_key_press, data);
	mlx_hook(data->win_ptr, 3, 1L<<1, ft_key_release, data);
	mlx_loop_hook(data->mlx_ptr, ft_update, data);
	mlx_loop(data->mlx_ptr);
}
