/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:10:35 by afont             #+#    #+#             */
/*   Updated: 2024/08/06 20:53:21 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_destroy_img3(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->all_img.floor.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.ceiling.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.door.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.door_open.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.img.img_ptr);
}

void	ft_destroy_img2(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->all_img.zero.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.one.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.two.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.three.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.four.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.five.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.six.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.seven.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.eight.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.nine.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.weapon[0].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.weapon[1].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.weapon[2].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.weapon[3].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.weapon[4].img_ptr);
	ft_destroy_img3(data);
}

void	ft_destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->all_img.env_img.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.west_wall.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.north_wall.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.east_wall.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.south_wall.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->all_img.deco1.img_ptr);
	ft_destroy_img2(data);
}

int	ft_close_window(t_data *data)
{
	int	i;

	mlx_mouse_show(data->mlx_ptr, data->win_ptr);
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
	ft_fps_counter(data, 1);
	free(data);
	exit(0);
	return (0);
}
