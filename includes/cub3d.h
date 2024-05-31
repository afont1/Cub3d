/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:19:52 by afont             #+#    #+#             */
/*   Updated: 2024/05/31 14:48:05 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "define.h"
# include "../sources/GNL/get_next_line.h"

typedef struct s_data		t_data;
typedef struct s_img		t_img;
typedef struct s_pos		t_pos;
typedef struct s_map		t_map;
typedef struct s_ray_data	t_ray_data;
typedef struct s_coord		t_coord;
typedef struct s_player		t_player;

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
	t_img	img;
};

struct	s_ray_data
{
	float	line_height;
	int		is_vertical;
};

struct	s_player
{
	int		color;
	int		radius;
	double	angle;
	double	angle_step;
	t_pos	pos;
};

struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			keys[256];
	double		player_angle;
	t_player	player;
	t_map		map;
	t_ray_data	*ray_data;
};

/*	main	*/
void	ft_cub3d(t_data *data, char *argv);

/*	utils	*/
void	ft_protect_malloc(void *ptr);
int		is_wall(t_data *data, double x, double y);
double	ft_dist(double ax, double ay, double bx, double by);
int		ft_get_map_height(char *argv);
double	ft_angle_loop(double angle);

/*	display	*/
void	ft_pixel_put(t_img img, int x, int y, int color);
void	ft_draw_map(t_data *data);
void	ft_draw_circle(t_data *data, int x0, int y0, int color);
int		check_circle_collision(t_data *data, int x0, int y0, int radius);

/*	hook	*/
int		ft_key_press(int key, t_data *data);
int		ft_key_release(int key, t_data *data);
int		ft_update(t_data *data);
void	ft_move_player(t_data *data, double angle);

/*	init	*/
void	ft_init_data(t_data *data);
void	ft_init_map_img(t_data *data, char *argv);
void	ft_init_map_data(t_data *data, char *argv);
void	ft_init_player(t_data *data);

/*	free	*/
void	ft_close_window(t_data *data);
void	ft_destroy_img(t_data *data);

/*	ray	*/
void	ft_ray(t_data *data);
void	ft_draw_line(t_data *data, double ray_angle, double dist_t);
double	fish_eye_correction(t_data *data, double ray_angle, double dist_t);
double	ft_horizontal_ray(t_data *data, double ray_angle);
double	ft_vertical_ray(t_data *data, double ray_angle);

/*	wall	*/
void	ft_init_wall(t_data *data, double dist, int nbr_ray, int is_vertical);
void	ft_draw_wall(t_data *data);

#endif