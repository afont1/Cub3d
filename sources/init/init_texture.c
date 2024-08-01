/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:48:11 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 01:19:51 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_color_range(t_data *data, int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
		ft_exit_before(data, "Error color range\n");
	if (r < 0 || g < 0 || b < 0)
		ft_exit_before(data, "Error color range\n");
}

int	ft_convert_rgb(t_data *data, char *str)
{
	char	**tab;
	int		r;
	int		g;
	int		b;

	tab = ft_split(str, ',');
	ft_check_tab_color(data, tab);
	r = ft_atoi(tab[0]);
	g = ft_atoi(tab[1]);
	b = ft_atoi(tab[2]);
	ft_check_color_range(data, r, g, b);
	ft_free_tab(tab);
	return (r << 16 | g << 8 | b);
}

void	ft_path_to_texture(t_data *data, char *line)
{
	char	**tab;
	int		i;

	tab = ft_split(line, ' ');
	i = -1;
	while (tab[++i])
	{
		if (!ft_strcmp(tab[i], "NO") && tab[i + 1])
			data->all_img.north_wall.path = ft_strdup(tab[i + 1]);
		else if (!ft_strcmp(tab[i], "SO") && tab[i + 1])
			data->all_img.south_wall.path = ft_strdup(tab[i + 1]);
		else if (!ft_strcmp(tab[i], "WE") && tab[i + 1])
			data->all_img.west_wall.path = ft_strdup(tab[i + 1]);
		else if (!ft_strcmp(tab[i], "EA") && tab[i + 1])
			data->all_img.east_wall.path = ft_strdup(tab[i + 1]);
	}
	ft_free_tab(tab);
}

void	ft_check_texture(t_data *data)
{
	if (!data->all_img.north_wall.path
		|| !data->all_img.south_wall.path
		|| !data->all_img.west_wall.path || !data->all_img.east_wall.path)
		ft_exit_map(data, "Error texture\n");
	data->all_img.north_wall.path[ft_strlen
		(data->all_img.north_wall.path) - 1] = '\0';
	data->all_img.south_wall.path[ft_strlen
		(data->all_img.south_wall.path) - 1] = '\0';
	data->all_img.west_wall.path[ft_strlen
		(data->all_img.west_wall.path) - 1] = '\0';
	data->all_img.east_wall.path[ft_strlen
		(data->all_img.east_wall.path) - 1] = '\0';
}

int	ft_init_texture(t_data *data, char *argv)
{
	int		fd;
	int		cpt;
	char	*line;

	cpt = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit_before(data, "Error open\n");
	while (1)
	{
		cpt++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
		{
			ft_path_to_texture(data, line);
			if (ft_texture_is_init(data, line))
				break ;
		}
		free(line);
	}
	close(fd);
	return (cpt);
}
