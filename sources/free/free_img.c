/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:10:35 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 12:12:32 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->map.img.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.wall_img.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.one.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.two.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.three.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.four.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.five.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.six.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.seven.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.eight.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.nine.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.zero.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.red_wall.img_ptr);
}

void	ft_close_window(t_data *data)
{
	int	i;

	free(data->ray_data);
	ft_destroy_img(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	i = -1;
	while (++i < data->map.height)
		free(data->map.tab_map[i]);
	free(data->map.tab_map);
	free(data);
	exit(0);
}
