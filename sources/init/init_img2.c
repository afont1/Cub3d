/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:59:50 by bloisel           #+#    #+#             */
/*   Updated: 2024/08/01 03:04:14 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	for_ft_img5(t_data *data)
{
	data->all_img.weapon[3].addr = mlx_get_data_addr
		(data->all_img.weapon[3].img_ptr,
			&data->all_img.weapon[3].bits_per_pixel,
			&data->all_img.weapon[3].line_length,
			&data->all_img.weapon[3].endian);
	data->all_img.weapon[4].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/weapon/knife5.xpm",
			&data->all_img.weapon[4].width,
			&data->all_img.weapon[4].height);
	ft_protect_img(data->all_img.weapon[4].img_ptr);
	data->all_img.weapon[4].addr = mlx_get_data_addr
		(data->all_img.weapon[4].img_ptr,
			&data->all_img.weapon[4].bits_per_pixel,
			&data->all_img.weapon[4].line_length,
			&data->all_img.weapon[4].endian);
	data->all_img.deco1.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/deco/deco1.xpm",
			&data->all_img.deco1.width,
			&data->all_img.deco1.height);
	ft_protect_img(data->all_img.deco1.img_ptr);
}

void	for_ft_img4(t_data *data)
{
	data->all_img.weapon[1].addr = mlx_get_data_addr
		(data->all_img.weapon[1].img_ptr,
			&data->all_img.weapon[1].bits_per_pixel,
			&data->all_img.weapon[1].line_length,
			&data->all_img.weapon[1].endian);
	data->all_img.weapon[2].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/weapon/knife3.xpm",
			&data->all_img.weapon[2].width,
			&data->all_img.weapon[2].height);
	ft_protect_img(data->all_img.weapon[2].img_ptr);
	data->all_img.weapon[2].addr = mlx_get_data_addr
		(data->all_img.weapon[2].img_ptr,
			&data->all_img.weapon[2].bits_per_pixel,
			&data->all_img.weapon[2].line_length,
			&data->all_img.weapon[2].endian);
	data->all_img.weapon[3].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/weapon/knife4.xpm",
			&data->all_img.weapon[3].width,
			&data->all_img.weapon[3].height);
	ft_protect_img(data->all_img.weapon[3].img_ptr);
}

void	for_ft_img3(t_data *data)
{
	ft_protect_img(data->all_img.south_wall.img_ptr);
	data->all_img.ceiling.addr = mlx_get_data_addr
		(data->all_img.ceiling.img_ptr,
			&data->all_img.ceiling.bits_per_pixel,
			&data->all_img.ceiling.line_length,
			&data->all_img.ceiling.endian);
	data->all_img.weapon[0].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/weapon/knife1.xpm",
			&data->all_img.weapon[0].width,
			&data->all_img.weapon[0].height);
	ft_protect_img(data->all_img.weapon[0].img_ptr);
	data->all_img.weapon[0].addr = mlx_get_data_addr
		(data->all_img.weapon[0].img_ptr,
			&data->all_img.weapon[0].bits_per_pixel,
			&data->all_img.weapon[0].line_length,
			&data->all_img.weapon[0].endian);
	data->all_img.weapon[1].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/weapon/knife2.xpm",
			&data->all_img.weapon[1].width,
			&data->all_img.weapon[1].height);
	ft_protect_img(data->all_img.weapon[1].img_ptr);
}

void	for_ft_img2(t_data *data)
{
	data->all_img.door_open.addr = mlx_get_data_addr
		(data->all_img.door_open.img_ptr,
			&data->all_img.door_open.bits_per_pixel,
			&data->all_img.door_open.line_length,
			&data->all_img.door_open.endian);
	data->all_img.floor.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/floor/wall1.xpm",
			&data->all_img.floor.width,
			&data->all_img.floor.height);
	ft_protect_img(data->all_img.floor.img_ptr);
	data->all_img.floor.addr = mlx_get_data_addr
		(data->all_img.floor.img_ptr,
			&data->all_img.floor.bits_per_pixel,
			&data->all_img.floor.line_length,
			&data->all_img.floor.endian);
	data->all_img.ceiling.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/ceiling/ceiling.xpm",
			&data->all_img.ceiling.width,
			&data->all_img.ceiling.height);
	ft_protect_img(data->all_img.ceiling.img_ptr);
}

void	for_ft_img(t_data *data)
{
	data->all_img.south_wall.addr = mlx_get_data_addr
		(data->all_img.south_wall.img_ptr,
			&data->all_img.south_wall.bits_per_pixel,
			&data->all_img.south_wall.line_length,
			&data->all_img.south_wall.endian);
	data->all_img.door.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/door/door.xpm", &data->all_img.door.width,
			&data->all_img.door.height);
	ft_protect_img(data->all_img.door.img_ptr);
	data->all_img.door.addr = mlx_get_data_addr(data->all_img.door.img_ptr,
			&data->all_img.door.bits_per_pixel,
			&data->all_img.door.line_length,
			&data->all_img.door.endian);
	data->all_img.door_open.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/door/door_open2.xpm",
			&data->all_img.door_open.width,
			&data->all_img.door_open.height);
	ft_protect_img(data->all_img.door_open.img_ptr);
}
