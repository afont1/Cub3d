/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:26:25 by afont             #+#    #+#             */
/*   Updated: 2024/06/24 10:30:33 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_map_height(char *argv)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Error open\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	ft_get_map_width(char *argv)
{
	int		width;
	int		fd;
	char	*line;

	width = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Error open\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (width < (int)ft_strlen(line))
			width = (int)ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}
