/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:30:22 by afont             #+#    #+#             */
/*   Updated: 2024/07/04 10:16:58 by afont            ###   ########.fr       */
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
typedef struct s_slope		t_slope;
typedef struct s_ray_coord	t_ray_coord;
typedef struct s_animation	t_animation;

struct	s_slope
{
	float		s1;
	float		s2;
	float		s3;
};

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
	char		*path;
};

struct	s_map
{
	char	**tab_map;
	int		width;
	int		height;
	int		cen_map;
	int		size;
	t_img	img;
};

struct	s_ray_data
{
	int		is_vertical;
	int		carac;
	double	rx;
	double	ry;
	double	ray_angle;
	float	line_height;
	float	ty_step;
	float	ty_offset;
	float	dist;
};

struct	s_player
{
	int		color;
	int		radius;
	int		fov;
	int		speed;
	float	fov_factor;
	double	sneak;
	double	angle;
	double	angle_step;
	double	delta_time;
	double	planeX;
	double	planeY;
	double	dirX;
	double	dirY;
	t_pos	pos;
};

struct	s_animation
{
	int		sprite;
	int		coord_x;
};

struct	s_all_img
{
	int		floor_color;
	int		ceiling_color;
	t_img	west_wall;
	t_img	east_wall;
	t_img	north_wall;
	t_img	south_wall;
	t_img	door;
	t_img	door_open;
	t_img	floor;

	t_img		weapon[5];
	t_animation	weapon_anim[4];
	
	t_img	*side_ptr;
	t_img	env_img;
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

struct	s_ray_coord
{
	float	vx;
	float	vy;
	float	hx;
	float	hy;
	int		carac_v;
	int		carac_h;
};

struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			keys[256];
	t_ray_coord	ray_coord;
	t_player	player;
	t_map		map;
	t_ray_data	*ray_data;
	t_all_img	all_img;
};

#endif