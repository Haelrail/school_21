/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_at_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:17:35 by cjoie             #+#    #+#             */
/*   Updated: 2022/03/15 20:20:57 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lst_get_content(t_list *lst, int index)
{
	if (index)
		return (lst_get_content(lst->next, --index));
	else
		return (&lst->content);
}

static	int	b_index_seek(t_list *b, t_data *data)
{
	int	i;
	int	i_save;
	int	min_index;

	i = 0;
	i_save = 0;
	min_index = b->move_amount;
	while (i < data->len_b)
	{
		if (b->move_amount < min_index)
		{
			min_index = b->move_amount;
			i_save = i;
		}
		b = b->next;
		i++;
	}
	return (i_save);
}

static	int	a_index_seek(t_list *a, int min_content)
{
	int	i;

	i = 0;
	while (!(a->prev->content < min_content && a->content > min_content))
	{
		a = a->next;
		i++;
	}
	return (i);
}

static	void	rot_or_rev_rot(int a_index, t_data *data, t_list **a)
{
	int		i;

	i = 0;
	if (a_index > data->len_a - a_index)
	{
		i = data->len_a;
		while (i-- > a_index)
			rev_rotate_a(a);
	}
	else
	{
		while (i++ < a_index)
			rotate_a(a);
	}
}

void	b_index_trans(t_list **a, t_list **b, t_data *data)
{
	int	b_index;
	int	min_content;
	int	a_index;
	int	i;

	i = 0;
	b_index = b_index_seek(*b, data);
	min_content = *lst_get_content(*b, b_index);
	a_index = a_index_seek(*a, min_content);
	if (b_index > data->len_b - b_index)
	{
		i = data->len_b;
		while (i-- > b_index)
			rev_rotate_b(b);
	}
	else
	{
		while (i++ < b_index)
			rotate_b(b);
	}
	rot_or_rev_rot(a_index, data, a);
	push_a(a, b, &data->len_a, &data->len_b);
}
