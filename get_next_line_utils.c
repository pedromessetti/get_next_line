/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:16:45 by pmessett          #+#    #+#             */
/*   Updated: 2023/04/23 16:49:15 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (++i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (!s2[0])
		return (0);
	new_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s1[i] && s1)
		new_s[i] = s1[i];
	j = 0;
	while (s2 && s2[j] != '\n' && s2[j])
		new_s[i++] = s2[j++];
	if (s2[j] == '\n')
		new_s[i++] = '\n';
	new_s[i] = '\0';
	free(s1);
	return (new_s);
}

int	ft_clear(char *s)
{
	int	i;
	int	j;
	int	is_new_line;

	i = 0;
	j = 0;
	is_new_line = 0;
	while (s[i])
	{
		if (is_new_line)
			s[j++] = s[i];
		if (s[i] == '\n')
			is_new_line = 1;
		s[i++] = '\0';
	}
	return (is_new_line);
}
