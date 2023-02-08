/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:07 by cjoie             #+#    #+#             */
/*   Updated: 2022/03/19 16:13:48 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	check_duplicates(t_list *a, int i)
{
	t_list	*elem;
	int		j;

	j = 1;
	elem = a->next;
	while (j < i)
	{
		if (elem->content == a->content)
			error_message();
		elem = elem->next;
		j++;
	}
}

int	is_sort(t_list *lst, int len)
{
	if (len == 1)
		return (1);
	else if (lst->content < lst->next->content)
		return (is_sort(lst->next, --len));
	else
		return (0);
}

int	str_is_numeric(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	while (argc - 1)
	{
		if (str_is_numeric(argv[argc - 1]))
			argc--;
		else
			error_message();
	}
	return ;
}
