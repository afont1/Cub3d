/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:35:13 by afont             #+#    #+#             */
/*   Updated: 2024/06/10 10:11:57 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_line_to_map(t_data *data, char *line, int j)
{
	int	i;

	i = -1;
	data->map.tab_map[j] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[++i] && line[i] != '\n')
		data->map.tab_map[j][i] = line[i];
	data->map.tab_map[j][i] = 0;
}

void	ft_init_map_data(t_data *data, char *argv)
{
	int		fd;
	int		j;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		exit(0);
	}
	data->map.tab_map = malloc(sizeof(char *) * (ft_get_map_height(argv) + 1));
	j = -1;
	line = get_next_line(fd);
	while (line)
	{
		ft_line_to_map(data, line, ++j);
		free(line);
		line = get_next_line(fd);
	}
	data->map.tab_map[j + 1] = NULL;
	data->map.width = ft_strlen(data->map.tab_map[0]);
	close(fd);
}
