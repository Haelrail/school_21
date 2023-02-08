/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:07:13 by cjoie             #+#    #+#             */
/*   Updated: 2022/07/02 14:06:09 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	print_status(t_args *data, int flag)
{
	long	act_ti;

	sem_wait(data->write);
	act_ti = current_time() - data->init_time;
	ft_putnbr(act_ti);
	write(1, " ", 1);
	ft_putnbr(data->proc_counter);
	if (flag == 1)
		write(1, " has taken a fork\n", 18);
	if (flag == 2)
		write(1, " is eating\n", 11);
	if (flag == 3)
		write(1, " is sleeping\n", 13);
	if (flag == 4)
		write(1, " is thinking\n", 13);
	sem_post(data->write);
}

void	ft_putnbr(int n)
{
	long	tmp;
	long	num;

	tmp = n;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp = -tmp;
	}
	if (tmp / 10)
		ft_putnbr(tmp / 10);
	num = (tmp % 10 + '0');
	write(1, &num, 1);
}
