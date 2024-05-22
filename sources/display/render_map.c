/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:39 by afont             #+#    #+#             */
/*   Updated: 2024/05/22 09:37:00 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_render_map(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map.img_ptr, 0, 0);
}