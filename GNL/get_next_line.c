/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:53:26 by cjoie             #+#    #+#             */
/*   Updated: 2021/11/24 20:40:32 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_get_line(char **wault, char **line)
{
	int		i;
	char	*ph;

	i = 0;
	ph = 0;
	while ((*(*wault + i) != '\n') && (*(*wault + i) != '\0'))
		i++;
	if (*(*wault + i) == '\n')
	{
		*line = ft_substr(*wault, 0, i + 1);
		ph = ft_substr(*wault, i + 1, ft_strlen(*wault) - i - 1);
	}
	else
		*line = ft_substr(*wault, 0, ft_strlen(*wault));
	free(*wault);
	*wault = 0;
	return (ph);
}

static int	gnl_read(int fd, char **line, char *buffer, char **wault)
{
	int		l;
	char	*ph;

	l = 1;
	while ((ft_strchr(*wault, '\n') == 0) && (l != 0))
	{
		l = read(fd, buffer, BUFFER_SIZE);
		buffer[l] = '\0';
		ph = *wault;
		*wault = ft_strjoin(ph, buffer);
		free (ph);
	}
	buffer = 0;
	*wault = gnl_get_line(wault, line);
	return (l);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	static char	*wault;
	int			i;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, 0, 0) < 0))
		return (0);
	if (wault == 0)
	{	
		wault = ft_substr("", 0, 0);
		if (wault == 0)
			return (0);
		wault[0] = '\0';
	}
	i = gnl_read(fd, &line, buffer, &wault);
	if ((i == 0) && (*line == 0))
	{
		free(line);
		return (0);
	}
	return (line);
}
