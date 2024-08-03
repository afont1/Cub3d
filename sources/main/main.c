/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:14:08 by afont             #+#    #+#             */
/*   Updated: 2024/08/03 11:34:45 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		ft_check_file_name(av[1]);
		data = malloc(sizeof(t_data));
		ft_protect_malloc(data);
		ft_init_data(data);
		ft_cub3d(data, av[1]);
	}
	else
		printf("Error\n");
	return (0);
}
