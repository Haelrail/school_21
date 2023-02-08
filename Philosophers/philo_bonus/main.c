/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:46:58 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 14:57:52 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pid_waiting(t_args *data)
{
	int	i;
	int	sig;
	int	y;

	i = -1;
	y = 0;
	while (++i < data->number_of_philo)
	{
		waitpid(-1, &sig, 0);
		if (!sig)
		{
			i = -1;
			while (++i < data->number_of_philo)
				kill(data->pids[i], SIGTERM);
			break ;
		}
		y++;
	}
	if (y == data->number_of_philo)
		printf("finished\n");
}

void	born_philo(t_args *data)
{
	data->proc_counter = 0;
	while (data->proc_counter < data->number_of_philo)
	{
		data->pids[data->proc_counter] = fork();
		if (!data->pids[data->proc_counter])
			break ;
		data->proc_counter++;
	}
}

void	sema_init(int i, t_args *data)
{
	if (i == 1)
	{
		sem_unlink("fork");
		sem_unlink("write");
		data->fork = sem_open("fork", O_CREAT, S_IRWXU, data->number_of_philo);
		data->write = sem_open("write", O_CREAT, S_IRWXU, 1);
	}
	else if (i == 2)
	{
		sem_close(data->fork);
		sem_close(data->write);
		sem_unlink("fork");
		sem_unlink("write");
	}
}

t_args	*args_init(int argc, char **argv)
{
	t_args	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof (t_args));
	if (!tmp)
		return (NULL);
	while (++i < argc)
		if (ft_atoi(argv[i]) <= 0)
			return (NULL);
	*tmp = (t_args){};
	tmp->number_of_philo = ft_atoi(argv[1]);
	tmp->time_to_die = ft_atoi(argv[2]);
	tmp->time_to_eat = ft_atoi(argv[3]);
	tmp->time_to_sleep = ft_atoi(argv[4]);
	tmp->number_of_eat = -1;
	if (argc == 6)
		tmp->number_of_eat = ft_atoi(argv[5]);
	tmp->last_eat = current_time();
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_args		*data;

	if (argc > 6 || argc < 5)
		return (error_managment(NULL, 1));
	data = args_init(argc, argv);
	if (!data)
		return (error_managment(NULL, 2));
	sema_init(1, data);
	data->init_time = current_time();
	born_philo(data);
	if (data->proc_counter == data->number_of_philo)
		pid_waiting(data);
	else
		ph_cycle(data);
	sema_init(2, data);
	return (0);
}
