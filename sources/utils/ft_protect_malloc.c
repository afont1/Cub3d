/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protect_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:16:54 by afont             #+#    #+#             */
/*   Updated: 2024/05/16 11:18:05 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_protect_malloc(void *ptr)
{
	if (!ptr)
	{
		perror("Erreur d'allocation de mémoire");
		exit(EXIT_FAILURE);
	}
}
