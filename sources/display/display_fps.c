/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:07:05 by afont             #+#    #+#             */
/*   Updated: 2024/06/18 10:59:48 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	ft_display_fps(t_data *data, char *fps)
{
	if (ft_strlen(fps) >= 1)
	{
		if (fps[0] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.zero.img_ptr, 6, 6);
		else if (fps[0] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.one.img_ptr, 6, 6);
		else if (fps[0] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.two.img_ptr, 6, 6);
		else if (fps[0] == '3')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.three.img_ptr, 6, 6);
		else if (fps[0] == '4')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.four.img_ptr, 6, 6);
		else if (fps[0] == '5')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.five.img_ptr, 6, 6);
		else if (fps[0] == '6')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.six.img_ptr, 6, 6);
		else if (fps[0] == '7')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.seven.img_ptr, 6, 6);
		else if (fps[0] == '8')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.eight.img_ptr, 6, 6);
		else if (fps[0] == '9')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.nine.img_ptr, 6, 6);
	}

	if (ft_strlen(fps) >= 2)
	{
		if (fps[1] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.zero.img_ptr, 22, 6);
		else if (fps[1] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.one.img_ptr, 22, 6);
		else if (fps[1] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.two.img_ptr, 22, 6);
		else if (fps[1] == '3')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.three.img_ptr, 22, 6);
		else if (fps[1] == '4')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.four.img_ptr, 22, 6);
		else if (fps[1] == '5')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.five.img_ptr, 22, 6);
		else if (fps[1] == '6')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.six.img_ptr, 22, 6);
		else if (fps[1] == '7')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.seven.img_ptr, 22, 6);
		else if (fps[1] == '8')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.eight.img_ptr, 22, 6);
		else if (fps[1] == '9')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.nine.img_ptr, 22, 6);
	}
	
	if (ft_strlen(fps) >= 3)
	{
		if (fps[2] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.zero.img_ptr, 38, 6);
		else if (fps[2] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.one.img_ptr, 38, 6);
		else if (fps[2] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.two.img_ptr, 38, 6);
		else if (fps[2] == '3')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.three.img_ptr, 38, 6);
		else if (fps[2] == '4')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.four.img_ptr, 38, 6);
		else if (fps[2] == '5')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.five.img_ptr, 38, 6);
		else if (fps[2] == '6')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.six.img_ptr, 38, 6);
		else if (fps[2] == '7')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.seven.img_ptr, 38, 6);
		else if (fps[2] == '8')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.eight.img_ptr, 38, 6);
		else if (fps[2] == '9')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.nine.img_ptr, 38, 6);
	}
	free(fps);
}
