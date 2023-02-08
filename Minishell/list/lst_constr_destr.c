/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_constr_destr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:42:27 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:42:29 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_lstnew(char *key, char *val)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem)
	{
		elem->key = NULL;
		elem->val = NULL;
		elem->next = NULL;
		if (key)
			elem->key = ft_strdup(key);
		if (val)
			elem->val = ft_strdup(val);
	}
	return (elem);
}

void	ft_lstdelone(t_list *elem)
{
	if (elem->key)
	{
		free(elem->key);
		elem->key = NULL;
	}
	if (elem->val)
	{
		free(elem->val);
		elem->val = NULL;
	}
	free(elem);
	elem = NULL;
	return ;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*buf;

	while (*lst)
	{
		buf = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(buf);
	}
	*lst = NULL;
}
