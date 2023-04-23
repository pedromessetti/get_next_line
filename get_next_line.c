/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:17:04 by pmessett          #+#    #+#             */
/*   Updated: 2023/04/23 17:04:23 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strjoin(0, buf);
	if (ft_clear(buf))
		return (line);
	i = read(fd, buf, BUFFER_SIZE);
	if (i < 0)
	{
		free(line);
		return (NULL);
	}
	while (i > 0)
	{
		line = ft_strjoin(line, buf);
		if (ft_clear(buf))
			break ;
		i = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}
