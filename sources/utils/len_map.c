/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:26:25 by afont             #+#    #+#             */
/*   Updated: 2024/05/29 11:03:43 by afont            ###   ########.fr       */
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
		perror("Error\nopen");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (height);
}
