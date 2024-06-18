/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:16:54 by afont             #+#    #+#             */
/*   Updated: 2024/06/18 10:03:04 by afont            ###   ########.fr       */
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

void	ft_protect_img(void *img_ptr)
{
	if (!img_ptr)
	{
		perror("Erreur d'allocation de mémoire pour l'image");
		exit(EXIT_FAILURE);
	}
}
