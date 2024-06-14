/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:36:04 by afont             #+#    #+#             */
/*   Updated: 2024/06/14 14:06:34 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_key_press(int key, t_data *data)
{
	if (key > 0 && key < 256)
		data->keys[key] = 1;
	else if (key == 65307)
		ft_close_window(data);
	return (0);
}

int	ft_key_release(int key, t_data *data)
{
	if (key > 0 && key < 256)
		data->keys[key] = 0;
	return (0);
}

void	ft_turn_player(t_data *data, int flag)
{
	if (flag)
	{
		if (data->player.angle < 0)
			data->player.angle += 2 * M_PI;
		data->player.angle -= data->player.angle_step;
		if (data->player.angle_step < 0.13)
			data->player.angle_step += 0.005;
	}
	else
	{
		if (data->player.angle > 2 * M_PI)
			data->player.angle -= 2 * M_PI;
		data->player.angle += data->player.angle_step;
		if (data->player.angle_step < 0.13)
			data->player.angle_step += 0.005;
	}
}

#include <sys/time.h>
void ft_frame_counter(void)
{
    static int frame_count = 0;
    static struct timeval last_time;
    struct timeval current_time;
    
    frame_count++;
    gettimeofday(&current_time, NULL);

	double elapsed_time = (current_time.tv_sec - last_time.tv_sec) + (current_time.tv_usec - last_time.tv_usec) / 1000000.0;
    
    if (elapsed_time >= 1.0)
    {
        printf("FPS: %d\n", frame_count);
        frame_count = 0;
        last_time = current_time;
    }
}

int	ft_update(t_data *data)
{
	// static int	frame;

	// frame++;
	// if (frame == 400)
	// {
		// struct timeval	start, end;
		// long			elapsed;
		// static int		frame;
		
		// frame++;
		// gettimeofday(&start, NULL);
		if (data->keys[UP])
			ft_move_player(data, data->player.angle);
		if (data->keys[DOWN])
			ft_move_player(data, data->player.angle + M_PI);
		if (data->keys[LEFT])
			ft_turn_player(data, 1);
		else if (!data->keys[RIGHT])
			data->player.angle_step = ANGLE_STEP;
		if (data->keys[RIGHT])
			ft_turn_player(data, 0);
		else if (!data->keys[LEFT])
			data->player.angle_step = ANGLE_STEP;
			
		// ft_draw_circle(data, data->player.pos.x, data->player.pos.y, CUBE_COLOR);
		// if (data->keys[UP] || data->keys[DOWN] || data->keys[LEFT] || data->keys[RIGHT])
		// {
			ft_draw_all(data);
			ft_display_all(data);
		// }
		
		ft_frame_counter();
		// gettimeofday(&end, NULL);
		// elapsed = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
		// if (elapsed < 1000000 / FPS)
		// 	usleep(1000000 / FPS - elapsed);
		// frame = 0;
	// }
	return (0);
}
