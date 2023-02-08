/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_methods_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:42:33 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:42:35 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
		ft_lstlast(*lst)->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void static	ft_lstadd_sort_paste(t_list *pos, t_list *new)
{
	while (pos->next)
	{
		if (strcmp(pos->next->key, new->key) < 0)
			pos = pos->next;
		else
		{
			new->next = pos->next;
			pos->next = new;
			return ;
		}
	}
	pos->next = new;
}

void	ft_lstadd_sort(t_list **lst, t_list *new)
{
	t_list	*pos;

	pos = *lst;
	if (!pos)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	if (strcmp(pos->key, new->key) >= 0)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	ft_lstadd_sort_paste(pos, new);
}
