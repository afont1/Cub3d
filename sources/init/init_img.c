/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:08:22 by afont             #+#    #+#             */
/*   Updated: 2024/07/03 09:31:01 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_img4(t_data *data)
{
	data->all_img.east_wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->all_img.east_wall.path, &data->all_img.east_wall.width, &data->\
	all_img.east_wall.height);
	ft_protect_img(data->all_img.east_wall.img_ptr);
	data->all_img.east_wall.addr = mlx_get_data_addr(data->all_img.east_wall.\
	img_ptr, &data->all_img.east_wall.bits_per_pixel, &data->all_img.\
	east_wall.line_length, &data->all_img.east_wall.endian);
	data->all_img.south_wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->all_img.south_wall.path, &data->all_img.south_wall.width, &data->\
	all_img.south_wall.height);
	ft_protect_img(data->all_img.south_wall.img_ptr);
	data->all_img.south_wall.addr = mlx_get_data_addr(data->all_img.\
	south_wall.img_ptr, &data->all_img.south_wall.bits_per_pixel, \
	&data->all_img.south_wall.line_length, &data->all_img.south_wall.endian);

	data->all_img.door.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/door/door.xpm", &data->all_img.door.width, &data->all_img.door.height);
	ft_protect_img(data->all_img.door.img_ptr);
	data->all_img.door.addr = mlx_get_data_addr(data->all_img.door.img_ptr, &data->all_img.door.bits_per_pixel, &data->all_img.door.line_length, &data->all_img.door.endian);

	data->all_img.door_open.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/door/door_open2.xpm", &data->all_img.door_open.width, &data->all_img.door_open.height);
	ft_protect_img(data->all_img.door_open.img_ptr);
	data->all_img.door_open.addr = mlx_get_data_addr(data->all_img.door_open.img_ptr, &data->all_img.door_open.bits_per_pixel, &data->all_img.door_open.line_length, &data->all_img.door_open.endian);

	data->all_img.floor.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/floor/purplestone.xpm", &data->all_img.floor.width, &data->all_img.floor.height);
	ft_protect_img(data->all_img.floor.img_ptr);
	data->all_img.floor.addr = mlx_get_data_addr(data->all_img.floor.img_ptr, &data->all_img.floor.bits_per_pixel, &data->all_img.floor.line_length, &data->all_img.floor.endian);

	data->all_img.weapon[0].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/weapon/knife1.xpm", &data->all_img.weapon[0].width, &data->all_img.weapon[0].height);
	ft_protect_img(data->all_img.weapon[0].img_ptr);
	data->all_img.weapon[0].addr = mlx_get_data_addr(data->all_img.weapon[0].img_ptr, &data->all_img.weapon[0].bits_per_pixel, &data->all_img.weapon[0].line_length, &data->all_img.weapon[0].endian);

	data->all_img.weapon[1].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/weapon/knife2.xpm", &data->all_img.weapon[1].width, &data->all_img.weapon[1].height);
	ft_protect_img(data->all_img.weapon[1].img_ptr);
	data->all_img.weapon[1].addr = mlx_get_data_addr(data->all_img.weapon[1].img_ptr, &data->all_img.weapon[1].bits_per_pixel, &data->all_img.weapon[1].line_length, &data->all_img.weapon[1].endian);

	data->all_img.weapon[2].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/weapon/knife3.xpm", &data->all_img.weapon[2].width, &data->all_img.weapon[2].height);
	ft_protect_img(data->all_img.weapon[2].img_ptr);
	data->all_img.weapon[2].addr = mlx_get_data_addr(data->all_img.weapon[2].img_ptr, &data->all_img.weapon[2].bits_per_pixel, &data->all_img.weapon[2].line_length, &data->all_img.weapon[2].endian);

	data->all_img.weapon[3].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/weapon/knife4.xpm", &data->all_img.weapon[3].width, &data->all_img.weapon[3].height);
	ft_protect_img(data->all_img.weapon[3].img_ptr);
	data->all_img.weapon[3].addr = mlx_get_data_addr(data->all_img.weapon[3].img_ptr, &data->all_img.weapon[3].bits_per_pixel, &data->all_img.weapon[3].line_length, &data->all_img.weapon[3].endian);

	data->all_img.weapon[4].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/weapon/knife5.xpm", &data->all_img.weapon[4].width, &data->all_img.weapon[4].height);
	ft_protect_img(data->all_img.weapon[4].img_ptr);
	data->all_img.weapon[4].addr = mlx_get_data_addr(data->all_img.weapon[4].img_ptr, &data->all_img.weapon[4].bits_per_pixel, &data->all_img.weapon[4].line_length, &data->all_img.weapon[4].endian);
}

void	ft_init_img3(t_data *data)
{
	data->all_img.west_wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->all_img.west_wall.path, &data->all_img.west_wall.width, \
	&data->all_img.west_wall.height);
	ft_protect_img(data->all_img.west_wall.img_ptr);
	data->all_img.west_wall.addr = mlx_get_data_addr(data->all_img.west_wall.\
	img_ptr, &data->all_img.west_wall.bits_per_pixel, &data->all_img.\
	west_wall.line_length, &data->all_img.west_wall.endian);
	data->all_img.north_wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	data->all_img.north_wall.path, &data->all_img.north_wall.width, &data->\
	all_img.north_wall.height);
	ft_protect_img(data->all_img.north_wall.img_ptr);
	data->all_img.north_wall.addr = mlx_get_data_addr(data->all_img.\
	north_wall.img_ptr, &data->all_img.north_wall.bits_per_pixel, \
	&data->all_img.north_wall.line_length, &data->all_img.north_wall.endian);
	data->all_img.four.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/digit/four.xpm", &data->all_img.four.width, &data->all_img.\
	four.height);
	ft_protect_img(data->all_img.four.img_ptr);
	ft_init_img4(data);
}

void	ft_init_img2(t_data *data)
{
	data->all_img.five.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/digit/five.xpm", &data->all_img.five.width, &data->all_img.\
	five.height);
	ft_protect_img(data->all_img.five.img_ptr);
	data->all_img.six.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/digit/six.xpm", &data->all_img.six.width, &data->all_img.\
	six.height);
	ft_protect_img(data->all_img.six.img_ptr);
	data->all_img.seven.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/digit/seven.xpm", &data->all_img.seven.width, &data->all_img.\
	seven.height);
	ft_protect_img(data->all_img.seven.img_ptr);
	data->all_img.eight.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/digit/eight.xpm", &data->all_img.eight.width, &data->all_img.\
	eight.height);
	ft_protect_img(data->all_img.eight.img_ptr);
	data->all_img.nine.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/digit/nine.xpm", &data->all_img.nine.width, &data->all_img.\
	nine.height);
	ft_protect_img(data->all_img.nine.img_ptr);
	data->all_img.zero.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/digit/zero.xpm", &data->all_img.zero.width, &data->all_img.\
	zero.height);
	ft_protect_img(data->all_img.zero.img_ptr);
	ft_init_img3(data);
}

void	ft_init_img(t_data *data)
{
	data->all_img.env_img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT);
	data->all_img.env_img.addr = mlx_get_data_addr(data->all_img.env_img.\
	img_ptr, &data->all_img.env_img.bits_per_pixel, &data->all_img.env_img.\
	line_length, &data->all_img.env_img.endian);
	data->map.img.img_ptr = mlx_new_image(data->mlx_ptr, data->map.size, \
	data->map.size);
	data->map.img.addr = mlx_get_data_addr(data->map.img.img_ptr, &data->map.\
	img.bits_per_pixel, &data->map.img.line_length, &data->map.img.endian);
	data->map.img.width = data->map.size;
	data->map.img.height = data->map.size;
	data->all_img.one.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/digit/one.xpm", &data->all_img.one.width, &data->all_img.\
	one.height);
	ft_protect_img(data->all_img.one.img_ptr);
	data->all_img.two.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/digit/two.xpm", &data->all_img.two.width, &data->all_img.\
	two.height);
	ft_protect_img(data->all_img.two.img_ptr);
	data->all_img.three.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/digit/three.xpm", &data->all_img.three.width, &data->all_img.\
	three.height);
	ft_protect_img(data->all_img.three.img_ptr);
	ft_init_img2(data);
}
