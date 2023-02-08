/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:50:53 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:50:55 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

long long int	ft_atoll(const char *str)
{
	int				minus;
	long long int	nb;

	minus = 1;
	nb = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			minus = -1;
	}
	while (ft_isdigit(*str))
		nb = (nb * 10) + *str++ - '0';
	return (nb * minus);
}
