/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:42:02 by afont             #+#    #+#             */
/*   Updated: 2024/08/03 12:26:44 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_join(char *line, char *buff)
{
	char	*t;

	t = ft_strjoin_gnl(line, buff);
	free(line);
	return (t);
}

char	*read_line(int fd, char *line)
{
	char	*buff;
	int		b_read;

	b_read = 1;
	buff = malloc(BUFFER_SIZE + 1);
	buff[0] = 0;
	while (b_read != 0 && !is_newline(buff))
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(line);
			free(buff);
			return (NULL);
		}
		buff[b_read] = 0;
		line = free_join(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_line(fd, buff);
	if (!buff)
		return (NULL);
	line = del_newline(buff);
	buff = after_newline(buff);
	return (line);
}
