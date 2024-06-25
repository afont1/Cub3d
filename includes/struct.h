/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:30:22 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 11:36:05 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data		t_data;
typedef struct s_img		t_img;
typedef struct s_pos		t_pos;
typedef struct s_map		t_map;
typedef struct s_ray_data	t_ray_data;
typedef struct s_coord		t_coord;
typedef struct s_player		t_player;
typedef struct s_all_img	t_all_img;

struct	s_pos
{
	int		x;
	int		y;
};

struct	s_coord
{
	double	x;
	double	y;
};

struct	s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	t_pos		pos;
};

struct	s_map
{
	char	**tab_map;
	int		width;
	int		height;
	t_img	img;
};

struct	s_ray_data
{
	int		is_vertical;
	double	rx;
	double	ry;
	double	ray_angle;
	float	line_height;
	float	ty_step;
	float	ty_offset;
};

struct	s_player
{
	int		color;
	int		radius;
	int		fov;
	float	fov_factor;
	double	angle;
	double	angle_step;
	t_pos	pos;
};

struct	s_all_img
{
	t_img	wall_img;
	t_img	red_wall;
	t_img	zero;
	t_img	one;
	t_img	two;
	t_img	three;
	t_img	four;
	t_img	five;
	t_img	six;
	t_img	seven;
	t_img	eight;
	t_img	nine;
};

struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			keys[256];
	double		player_angle;
	int			fps;
	float		vx, vy, hx, hy;
	t_player	player;
	t_map		map;
	t_ray_data	*ray_data;
	t_all_img	all_img;
};

#endif