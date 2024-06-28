/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:16:23 by afont             #+#    #+#             */
/*   Updated: 2024/06/27 15:49:36 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_tab_color(t_data *data, char **tab)
{
	int	i;
	int	j;

	if (ft_tablen(tab) != 3)
		ft_exit_before(data, "Error color len\n");
	if (tab[2][0] == '\n')
		ft_exit_before(data, "Error color len\n");
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (ft_isdigit(tab[i][j]) == 0 && tab[i][j] != '\n')
				ft_exit_before(data, "Error color digit\n");
		}
	}
}
