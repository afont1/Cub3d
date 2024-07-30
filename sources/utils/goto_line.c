/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:02:33 by afont             #+#    #+#             */
/*   Updated: 2024/07/05 09:07:53 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_goto_line(int fd, int cpt)
{
	int		j;

	j = -1;
	while (++j < cpt)
	{
		free(get_next_line(fd));
		// printf("%s\n", get_next_line(fd));
	}
}
