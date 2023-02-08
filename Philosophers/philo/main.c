/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:55:00 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 14:26:49 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*args_init(int argc, char **argv)
{
	t_args	*arg;
	int		i;

	i = 0;
	arg = malloc(sizeof (t_args));
	if (!arg)
		return (NULL);
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			free(arg);
			return (NULL);
		}
	}
	*arg = (t_args){};
	arg->number_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->number_of_eat = -1;
	if (argc == 6)
		arg->number_of_eat = ft_atoi(argv[5]);
	return (arg);
}

t_philo	*philo_init(t_args *data)
{
	t_philo		*ph;
	int			i;

	i = -1;
	ph = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!ph)
		return (NULL);
	while (++i < data->number_of_philo)
	{
		ph[i] = (t_philo){};
		ph[i].philo_num = i + 1;
		ph[i].philo_data = data;
		ph[i].number_of_eat = data->number_of_eat;
		ph[i].last_eat = current_time();
		pthread_mutex_init(&ph[i].right_f, NULL);
	}
	i = 0;
	while (++i < data->number_of_philo)
		ph[i].left_f = &ph[i - 1].right_f;
	ph[0].left_f = &ph[i - 1].right_f;
	pthread_mutex_init(&ph->philo_data->write, NULL);
	pthread_mutex_init(&ph->philo_data->check, NULL);
	return (ph);
}

pthread_t	*threads_init(t_args *data, t_philo *ph)
{
	pthread_t	*thread;
	int			thread_check;
	int			i;

	i = -1;
	thread = malloc(sizeof(pthread_t) * (data->number_of_philo + 1));
	if (!thread)
		error_managment(ph->philo_data, -2);
	data->init_time = current_time();
	while (++i < data->number_of_philo)
	{
		thread_check = pthread_create(&thread[i], NULL, ph_cycle, &(ph[i]));
		if (thread_check)
			return (NULL);
		pthread_detach(thread[i]);
	}
	thread_check = pthread_create(&thread[data->number_of_philo],
			NULL, check_condition, ph);
	if (thread_check)
		return (NULL);
	pthread_join(thread[data->number_of_philo], NULL);
	return (thread);
}

void	finish_philo(t_philo *ph, pthread_t *thread)
{
	while (ph->philo_data->number_of_philo > 0)
	{
		pthread_mutex_destroy(&ph[ph->philo_data->number_of_philo].right_f);
		(ph->philo_data->number_of_philo)--;
	}
	pthread_mutex_destroy(&ph->philo_data->write);
	pthread_mutex_destroy(&ph->philo_data->check);
	free(thread);
	free(ph->philo_data);
	free(ph);
}

int	main(int argc, char **argv)
{
	t_args		*data;
	t_philo		*philo;
	pthread_t	*threads;

	if (argc > 6 || argc < 5)
		return (error_managment(NULL, 1));
	data = args_init(argc, argv);
	if (!data)
		return (error_managment(NULL, 2));
	philo = philo_init(data);
	if (!philo)
	{
		free(data);
		return (error_managment(NULL, 3));
	}
	threads = threads_init(data, philo);
	if (!threads)
		return (error_managment(data, -3));
	finish_philo(philo, threads);
	return (0);
}
