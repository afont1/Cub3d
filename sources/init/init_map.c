/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:35:13 by afont             #+#    #+#             */
/*   Updated: 2024/06/14 09:01:34 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_line_to_map(t_data *data, char *line, int j)
{
	int	i;

	data->map.tab_map[j] = malloc(sizeof(char) * (data->map.width + 1));
	i = -1;
	while (line[++i] && line[i] != '\n')
		data->map.tab_map[j][i] = line[i];
	while (i < data->map.width)
		data->map.tab_map[j][i++] = ' ';
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
		printf("Error open\n");
		exit(0);
	}
	data->map.height = ft_get_map_height(argv);
	data->map.width = ft_get_map_width(argv) - 1;
	data->map.tab_map = malloc(sizeof(char *) * (data->map.height + 1));
	j = -1;
	line = get_next_line(fd);
	while (line)
	{
		ft_line_to_map(data, line, ++j);
		free(line);
		line = get_next_line(fd);
	}
	data->map.tab_map[j + 1] = NULL;
	// j = -1;
	// while (data->map.tab_map[++j])
	// {
	// 	int i = -1;
	// 	while (data->map.tab_map[j][++i])
	// 	{
	// 		if (data->map.tab_map[j][i] == ' ')
	// 			printf("-");
	// 		else if (data->map.tab_map[j][i] == '1')
	// 			printf("+");
	// 		else if (data->map.tab_map[j][i] == '0')
	// 			printf(".");
	// 		else
	// 			printf("%d", data->map.tab_map[j][i]);
	// 	}
	// 	printf(";\n");
	// }
	close(fd);
}
