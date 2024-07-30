/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:10:35 by afont             #+#    #+#             */
/*   Updated: 2024/07/04 12:41:12 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->all_img.env_img.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.west_wall.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.north_wall.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.east_wall.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.south_wall.img_ptr);
}

int	ft_close_window(t_data *data)
{
	int	i;

	ft_destroy_img(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->all_img.north_wall.path);
	free(data->all_img.south_wall.path);
	free(data->all_img.west_wall.path);
	free(data->all_img.east_wall.path);
	i = -1;
	while (++i < data->map.height)
		free(data->map.tab_map[i]);
	free(data->map.tab_map);
	free(data);
	exit(0);
	return (0);
}
