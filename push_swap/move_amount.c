/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_amount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:15:27 by cjoie             #+#    #+#             */
/*   Updated: 2022/03/15 20:16:06 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	move_amount_a(t_list *a, int i, int l, int j)
{
	t_list	*elem;

	elem = a;
	while (elem -> next)
	{
		if ((elem -> content < l) && (elem -> next -> content > l))
		{
			if (j < (i - j))
				return (j);
			else
				return (i - j);
		}
		else
			elem = elem -> next;
		j++;
	}
	if ((elem -> content < l) && (elem -> next -> content > l))
	{
		if (j < (i - j))
			return (j);
		else
			return (i - j);
	}
	return (j);
}

void	move_amount(t_list *a, t_list *b, t_data data)
{
	int		i;
	int		j;
	t_list	*elem;

	i = data.len_b;
	elem = b;
	j = 0;
	while (j < i)
	{
		if (j < (i - j))
			elem->move_amount = j;
		else
			elem -> move_amount = i - j;
		elem -> move_amount += move_amount_a(a, data.len_a, elem -> content, 0);
		j++;
		if (elem -> next)
			elem = elem -> next;
	}
}

void	transpher_all(t_list **a, t_list **b, t_data *data)
{
	int	i;

	i = data->len_a - 2;
	while (i)
	{
		if (((*a)->content != data->max) && ((*a)->content != data->min))
		{
			push_b(a, b, &data->len_a, &data->len_b);
			i--;
		}
		else
			rotate_a(a);
	}
	if ((*a)->content > (*a)->next->content)
		swap_a(*a);
}
