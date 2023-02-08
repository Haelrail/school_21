/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:13:44 by cjoie	           #+#    #+#             */
/*   Updated: 2022/06/07 23:03:54 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	data_x_y(t_fdf *data, int x, int y)
{
	data->x1 = x;
	data->x2 = x;
	data->y1 = y;
	data->y2 = y;
}

static void	draw_map_1(t_fdf *data, int x, int y)
{
	data_x_y(data, x, y);
	if (x < data->width - 1)
	{
		data->x2 += 1;
		put_line(data);
		data_x_y(data, x, y);
	}
	if (y < data->height - 1)
	{
		data->y2 += 1;
		put_line(data);
		data_x_y(data, x, y);
	}
}

void	draw_map(t_fdf *data)
{
	int		x;
	int		y;

	y = 0;
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			draw_map_1(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
