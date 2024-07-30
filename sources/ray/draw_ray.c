/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:48:20 by afont             #+#    #+#             */
/*   Updated: 2024/07/05 12:22:31 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_ray(t_data *data)
{
	float	ray_dir_x0;
	float	ray_dir_y0;
	float	ray_dir_x1;
	float	ray_dir_y1;
	float	player_z;
	float	row_distance;
	float	floor_step_x;
	float	floor_step_y;
	float	floor_x;
	float	floor_y;

	int		y;
	int		x;
	int		p;
	int		texture_x;
	int		texture_y;
	int		color;

	y = WIN_HEIGHT / 2;
	while (++y < WIN_HEIGHT)
	{
		ray_dir_x0 = data->player.dir_x - data->player.plane_x;
		ray_dir_y0 = data->player.dir_y - data->player.plane_y;
		ray_dir_x1 = data->player.dir_x + data->player.plane_x;
		ray_dir_y1 = data->player.dir_y + data->player.plane_y;
		
		p = y - WIN_HEIGHT / 2;
		player_z = 0.5 * WIN_HEIGHT;

		row_distance = player_z / p;
		floor_step_x = row_distance * (ray_dir_x1 - ray_dir_x0) / WIN_WIDTH;
		floor_step_y = row_distance * (ray_dir_y1 - ray_dir_y0) / WIN_WIDTH;

		floor_x = data->player.x + row_distance * ray_dir_x0;
		floor_y = data->player.y + row_distance * ray_dir_y0;
		
		x = -1;
		while (++x < WIN_WIDTH)
		{
			texture_x = (int)(JSP * (floor_x - (int)floor_x)) & (JSP - 1);
			texture_y = (int)(JSP * (floor_y - (int)floor_y)) & (JSP - 1);

			floor_x += floor_step_x;
			floor_y += floor_step_y;
			color = ft_get_color(&data->all_img.floor, texture_x, texture_y);
			ft_pixel_put(data->all_img.env_img, x, y, color);
			color = ft_get_color(&data->all_img.ceiling, texture_x, texture_y);
			ft_pixel_put(data->all_img.env_img, x, WIN_HEIGHT - y, color);
		}
	}


		
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	step;
	double	tex_pos;

	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	
	x = -1;
	while (++x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_dir_x = data->player.dir_x + data->player.plane_x * camera_x;
		ray_dir_y = data->player.dir_y + data->player.plane_y * camera_x;

		map_x = (int)data->player.x;
		map_y = (int)data->player.y;

		delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
		delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);


		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->player.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - data->player.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->player.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - data->player.y) * delta_dist_y;
		}
		
		hit = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (ft_collision(data, map_x, map_y))
				hit = 1;
		}
		if (side == 0)
		{
			perp_wall_dist = (side_dist_x - delta_dist_x);
			if (step_x > 0)
			{
				
				if ((map_x > 0 && data->map.tab_map[map_x - 1][map_y] == '3'))
					data->all_img.side_ptr = &data->all_img.door_open;
				else
					data->all_img.side_ptr = &data->all_img.south_wall;
			}
			else
			{
				if ((map_x < data->map.width && data->map.tab_map[map_x + 1][map_y] == '3'))
					data->all_img.side_ptr = &data->all_img.door_open;
				else
					data->all_img.side_ptr = &data->all_img.north_wall;
			}
		}
		else
		{
			perp_wall_dist = (side_dist_y - delta_dist_y);
			if (step_y > 0)
			{
				if ((map_y > 0 && data->map.tab_map[map_x][map_y - 1] == '3'))
					data->all_img.side_ptr = &data->all_img.door_open;
				else
					data->all_img.side_ptr = &data->all_img.west_wall;
			}
			else
			{
				if ((map_y < data->map.height && data->map.tab_map[map_x][map_y + 1] == '3'))
					data->all_img.side_ptr = &data->all_img.door_open;
				else
					data->all_img.side_ptr = &data->all_img.east_wall;
			}
		}
		line_height = (int)(WIN_HEIGHT / perp_wall_dist);
		draw_start = -line_height / 2 + WIN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + WIN_HEIGHT / 2;
		if (draw_end >= WIN_HEIGHT)
			draw_end = WIN_HEIGHT - 1;
		if (side == 0)
			wall_x = data->player.y + perp_wall_dist * ray_dir_y;
		else
			wall_x = data->player.x + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * (double)JSP);
		if (side == 0 && ray_dir_x > 0)
			tex_x = JSP - tex_x - 1;
		if (side == 1 && ray_dir_y < 0)
			tex_x = JSP - tex_x - 1;
		step = 1.0 * JSP / line_height;
		tex_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;
		y = draw_start - 1;
		while (++y < draw_end)
		{
			tex_y = (int)tex_pos & (JSP - 1);
			tex_pos += step;
			color = ft_check_color(data, map_x, map_y, tex_x, tex_y);
			ft_pixel_put(data->all_img.env_img, x, y, color);
		}
	}
}