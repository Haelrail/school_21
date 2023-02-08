/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:09:59 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 14:19:33 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sleep(int time)
{
	long		start;

	start = current_time();
	while ((time + start) > current_time())
		usleep(250);
}

void	ph_cycle(t_args *data)
{
	pthread_t	new;

	pthread_create(&new, NULL, check_death, data);
	pthread_detach(new);
	data->proc_counter++;
	if (!(data->proc_counter % 2))
		usleep(500);
	while (data->number_of_eat)
	{
		sem_wait(data->fork);
		print_status(data, 1);
		sem_wait(data->fork);
		print_status(data, 1);
		data->last_eat = current_time();
		print_status(data, 2);
		ft_sleep(data->time_to_eat);
		sem_post(data->fork);
		sem_post(data->fork);
		print_status(data, 3);
		ft_sleep(data->time_to_sleep);
		print_status(data, 4);
		if (data->number_of_eat != -1)
			data->number_of_eat--;
	}
	exit (1);
}
