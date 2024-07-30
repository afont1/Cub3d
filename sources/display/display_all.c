/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:22:31 by afont             #+#    #+#             */
/*   Updated: 2024/07/04 12:22:38 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_display_all(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.env_img.img_ptr, 0, 0);
}