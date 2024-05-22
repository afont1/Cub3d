/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:25:27 by afont             #+#    #+#             */
/*   Updated: 2024/05/21 15:36:54 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_del_img(t_data *data)
{
	t_img	img_del;

	img_del = ft_new_img(data, data->img.width, data->img.height, data->img.pos.x, data->img.pos.y);
	ft_put_image_to_window(data, img_del, 0x00000000);
	mlx_destroy_image(data->mlx_ptr, img_del.img_ptr);
}
