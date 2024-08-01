/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:35:13 by afont             #+#    #+#             */
/*   Updated: 2024/08/01 01:17:45 by bloisel          ###   ########.fr       */
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
		if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] \
		== ' ' || map[i][j + 1] == ' ')
			return (1);
	}
	return (0);
}

int	ft_check_map2(t_data *data, char **map, int i, int j)
{
	int	flag;

	flag = 0;
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' \
	|| map[i][j] == 'E' || map[i][j] == 'W')
	{
		if (ft_check_wall(data, map, i, j))
			ft_exit_map(data, "Error wall\n");
		if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' \
		|| map[i][j] == 'W')
			flag++;
	}
	else if (map[i][j] != '1' && map[i][j] != ' '
			&& map[i][j] != '2' && map[i][j] != '4')
		ft_exit_map(data, "Error character unknown\n");
	return (flag);
}

void	ft_check_map(t_data *data, char **map)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			flag += ft_check_map2(data, map, i, j);
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

void	ft_init_map_data(t_data *data, char *argv, int cpt)
{
	int		fd;
	int		j;
	char	*line;

	data->map.height = ft_get_map_height(data, argv, cpt);
	data->map.width = ft_get_map_width(data, argv, cpt);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit_before(data, "Error open\n");
	data->map.tab_map = malloc(sizeof(char *) * (data->map.height + 1));
	ft_goto_line(fd, cpt);
	j = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
			ft_line_to_map(data, line, ++j);
		free(line);
	}
	data->map.tab_map[j + 1] = NULL;
	if (!data->map.tab_map[0])
		ft_exit_before(data, "Error empty map\n");
	close(fd);
}
