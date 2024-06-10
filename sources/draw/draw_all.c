/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:02:03 by afont             #+#    #+#             */
/*   Updated: 2024/06/10 10:10:08 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_all(t_data *data)
{
	ft_ray(data);
	mlx_destroy_image(data->mlx_ptr, data->map.img.img_ptr);
	ft_draw_map(data);
}
