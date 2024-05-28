/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:10:35 by afont             #+#    #+#             */
/*   Updated: 2024/05/28 08:19:02 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.img.img_ptr);
}

void	ft_close_window(t_data *data)
{
	int	i;

	i = -1;
	while (data->map.tab_map[++i])
		free(data->map.tab_map[i]);
	free(data->map.tab_map);
	ft_destroy_img(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}