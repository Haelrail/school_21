/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:20:52 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 14:06:28 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args
{
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_eat;
	long				init_time;
	int					eat_counter;
	int					exit_marker;
	pthread_mutex_t		write;
	pthread_mutex_t		check;
}	t_args;

typedef struct s_philo
{
	t_args				*philo_data;
	pthread_mutex_t		*left_f;
	pthread_mutex_t		right_f;
	int					philo_num;
	int					eat_iter;
	long				last_eat;
	int					number_of_eat;
}	t_philo;

int			main(int argc, char **argv);
t_args		*args_init(int argc, char **argv);
t_philo		*philo_init(t_args *data);
pthread_t	*threads_init(t_args *data, t_philo *ph);
void		finish_philo(t_philo *ph, pthread_t *thread);
void		*ph_cycle(void *philo);
void		ft_sleep(int mtime);
void		*check_condition(void *philo);
int			error_managment(t_args *data, int i);
void		ft_putnbr(int n);
void		print_status(t_philo *ph, t_args *data, int i);
long		current_time(void);
int			ft_atoi(const char *str);
#endif