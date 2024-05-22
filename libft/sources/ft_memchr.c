/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:53:11 by afont             #+#    #+#             */
/*   Updated: 2024/05/17 09:42:21 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*
int main()
{
	char s[] = ".g...`w.b...S.t1f..h{.DB..`-,d.Y.t........-.^.}.";
	printf("%s", ft_memchr(s, '\317', 45));
	printf("%s", memchr(s, 651, 26));
}*/
