/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:27:10 by afont             #+#    #+#             */
/*   Updated: 2024/06/24 13:10:01 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_display_fov(t_data *data)
{
	char	*fov;
	
	fov = ft_itoa(data->player.fov);
	if (ft_strlen(fov) >= 1)
	{
		if (fov[0] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.zero.img_ptr, 6, 22);
		else if (fov[0] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.one.img_ptr, 6, 22);
		else if (fov[0] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.two.img_ptr, 6, 22);
		else if (fov[0] == '3')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.three.img_ptr, 6, 22);
		else if (fov[0] == '4')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.four.img_ptr, 6, 22);
		else if (fov[0] == '5')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.five.img_ptr, 6, 22);
		else if (fov[0] == '6')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.six.img_ptr, 6, 22);
		else if (fov[0] == '7')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.seven.img_ptr, 6, 22);
		else if (fov[0] == '8')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.eight.img_ptr, 6, 22);
		else if (fov[0] == '9')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.nine.img_ptr, 6, 22);
	}
	
	if (ft_strlen(fov) >= 2)
	{
		if (fov[1] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.zero.img_ptr, 22, 22);
		else if (fov[1] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.one.img_ptr, 22, 22);
		else if (fov[1] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.two.img_ptr, 22, 22);
		else if (fov[1] == '3')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.three.img_ptr, 22, 22);
		else if (fov[1] == '4')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.four.img_ptr, 22, 22);
		else if (fov[1] == '5')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.five.img_ptr, 22, 22);
		else if (fov[1] == '6')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.six.img_ptr, 22, 22);
		else if (fov[1] == '7')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.seven.img_ptr, 22, 22);
		else if (fov[1] == '8')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.eight.img_ptr, 22, 22);
		else if (fov[1] == '9')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.nine.img_ptr, 22, 22);
	}

	if (ft_strlen(fov) >= 3)
	{
		if (fov[1] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.zero.img_ptr, 38, 22);
		else if (fov[1] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.one.img_ptr, 38, 22);
		else if (fov[1] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.two.img_ptr, 38, 22);
		else if (fov[1] == '3')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.three.img_ptr, 38, 22);
		else if (fov[1] == '4')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.four.img_ptr, 38, 22);
		else if (fov[1] == '5')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.five.img_ptr, 38, 22);
		else if (fov[1] == '6')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.six.img_ptr, 38, 22);
		else if (fov[1] == '7')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.seven.img_ptr, 38, 22);
		else if (fov[1] == '8')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.eight.img_ptr, 38, 22);
		else if (fov[1] == '9')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->all_img.nine.img_ptr, 38, 22);
	}
	free(fov);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ft_fill_triangle(t_img img, int x1, int y1, int x2, int y2, int x3, int y3)
{
	if (y2 < y1)
	{
		swap(&x1, &x2);
		swap(&y1, &y2);
	}
	if (y3 < y1)
	{
		swap(&x1, &x3);
		swap(&y1, &y3);
	}
	if (y3 < y2)
	{
		swap(&x2, &x3);
		swap(&y2, &y3);
	}
	float slope1 = (y2 - y1 > 0) ? (float)(x2 - x1) / (y2 - y1) : 0;
	float slope2 = (y3 - y1 > 0) ? (float)(x3 - x1) / (y3 - y1) : 0;
	float slope3 = (y3 - y2 > 0) ? (float)(x3 - x2) / (y3 - y2) : 0;
	for (int y = y1; y <= y3; y++)
	{
		int xs, xe;
		if (y < y2)
		{
			xs = x1 + slope1 * (y - y1);
			xe = x1 + slope2 * (y - y1);
		}
		else
		{
			xs = x2 + slope3 * (y - y2);
			xe = x1 + slope2 * (y - y1);
		}
		if (xs > xe)
		{
			swap(&xs, &xe);
		}
		for (int x = xs; x <= xe; x++)
			ft_pixel_put(img, x, y, ft_get_color(&img, x, y) + 0x202020);
	}
}

void	ft_fill_gap(t_img img, int start, double a1, double a2, int d1, int d2)
{
	if ((a1 <= M_PI / 4 && a1 >= 0) || (a1 >= 345 * (M_PI / 180)))
		ft_fill_triangle(img, start + cos(a1) * d1, start + sin(a1) * d1, start + cos(a2) * d2, start + sin(a2) * d2, MAP_SIZE, MAP_SIZE);
	else if (a1 >= 75  * (M_PI / 180) && a1 <= 3 * M_PI / 4)
		ft_fill_triangle(img, start + cos(a1) * d1, start + sin(a1) * d1, start + cos(a2) * d2, start + sin(a2) * d2, 0, MAP_SIZE);
	else if (a1 >= 165 * (M_PI / 180) && a1 <= 5 * M_PI / 4)
		ft_fill_triangle(img, start + cos(a1) * d1, start + sin(a1) * d1, start + cos(a2) * d2, start + sin(a2) * d2, 0, 0);
	else if (a1 >= 255 * (M_PI / 180) && a1 <= 7 * M_PI / 4)
		ft_fill_triangle(img, start + cos(a1) * d1, start + sin(a1) * d1, start + cos(a2) * d2, start + sin(a2) * d2, MAP_SIZE, 0);
}

void	ft_draw_fov(t_data *data, t_img img)
{
	int		start;
	int		distance1;
	int		distance2;
	double	angle1;
	double	angle2;

	distance1 = 0;
	angle1 = ft_dist_ang(data, data->player.angle, &distance1, 0);
	angle2 = ft_dist_ang(data, data->player.angle, &distance2, 1);
	start = (MAP_RANGE / 2) * MAP_SQUARE_SIZE + MAP_SQUARE_SIZE / 2;
	ft_fill_triangle(img, start, start, start + cos(angle1) * distance1, start + sin(angle1) * distance1, start + cos(angle2) * distance2, start + sin(angle2) * distance2);
	ft_fill_gap(img, start, angle1, angle2, distance1, distance2);
}

void	ft_fov(t_data *data)
{
	if (data->keys[113] && data->player.fov < 158)
	{
		data->player.fov += 2;
		data->player.fov_factor = JSP * (float)(FOV_BASE) / (float)(data->player.fov);
	}
	if (data->keys[101] && data->player.fov > 2)
	{
		data->player.fov -= 2;
		data->player.fov_factor = JSP * (float)(FOV_BASE) / (float)(data->player.fov);
	}
}