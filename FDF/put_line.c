/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:12:50 by cjoie             #+#    #+#             */
/*   Updated: 2022/06/09 17:35:47 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	ft_find_max(float x, float y)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
		return (x);
	else
		return (y);
}

static void	three_d(t_fdf *data, int z1, int z2)
{
	float	f;

	f = data->x1;
	data->x1 = (data->x1 - data->y1) * cos(data->rad);
	data->y1 = (f + data->y1) * sin(0.8) - z1;
	f = data->x2;
	data->x2 = (data->x2 - data->y2) * cos(data->rad);
	data->y2 = (f + data->y2) * sin(0.8) - z2;
}

static void	put_line_1(t_fdf *data, int z1, int z2)
{
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	data->x2 *= data->zoom;
	data->y2 *= data->zoom;
	if (z1)
		data->colour = 0xe80c0c;
	else
		data->colour = 0xffffff;
	three_d(data, z1, z2);
	data->x1 += data->shift_x;
	data->x2 += data->shift_x;
	data->y1 += data->shift_y;
	data->y2 += data->shift_y;
}

static void	put_pixel(t_fdf *data)
{
	int		i;

	i = ((int)data->y1 * data->line_length + (int)data->x1
			* (data->bits_per_pixel / 8));
	data->img_addr[i] = data->colour;
	data->img_addr[++i] = data->colour >> 8;
	data->img_addr[++i] = data->colour >> 16;
}

void	put_line(t_fdf *data)
{
	float	x_reloc;
	float	y_reloc;
	float	max;
	int		z1;
	int		z2;

	z1 = data->matrix[(int)data->y1][(int)data->x1];
	z2 = data->matrix[(int)data->y2][(int)data->x2];
	put_line_1(data, z1, z2);
	x_reloc = data->x2 - data->x1;
	y_reloc = data->y2 - data->y1;
	max = ft_find_max(x_reloc, y_reloc);
	x_reloc /= max;
	y_reloc /= max;
	while ((int)(data->x1 - data->x2) || (int)(data->y1 - data->y2))
	{
		if ((data->x1 > 1000) || (data->x1 < 0)
			|| (data->y1 > 1000) || (data->y1 < 0))
			break ;
		put_pixel(data);
		data->x1 += x_reloc;
		data->y1 += y_reloc;
	}
}
