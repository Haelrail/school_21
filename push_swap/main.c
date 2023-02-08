/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:13:03 by cjoie             #+#    #+#             */
/*   Updated: 2022/03/19 17:01:36 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(t_list **a, int argc, char **argv, int *len)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		lstadd_front(a, lstnew((new_atoi(argv[argc - i]))), len);
		check_duplicates(*a, i);
		i++;
	}
}

int	final_rotates(t_list *a, t_data data)
{
	int	i;

	i = 0;
	while (a->content != data.min)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	last_steps(t_data data, t_list **a, int n)
{
	n = final_rotates(*a, data);
	if (n <= data.len_a / 2)
	{
		while (n--)
			rotate_a(a);
	}
	else
	{
		while (data.len_a - n++)
			rev_rotate_a(a);
	}
}

int	push_swap(t_list **a, t_list **b, t_data data, int n)
{
	find_max(*a, &data);
	find_min(*a, &data);
	if (data.len_a < 7)
	{
		sort_six(a, b, &data);
		return (0);
	}
	transpher_all(a, b, &data);
	while (data.len_b)
	{
		move_amount(*a, *b, data);
		b_index_trans(a, b, &data);
	}
	n = final_rotates(*a, data);
	last_steps(data, a, n);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_data	data;
	int		n;

	b = NULL;
	n = 0;
	data.len_a = 0;
	data.len_b = 0;
	if (argc <= 2)
		return (0);
	check_args(argc, argv);
	init_list(&a, argc, argv, &data.len_a);
	if (!is_sort(a, data.len_a))
		push_swap(&a, &b, data, n);
	lst_clear(&a, data.len_a);
	return (0);
}
