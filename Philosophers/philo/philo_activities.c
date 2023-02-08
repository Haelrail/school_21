/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:06:01 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 14:34:04 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eating(t_philo *ph)
{
	pthread_mutex_lock(ph->left_f);
	print_status(ph, ph->philo_data, 1);
	pthread_mutex_lock(&ph->right_f);
	print_status(ph, ph->philo_data, 1);
	pthread_mutex_lock(&ph->philo_data->check);
	ph->last_eat = current_time();
	pthread_mutex_unlock(&ph->philo_data->check);
	print_status(ph, ph->philo_data, 2);
	ft_sleep(ph->philo_data->time_to_eat);
	pthread_mutex_unlock(ph->left_f);
	pthread_mutex_unlock(&ph->right_f);
}

void	ft_sleep(int mtime)
{
	long		start;

	start = current_time();
	while ((mtime + start) > current_time())
		usleep(250);
}

void	*ph_cycle(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	pthread_mutex_lock(&ph->philo_data->check);
	ph->philo_data->exit_marker = 0;
	pthread_mutex_unlock(&ph->philo_data->check);
	if (!(ph->philo_num % 2))
		ft_sleep(ph->philo_data->time_to_sleep);
	while (ph->number_of_eat)
	{
		ft_eating(ph);
		print_status(ph, ph->philo_data, 3);
		ft_sleep(ph->philo_data->time_to_sleep);
		print_status(ph, ph->philo_data, 4);
		if (ph->number_of_eat != -1)
			ph->number_of_eat -= 1;
	}
	pthread_mutex_lock(&ph->philo_data->check);
		ph->philo_data->exit_marker++;
		ph->philo_data->eat_counter++;
	pthread_mutex_unlock(&ph->philo_data->check);
	return (NULL);
}
