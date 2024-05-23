/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:32:42 by afont             #+#    #+#             */
/*   Updated: 2024/05/23 08:43:16 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_cube(t_data *data, double angle)
{
	int	x_mv;
	int	y_mv;

	x_mv = 5 * cos(angle);
	y_mv = 5 * sin(angle);
	// ft_del_img(data);
	ft_draw_map(data);
	if (!is_wall(data, data->img.pos.x + x_mv, data->img.pos.y) &&
    	!is_wall(data, data->img.pos.x + x_mv + CUBE_SIZE, data->img.pos.y) &&
    	!is_wall(data, data->img.pos.x + x_mv, data->img.pos.y + CUBE_SIZE) &&
    	!is_wall(data, data->img.pos.x + x_mv + CUBE_SIZE, data->img.pos.y + CUBE_SIZE))
    	data->img.pos.x += x_mv;
	if (!is_wall(data, data->img.pos.x, data->img.pos.y + y_mv) &&
		!is_wall(data, data->img.pos.x + CUBE_SIZE, data->img.pos.y + y_mv) &&
		!is_wall(data, data->img.pos.x, data->img.pos.y + y_mv + CUBE_SIZE) &&
		!is_wall(data, data->img.pos.x + CUBE_SIZE, data->img.pos.y + y_mv + CUBE_SIZE))
		data->img.pos.y += y_mv;
	ft_put_image_to_window(data, data->img, CUBE_COLOR);
}

void	ft_draw_direction_line(t_data *data, int length, int color)
{
	int	start_x = data->img.pos.x + CUBE_SIZE / 2;
	int start_y = data->img.pos.y + CUBE_SIZE / 2;
	int end_x = start_x + length * cos(data->player_angle);
	int end_y = start_y + length * sin(data->player_angle);
	int err = (abs(end_x - start_x) > abs(end_y - start_y) ? abs(end_x - start_x) : -abs(end_y - start_y)) / 2;

	ft_draw_map(data);
	ft_put_image_to_window(data, data->img, CUBE_COLOR);
	while (start_x != end_x || start_y != end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start_x, start_y, color);
		if (err > -abs(end_x - start_x))
		{
			err -= abs(end_y - start_y);
			start_x += start_x < end_x ? 1 : -1;
		}
		if (err < abs(end_y - start_y))
		{
			err += abs(end_x - start_x);
			start_y += start_y < end_y ? 1 : -1;
		}
	}
}
