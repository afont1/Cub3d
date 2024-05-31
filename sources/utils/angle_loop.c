/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:24:27 by afont             #+#    #+#             */
/*   Updated: 2024/05/30 10:26:16 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_angle_loop(double angle)
{
	if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}
