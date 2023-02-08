/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 03:23:29 by cjoie             #+#    #+#             */
/*   Updated: 2022/06/09 17:32:24 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	data_init(t_fdf *data)
{
	data->zoom = 10;
	data->shift_x = 400;
	data->shift_y = 250;
	data->rad = 0.8;
}

static int	hotkeys(int key, t_fdf *data)
{
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 6)
		data->zoom *= 2;
	if (key == 7)
		data->zoom /= 2;
	if (key == 0)
		data->rad -= 0.1;
	if (key == 2)
		data->rad += 0.1;
	if (key == 53)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (0);
	}
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	draw_map(data);
	return (0);
}

static int	cross_close(void *param)
{
	(void)param;
	exit(0);
}

static void	setup_controls(t_fdf *data)
{
	mlx_hook(data->win_ptr, 2, 0, hotkeys, data);
	mlx_hook(data->win_ptr, 17, 0, cross_close, data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		i;

	i = open(argv[1], O_RDONLY, 0);
	if ((argc != 2) || (read(i, 0, 0) < 0))
		return (0);
	close(i);
	i = 0;
	data = malloc(sizeof(t_fdf));
	data_init(data);
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	draw_map(data);
	setup_controls(data);
	mlx_loop(data->mlx_ptr);
	while (data->matrix[i])
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix[i]);
	free(data->matrix);
	free(data);
	return (0);
}
