/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:18:27 by cjoie             #+#    #+#             */
/*   Updated: 2022/03/15 20:18:29 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate(t_list **a)
{
	*a = (*a)->next;
	return ;
}

void	rotate_a(t_list **a)
{
	rotate (a);
	write(1, "ra\n", 3);
	return ;
}

void	rotate_b(t_list **b)
{
	rotate (b);
	write(1, "rb\n", 3);
	return ;
}

void	rotate_r(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	return ;
}
