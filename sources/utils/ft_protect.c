/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:16:54 by afont             #+#    #+#             */
/*   Updated: 2024/06/24 10:05:34 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_protect_malloc(void *ptr)
{
	if (!ptr)
	{
		perror("Erorr malloc");
		exit(EXIT_FAILURE);
	}
}

void	ft_protect_img(void *img_ptr)
{
	if (!img_ptr)
	{
		perror("Error img allocation");
		exit(EXIT_FAILURE);
	}
}
