/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 01:41:54 by cjoie             #+#    #+#             */
/*   Updated: 2022/06/07 23:05:06 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (height);
}

int	get_width(char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(file, O_RDONLY, 0);
	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line[i])
	{
		if ((line[i] != ' ') && (line[i + 1] == ' '))
			j++;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	return (j + 1);
}

void	fill_matrix(int *z, char *line)
{
	char	**number;
	int		i;

	i = 0;
	number = ft_split(line, ' ');
	while (number[i])
	{
		z[i] = ft_atoi(number[i]);
		free(number[i]);
		i++;
	}
	free(number);
}

void	read_file(char *file, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	data->height = get_height(file);
	data->width = get_width(file);
	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	while (i <= data->height)
	{
		data->matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
}
