/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_extremum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:20 by cjoie             #+#    #+#             */
/*   Updated: 2022/03/15 20:14:22 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_list *a, t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = a -> content;
	while (j < data->len_a)
	{
		if (a -> content < i)
			i = a -> content;
		a = a -> next;
		j++;
	}
	if (a -> content < i)
		i = a -> content;
	data->min = i;
}

void	find_max(t_list *a, t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = a -> content;
	while (j < data->len_a)
	{
		if (a -> content > i)
			i = a -> content;
		a = a -> next;
		j++;
	}
	if (a -> content > i)
		i = a -> content;
	data->max = i;
}
