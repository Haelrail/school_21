/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:12:50 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 14:06:01 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	error_managment(t_args *data, int i)
{	
	if (i < 0)
	{
		free(data);
		i *= -1;
	}
	if (i == 1)
		write(2, "Error: wrong number of arguments\n", 33);
	if (i == 2)
		write(2, "Error: incorrect arguments\n", 27);
	if (i == 3)
		write(2, "Error: memory error\n", 20);
	return (1);
}

void	*check_death(void *data)
{
	t_args	*ph;

	ph = (t_args *)data;
	while (1)
	{
		if ((current_time() - ph->last_eat) > (ph->time_to_die))
		{
			sem_wait(ph->write);
			printf("%ld %d died\n",
				current_time() - ph->init_time, ph->proc_counter);
			exit (0);
		}
		usleep(500);
	}
}
