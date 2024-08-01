/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:45:52 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 00:12:25 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_all(t_data *data)
{
	ft_draw_ray(data);
	ft_draw_map(data);
	ft_fusion_img(&data->all_img.env_img, &data->map.img, 0, 0);
	ft_draw_weapon(data);
}
