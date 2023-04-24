/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:17:04 by pmessett          #+#    #+#             */
/*   Updated: 2023/04/24 12:02:59 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			read_bytes;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strjoin(0, buf[fd]);
	if (ft_clear(buf[fd]))
		return (line);
	read_bytes = read(fd, buf[fd], BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(line);
		return (NULL);
	}
	while (read_bytes)
	{
		line = ft_strjoin(line, buf[fd]);
		if (ft_clear(buf[fd]))
			break ;
		read_bytes = read(fd, buf[fd], BUFFER_SIZE);
	}
	return (line);
}
