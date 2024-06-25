/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:56:32 by afont             #+#    #+#             */
/*   Updated: 2024/06/24 13:25:31 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_display_all(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.wall_img.img_ptr, 0, 0);
	ft_display_fps(data, fps_counter(data));
	ft_display_fov(data);
}
