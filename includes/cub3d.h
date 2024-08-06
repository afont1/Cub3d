/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:19:52 by afont             #+#    #+#             */
/*   Updated: 2024/08/06 21:43:10 by bloisel          ###   ########.fr       */
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

void	for_ft_img(t_data *data);
void	for_ft_img2(t_data *data);
void	for_ft_img3(t_data *data);
void	for_ft_img4(t_data *data);
void	for_ft_img5(t_data *data);
void	ft_init_data(t_data *data);
void	ft_check_file_name(char *av);
void	ft_protect_malloc(void *ptr);
void	ft_protect_img(void *img_ptr);
void	ft_draw_ray(t_data *data);
int		ft_init_texture(t_data *data, char *argv);
void	ft_check_texture(t_data *data);
void	ft_init_map_data(t_data *data, char *argv, int cpt);
void	ft_check_map(t_data *data, char **map);
void	ft_init_img(t_data *data);
void	ft_init_img2(t_data *data);
void	ft_init_img3(t_data *data);
void	ft_init_img4(t_data *data);
int		ft_key_press(int key, t_data *data);
int		ft_key_release(int key, t_data *data);
int		ft_update(t_data *data);
void	ft_pixel_put(t_img img, int x, int y, int color);
int		ft_get_color(t_img *img, int x, int y);
void	ft_init_player(t_data *data);
int		ft_get_map_height(t_data *data, char *argv, int cpt);
int		ft_get_map_width(t_data *data, char *argv, int cpt);
void	ft_goto_line(int fd, int cpt);
void	ft_exit_map(t_data *data, char *str);
void	ft_exit_before(t_data *data, char *str);
void	ft_check_tab_color(t_data *data, char **tab);
int		ft_texture_is_init(t_data *data, char *line);
void	ft_display_all(t_data *data);
void	ft_cub3d(t_data *data, char *argv);
int		ft_close_window(t_data *data);
void	ft_mouvement(t_data *data);
void	ft_display_fps4(t_data *data, char *fps);
void	ft_display_fps5(t_data *data, char *fps);
void	ft_display_fps6(t_data *data, char *fps);
void	ft_fps_counter(t_data *data, int flag);
void	ft_display_fps3(t_data *data, char *fps);
void	ft_display_fps2(t_data *data, char *fps);
void	ft_display_fps1(t_data *data, char *fps);
void	ft_draw_map(t_data *data);
double	ft_dist_ang(t_data *data, double player_angle, int *d, int flag);
void	ft_draw_fov(t_data *data, t_img img);
t_slope	ft_init_slope(t_pos pos1, t_pos pos2, t_pos pos3);
t_pos	ft_init_x_fov(t_slope slp, t_pos pos1, t_pos pos2, int y);
void	ft_var_pos(t_data *data, t_pos *pos, double a1);
void	ft_swap_pos(t_pos *pos1, t_pos *pos2, t_pos *pos3);
void	swap(int *a, int *b);
double	ft_angle_loop(double angle);
void	ft_draw_all(t_data *data);
void	ft_fusion_img_resized(t_img *dst, t_img *src, int x);
void	ft_fusion_img(t_img *dst, t_img *src, int x, int y);
void	ft_draw_weapon(t_data *data);
int		ft_is_mouvement(t_data *data);
void	ft_door(t_data *data, double move_speed, int flag);
int		ft_dist_int(int ax, int ay, int bx, int by);
int		ft_check_color(t_data *data, int map_x, int map_y);
int		ft_collision(t_data *data, int map_x, int map_y);
int		ft_mouse_hook(int x, int y, t_data *data);
void	ft_turn_player(t_data *data, double rot_speed, int flag);

void	calculate_floor_params(t_data *data);
void	render_floor_and_ceiling(t_data *data);
void	initialize_ray_params(t_data *data);
void	calculate_wall_distance_y(t_data *data);
void	calculate_wall_params(t_data *data);
void	calculate_texture_params(t_data *data);
void	calculate_wall_distance_and_texture(t_data *data);
void	render_wall(t_data *data);
void	calculate_step_and_side_dist(t_data *data);
void	perform_dda(t_data *data);
void	calculate_wall_distance_x(t_data *data);

#endif
