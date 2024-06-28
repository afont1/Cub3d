/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:35:59 by afont             #+#    #+#             */
/*   Updated: 2024/06/27 16:40:07 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_display_fps4(t_data *data, char *fps)
{
	if (fps[0] == '5')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.five.img_ptr, 6, 6);
	else if (fps[0] == '6')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.six.img_ptr, 6, 6);
	else if (fps[0] == '7')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.seven.img_ptr, 6, 6);
	else if (fps[0] == '8')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.eight.img_ptr, 6, 6);
	else if (fps[0] == '9')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.nine.img_ptr, 6, 6);
}

void	ft_display_fps5(t_data *data, char *fps)
{
	if (fps[1] == '5')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.five.img_ptr, 22, 6);
	else if (fps[1] == '6')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.six.img_ptr, 22, 6);
	else if (fps[1] == '7')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.seven.img_ptr, 22, 6);
	else if (fps[1] == '8')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.eight.img_ptr, 22, 6);
	else if (fps[1] == '9')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.nine.img_ptr, 22, 6);
}

void	ft_display_fps6(t_data *data, char *fps)
{
	if (fps[2] == '5')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.five.img_ptr, 38, 6);
	else if (fps[2] == '6')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.six.img_ptr, 38, 6);
	else if (fps[2] == '7')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.seven.img_ptr, 38, 6);
	else if (fps[2] == '8')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.eight.img_ptr, 38, 6);
	else if (fps[2] == '9')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->all_img.nine.img_ptr, 38, 6);
}
