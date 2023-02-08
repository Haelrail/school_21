/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:18:35 by cjoie             #+#    #+#             */
/*   Updated: 2022/03/15 21:44:29 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_list **lst, int *len)
{
	if (*len == 1)
		return ;
	else if (*len == 2 && (*lst)->content > (*lst)->next->content)
		swap_a((*lst));
	else if (*len == 3)
	{
		if ((*lst)->content > (*lst)->next->next->content
			&& (*lst)->content > (*lst)->next->content)
			rotate_a(lst);
		if ((*lst)->next->content > (*lst)->content
			&& (*lst)->next->content > (*lst)->next->next->content)
			rev_rotate_a(lst);
		if ((*lst)->content > (*lst)->next->content)
			swap_a(*lst);
	}
	return ;
}

void	sort_three_b(t_list **lst, int *len)
{
	if (*len == 1)
		return ;
	else if (*len == 2 && (*lst)->content > (*lst)->next->content)
		swap_b((*lst));
	else if (*len == 3)
	{
		if ((*lst)->content > (*lst)->next->next->content
			&& (*lst)->content > (*lst)->next->content)
			rotate_b(lst);
		if ((*lst)->next->content > (*lst)->content
			&& (*lst)->next->content > (*lst)->next->next->content)
			rev_rotate_b(lst);
		if ((*lst)->content > (*lst)->next->content)
			swap_b(*lst);
	}
	return ;
}

void	sort_six(t_list **a, t_list **b, t_data *data)
{
	if (is_sort(*a, data->len_a))
		return ;
	while (data->len_a > 3)
		push_b(a, b, &data->len_a, &data->len_b);
	sort_three_a(a, &data->len_a);
	if (b)
		sort_three_b(b, &data->len_b);
	while (*b)
	{
		if ((*a)->content > (*b)->content)
		{
			push_a(a, b, &data->len_a, &data->len_b);
			rotate_a(a);
		}
		else if ((*a)->content < (*a)->next->content)
			rotate_a(a);
		else
		{
			rotate_a(a);
			push_a(a, b, &data->len_a, &data->len_b);
		}
	}
	last_steps(*data, a, final_rotates(*a, *data));
}
