/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:37:29 by afont             #+#    #+#             */
/*   Updated: 2024/08/05 14:35:18 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_file_name(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (i < 5)
	{
		printf("Error file name\n");
		exit(EXIT_FAILURE);
	}
	if (av[i - 1] != 'b' || av[i - 2] != 'u' || av[i - 3] != 'c' || \
	av[i - 4] != '.')
	{
		printf("Error file name\n");
		exit(EXIT_FAILURE);
	}
}
