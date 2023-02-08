/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:46:53 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 14:06:08 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <unistd.h>
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
	int					proc_counter;
	int					pids[250];
	long				init_time;
	long				last_eat;
	sem_t				*fork;
	sem_t				*write;
}	t_args;

int			error_managment(t_args *data, int flag);
int			ft_atoi(const char *str);
void		ft_sleep(int time);
long		current_time(void);
t_args		*args_init(int argc, char **argv);
void		ft_putnbr(int n);
void		*ft_memset(void *b, int c, size_t len);
void		sema_init(int flag, t_args *data);
void		*check_death(void *philo);
void		print_status(t_args *data, int flag);
void		ph_cycle(t_args *data);
void		pid_waiting(t_args *data);
void		born_philo(t_args *data);

#endif