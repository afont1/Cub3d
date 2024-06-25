/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:35:13 by afont             #+#    #+#             */
/*   Updated: 2024/06/24 10:55:01 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_wall(t_data *data, char **map, int i, int j)
{
	if (i == 0 || i == data->map.height - 1)
		return (1);
	else if (j == 0 || j == data->map.width - 1)
		return (1);
	else
	{
		if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
			return (1);
	}
	return (0);
}

void	ft_check_map(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while (data->map.tab_map[++i])
	{
		j = -1;
		while (data->map.tab_map[i][++j])
		{
			if (data->map.tab_map[i][j] == '0' || data->map.tab_map[i][j] == 'N' || data->map.tab_map[i][j] == 'S' || data->map.tab_map[i][j] == 'E' || data->map.tab_map[i][j] == 'W')
			{
				if (ft_check_wall(data,data->map.tab_map, i, j))
					ft_exit_map(data, "Error wall\n");
				if (data->map.tab_map[i][j] == 'N' || data->map.tab_map[i][j] == 'S' || data->map.tab_map[i][j] == 'E' || data->map.tab_map[i][j] == 'W')
					flag++;
			}
			else if (data->map.tab_map[i][j] != '1' && data->map.tab_map[i][j] != ' ')
				ft_exit_map(data, "Error character unknown\n");
		}
	}
	if (flag != 1)
		ft_exit_map(data, "Error player\n");
}

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
		ft_exit_open(data, "Error open\n");
	data->map.height = ft_get_map_height(argv);
	data->map.width = ft_get_map_width(argv) - 1;
	data->map.tab_map = malloc(sizeof(char *) * (data->map.height + 1));
	j = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_line_to_map(data, line, ++j);
		free(line);
	}
	data->map.tab_map[j + 1] = NULL;
	if (!data->map.tab_map[0])
	{
		free(data->map.tab_map);
		ft_exit_open(data, "Error empty map\n");
	}
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
