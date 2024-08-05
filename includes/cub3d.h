/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:19:52 by afont             #+#    #+#             */
/*   Updated: 2024/08/05 10:19:25 by afont            ###   ########.fr       */
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
void	ft_goto_line(int fd, int cpt);
int		is_wall(t_data *data, double x, double y);
int		ft_texture_is_init(t_data *data, char *line);
double	ft_dist(double ax, double ay, double bx, double by);
void	ft_check_tab_color(t_data *data, char **tab);
void	ft_check_file_name(char *av);
int		ft_get_map_height(t_data *data, char *argv, int cpt);
char	*fps_counter(t_data *data);
int		ft_get_map_width(t_data *data, char *argv, int cpt);
double	ft_angle_loop(double angle);
void	ft_fusion_img(t_img *dst, t_img *src, int x, int y);
double	ft_dist_ang(t_data *data, double player_angle, int *d, int flag);
int		ft_get_color(t_img *img, int x, int y);
void	ft_protect_img(void *img_ptr);
int		ft_empty_line(char *line);
int		ft_check_empty(int j, char *line);
void	ft_end_gnl(int fd);

/*	display	*/
void	ft_display_all(t_data *data);
void	ft_display_fps(t_data *data, char *fps);
void	ft_display_fps4(t_data *data, char *fps);
void	ft_display_fps5(t_data *data, char *fps);
void	ft_display_fps6(t_data *data, char *fps);

/*	hook	*/
int		ft_key_press(int key, t_data *data);
int		ft_key_release(int key, t_data *data);
int		ft_update(t_data *data);
void	ft_move_player(t_data *data, double angle);

/*	init	*/
void	ft_init_data(t_data *data);
int		ft_init_texture(t_data *data, char *argv);
void	ft_init_map_data(t_data *data, char *argv, int cpt);
void	ft_check_texture(t_data *data);
void	ft_init_player(t_data *data);
void	ft_init_img(t_data *data);
void	ft_check_map(t_data *data, char **map);

/*	free	*/
int		ft_close_window(t_data *data);
void	ft_destroy_img(t_data *data);
void	ft_exit_map(t_data *data, char *str);
void	ft_exit_before(t_data *data, char *str);

/*	ray	*/
void	ft_ray(t_data *data);
double	fish_eye(t_data *data, double ray_angle, double dist_t);
double	ft_horizontal_ray(t_data *data, double ray_angle);
double	ft_vertical_ray(t_data *data, double ray_angle);
void	ft_horizontal_var(t_data *data, t_coord *ray_coord, \
t_coord *offset, double ray_angle);
void	ft_vertical_var(t_data *data, t_coord *ray_coord, \
t_coord *offset, double ray_angle);

/*	draw	*/
void	ft_draw_map(t_data *data);
void	ft_pixel_put(t_img img, int x, int y, int color);
void	ft_draw_roof(t_data *data, t_img *img, int k, double offset);
void	ft_init_wall(t_data *data, double dist, int nbr_ray, int is_vertical);
void	ft_draw_circle(t_data *data, int x0, int y0, int color);
void	ft_draw_environement(t_data *data, t_img *env_img, int k, \
double offset);
void	ft_draw_all(t_data *data);
int		ft_draw_wall(t_data *data, t_img *img, int k, double offset);
void	ft_draw_floor(t_data *data, t_img *img, int k, int i);
void	ft_sort_dist(t_data *data, t_coord dist, double ray_angle, int nbr_ray);

/*	fov	*/
void	ft_var_pos(t_data *data, t_pos *pos, double a1);
void	ft_fov(t_data *data);
void	ft_draw_fov(t_data *data, t_img img);
void	swap(int *a, int *b);
void	ft_swap_pos(t_pos *pos1, t_pos *pos2, t_pos *pos3);
t_slope	ft_init_slope(t_pos pos1, t_pos pos2, t_pos pos3);
t_pos	ft_init_x_fov(t_slope slp, t_pos pos1, t_pos pos2, int y);

#endif