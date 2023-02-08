/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:53:31 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 14:06:30 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		a;
	long	res;

	i = 0;
	a = -1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			a = -a;
	while (str[i] == '0')
		i++;
	if (str[i] >= 48 && str[i] <= 57)
	{
		while (str[i] >= 48 && str[i] <= 57)
			res = res * 10 - (str[i++] - '0');
		if (str[i])
			return (-1);
	}
	else
		return (-1);
	return (a * (int)res);
}

long	current_time(void)
{
	struct timeval	time;
	long			value;

	gettimeofday(&time, NULL);
	value = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (value);
}

void	print_status(t_philo *ph, t_args *data, int i)
{
	long	actual_time;

	actual_time = current_time() - data->init_time;
	pthread_mutex_lock(&ph->philo_data->write);
	ft_putnbr(actual_time);
	write(1, " ", 1);
	ft_putnbr(ph->philo_num);
	if (i == 1)
		write(1, " has taken a fork\n", 18);
	if (i == 2)
		write(1, " is eating\n", 11);
	if (i == 3)
		write(1, " is sleeping\n", 13);
	if (i == 4)
		write(1, " is thinking\n", 13);
	pthread_mutex_unlock(&(ph->philo_data->write));
}

void	ft_putnbr(int n)
{
	long	arg;
	long	num;

	arg = n;
	if (arg < 0)
	{
		write(1, "-", 1);
		arg = -arg;
	}
	if (arg / 10)
		ft_putnbr(arg / 10);
	num = (arg % 10 + '0');
	write(1, &num, 1);
}
