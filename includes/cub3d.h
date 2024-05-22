/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:19:52 by afont             #+#    #+#             */
/*   Updated: 2024/05/22 10:07:19 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "define.h"

typedef struct s_data	t_data;
typedef struct s_img	t_img;
typedef struct s_pos	t_pos;

struct	s_pos
{
	int		x;
	int		y;
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

struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			keys[256];
	double		player_angle;
	t_img		img;
	t_img		map;
};


/*	main	*/
void	ft_cub3d(t_data *data, char *map);

/*	utils	*/
void	ft_protect_malloc(void *ptr);

/*	display	*/
void	ft_pixel_put(t_img img, int x, int y, int color);
t_img	ft_new_img(t_data *data, int width, int height, int x, int y);
void	ft_put_image_to_window(t_data *data, t_img img, int color);
void	ft_del_img(t_data *data);
void	ft_render_map(t_data *data);

/*	hook	*/
int		ft_key_press(int key, t_data *data);
int		ft_key_release(int key, t_data *data);
int		ft_update(t_data *data);
void	ft_move(t_data *data, int x_mv, int y_mv);

/*	init	*/
void	ft_init_data(t_data *data);
void	ft_init_map(t_data *data);

/*	free	*/
void	ft_close_window(t_data *data);
void	ft_destroy_img(t_data *data);

#endif