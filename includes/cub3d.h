/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:19:52 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 10:10:24 by afont            ###   ########.fr       */
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
# include <sys/time.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../sources/GNL/get_next_line.h"
# include "define.h"
# include "struct.h"

/*	main	*/
void	ft_cub3d(t_data *data, char *argv);

/*	utils	*/
void	ft_protect_malloc(void *ptr);
int		is_wall(t_data *data, double x, double y);
double	ft_dist(double ax, double ay, double bx, double by);
int		ft_get_map_height(char *argv);
int		ft_get_map_width(char *argv);
double	ft_angle_loop(double angle);
void	ft_fusion_img(t_img *dst, t_img *src, int x, int y);
double	ft_dist_ang(t_data *data, double player_angle, int *d, int flag);
int		ft_get_color(t_img *img, int x, int y);

/*	display	*/
void	ft_display_all(t_data *data);

/*	hook	*/
int		ft_key_press(int key, t_data *data);
int		ft_key_release(int key, t_data *data);
int		ft_update(t_data *data);
void	ft_move_player(t_data *data, double angle);

/*	init	*/
void	ft_init_data(t_data *data);
void	ft_init_map_data(t_data *data, char *argv);
void	ft_init_player(t_data *data);

/*	free	*/
void	ft_close_window(t_data *data);
void	ft_destroy_img(t_data *data);

/*	ray	*/
void	ft_ray(t_data *data);
double	fish_eye(t_data *data, double ray_angle, double dist_t);
double	ft_horizontal_ray(t_data *data, double ray_angle, double *rx);
double	ft_vertical_ray(t_data *data, double ray_angle, double *ry);
int		ft_horizontal_var(t_data *data, t_coord *ray_coord, t_coord *offset, double ray_angle);
int		ft_vertical_var(t_data *data, t_coord *ray_coord, t_coord *offset, double ray_angle);

/*	draw	*/
void	ft_draw_map(t_data *data);
void	ft_pixel_put(t_img img, int x, int y, int color);
void	ft_init_wall(t_data *data, double dist, int nbr_ray, int is_vertical);
void	ft_draw_circle(t_data *data, int x0, int y0, int color);
void	ft_draw_wall(t_data *data, t_img *wall_img, int k, double offset);
void	ft_draw_all(t_data *data);

void	ft_draw_line_ray(t_data *data, double ray_angle, double dist_t);
void	ft_display_fps(t_data *data, char *fps);
void	ft_init_img(t_data *data);
void	ft_protect_img(void *img_ptr);
char	*fps_counter(t_data *data);
void	ft_fov(t_data *data);
void	ft_display_fov(t_data *data);
void	ft_draw_fov(t_data *data, t_img img);
void	ft_check_map(t_data *data);
void	ft_exit_map(t_data *data, char *str);
void	ft_exit_open(t_data *data, char *str);

#endif