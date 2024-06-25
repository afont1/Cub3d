/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:08:22 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 12:14:18 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_img(t_data *data)
{
	data->all_img.wall_img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->all_img.wall_img.addr = mlx_get_data_addr(data->all_img.wall_img.img_ptr, &data->all_img.wall_img.bits_per_pixel, &data->all_img.wall_img.line_length, &data->all_img.wall_img.endian);

	data->map.img.img_ptr = mlx_new_image(data->mlx_ptr, MAP_SIZE, MAP_SIZE);
	data->map.img.addr = mlx_get_data_addr(data->map.img.img_ptr, &data->map.img.bits_per_pixel, \
	&data->map.img.line_length, &data->map.img.endian);
	data->map.img.width = MAP_SIZE;
	data->map.img.height = MAP_SIZE;

	data->all_img.one.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/digit/one.xpm", &data->all_img.one.width, &data->all_img.one.height);
	ft_protect_img(data->all_img.one.img_ptr);
	data->all_img.two.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/digit/two.xpm", &data->all_img.two.width, &data->all_img.two.height);
	ft_protect_img(data->all_img.two.img_ptr);
	data->all_img.three.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/digit/three.xpm", &data->all_img.three.width, &data->all_img.three.height);
	ft_protect_img(data->all_img.three.img_ptr);
	data->all_img.four.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/digit/four.xpm", &data->all_img.four.width, &data->all_img.four.height);
	ft_protect_img(data->all_img.four.img_ptr);
	data->all_img.five.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/digit/five.xpm", &data->all_img.five.width, &data->all_img.five.height);
	ft_protect_img(data->all_img.five.img_ptr);
	data->all_img.six.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/digit/six.xpm", &data->all_img.six.width, &data->all_img.six.height);
	ft_protect_img(data->all_img.six.img_ptr);
	data->all_img.seven.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/digit/seven.xpm", &data->all_img.seven.width, &data->all_img.seven.height);
	ft_protect_img(data->all_img.seven.img_ptr);
	data->all_img.eight.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/digit/eight.xpm", &data->all_img.eight.width, &data->all_img.eight.height);
	ft_protect_img(data->all_img.eight.img_ptr);
	data->all_img.nine.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/digit/nine.xpm", &data->all_img.nine.width, &data->all_img.nine.height);
	ft_protect_img(data->all_img.nine.img_ptr);
	data->all_img.zero.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/digit/zero.xpm", &data->all_img.zero.width, &data->all_img.zero.height);
	ft_protect_img(data->all_img.zero.img_ptr);

	data->all_img.red_wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/wall/red.xpm", &data->all_img.red_wall.width, &data->all_img.red_wall.height);
	ft_protect_img(data->all_img.red_wall.img_ptr);
	data->all_img.red_wall.addr = mlx_get_data_addr(data->all_img.red_wall.img_ptr, &data->all_img.red_wall.bits_per_pixel, &data->all_img.red_wall.line_length, &data->all_img.red_wall.endian);

	// data->all_img.one.addr = mlx_get_data_addr(data->all_img.one.img_ptr, &data->all_img.one.bits_per_pixel, &data->all_img.one.line_length, &data->all_img.one.endian);
}
