/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:20:58 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 14:06:18 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_philo *ph, int i)
{
	while (i < ph->philo_data->number_of_philo)
	{
		pthread_mutex_lock(&ph->philo_data->check);
		if (ph->philo_data->number_of_philo == ph->philo_data->eat_counter)
		{
			pthread_mutex_lock(&ph->philo_data->write);
			printf("%s\n", "finished");
			return (1);
		}
		pthread_mutex_unlock(&ph->philo_data->check);
		pthread_mutex_lock(&ph->philo_data->check);
		if (((current_time() - ph[i].last_eat) > (ph->philo_data->time_to_die))
			&& (!ph->philo_data->exit_marker))
		{
			pthread_mutex_lock(&ph->philo_data->write);
			printf("%ld %d died\n",
				current_time() - ph->philo_data->init_time, i + 1);
			return (1);
		}
		pthread_mutex_unlock(&ph->philo_data->check);
		usleep(1000);
		i++;
	}
	return (0);
}

void	*check_condition(void *philo)
{
	int		i;
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		i = 0;
		if (check_death(ph, i))
			break ;
	}
	return (NULL);
}

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
