/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 03:22:25 by cjoie             #+#    #+#             */
/*   Updated: 2022/06/07 23:04:49 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**matrix;
	float	zoom;
	int		colour;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	rad;
}	t_fdf;

int		get_height(char *file);
int		get_width(char *file);
void	fill_matrix(int *z, char *line);
void	read_file(char *file, t_fdf *data);
void	put_line(t_fdf *data);
void	draw_map(t_fdf *data);

#endif