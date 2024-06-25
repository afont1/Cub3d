/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:27:10 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 15:36:23 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_display_fov(t_data *data)
{
	char	*fov;
	
	fov = ft_itoa(data->player.fov);
	if (ft_strlen(fov) >= 1)
	{
		if (fov[0] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.zero.img_ptr, 6, 22);
		else if (fov[0] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.one.img_ptr, 6, 22);
		else if (fov[0] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.two.img_ptr, 6, 22);
		else if (fov[0] == '3')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.three.img_ptr, 6, 22);
		else if (fov[0] == '4')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.four.img_ptr, 6, 22);
		else if (fov[0] == '5')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.five.img_ptr, 6, 22);
		else if (fov[0] == '6')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.six.img_ptr, 6, 22);
		else if (fov[0] == '7')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.seven.img_ptr, 6, 22);
		else if (fov[0] == '8')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.eight.img_ptr, 6, 22);
		else if (fov[0] == '9')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.nine.img_ptr, 6, 22);
	}
	
	if (ft_strlen(fov) >= 2)
	{
		if (fov[1] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.zero.img_ptr, 22, 22);
		else if (fov[1] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.one.img_ptr, 22, 22);
		else if (fov[1] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.two.img_ptr, 22, 22);
		else if (fov[1] == '3')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.three.img_ptr, 22, 22);
		else if (fov[1] == '4')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.four.img_ptr, 22, 22);
		else if (fov[1] == '5')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.five.img_ptr, 22, 22);
		else if (fov[1] == '6')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.six.img_ptr, 22, 22);
		else if (fov[1] == '7')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.seven.img_ptr, 22, 22);
		else if (fov[1] == '8')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.eight.img_ptr, 22, 22);
		else if (fov[1] == '9')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.nine.img_ptr, 22, 22);
	}

	if (ft_strlen(fov) >= 3)
	{
		if (fov[1] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.zero.img_ptr, 38, 22);
		else if (fov[1] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.one.img_ptr, 38, 22);
		else if (fov[1] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.two.img_ptr, 38, 22);
		else if (fov[1] == '3')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.three.img_ptr, 38, 22);
		else if (fov[1] == '4')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.four.img_ptr, 38, 22);
		else if (fov[1] == '5')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.five.img_ptr, 38, 22);
		else if (fov[1] == '6')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.six.img_ptr, 38, 22);
		else if (fov[1] == '7')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.seven.img_ptr, 38, 22);
		else if (fov[1] == '8')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.eight.img_ptr, 38, 22);
		else if (fov[1] == '9')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.nine.img_ptr, 38, 22);
	}
	free(fov);
}

void	ft_fov(t_data *data)
{
	if (data->keys[113] && data->player.fov < 158)
	{
		data->player.fov += 2;
		data->player.fov_factor = JSP * (float)(FOV_BASE) / (float)(data->player.fov);
	}
	if (data->keys[101] && data->player.fov > 2)
	{
		data->player.fov -= 2;
		data->player.fov_factor = JSP * (float)(FOV_BASE) / (float)(data->player.fov);
	}
}