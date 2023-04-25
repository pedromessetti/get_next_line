/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:17:04 by pmessett          #+#    #+#             */
/*   Updated: 2023/04/24 13:08:27 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			read_bytes;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strjoin(0, buf);
	if (ft_clear(buf))
		return (line);
	read_bytes = read(fd, buf, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(line);
		return (NULL);
	}
	while (read_bytes)
	{
		line = ft_strjoin(line, buf);
		if (ft_clear(buf))
			break ;
		read_bytes = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}
