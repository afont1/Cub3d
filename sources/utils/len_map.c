/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:26:25 by afont             #+#    #+#             */
/*   Updated: 2024/08/05 10:23:08 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_map_height(t_data *data, char *argv, int cpt)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit_before(data, "Error open\n");
	ft_goto_line(fd, cpt);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (ft_check_empty(height, line))
			break ;
		if (height && line[0] != '\n')
			height++;
		if (line[0] != '\n' && !height)
			height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	ft_get_map_width(t_data *data, char *argv, int cpt)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit_before(data, "Error open\n");
	ft_goto_line(fd, cpt);
	width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (ft_check_empty(width, line))
			break ;
		if (width && line[0] != '\n')
			if (width < (int)ft_strlen(line) + 1)
				width = (int)ft_strlen(line) + 1;
		if (line[0] != '\n' && !width)
			width = (int)ft_strlen(line) + 1;
		free(line);
	}
	close(fd);
	return (width - 1);
}
