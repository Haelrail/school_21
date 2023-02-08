/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:13:51 by cjoie             #+#    #+#             */
/*   Updated: 2022/03/15 20:15:13 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_atoi(const char *str)
{
	int			minus;
	long int	nb;

	minus = 1;
	nb = 0;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nb = (nb * 10) + *str++ - '0';
		if (((nb > 2147483647) && (minus > 0))
			|| ((nb > 2147483648) && (minus < 0)))
			error_message();
	}
	return (nb * minus);
}
