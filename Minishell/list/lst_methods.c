/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:42:39 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:42:41 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst && lst->next)
		return (ft_lstlast(lst->next));
	else
		return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstfindkey(t_list *lst, char *key)
{
	while (lst)
	{
		if (!ft_strcmp(lst->key, key))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_lstkick_key(t_list **lst, char *key)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return ;
	tmp = *lst;
	if (!ft_strcmp((*lst)->key, key))
	{
		*lst = (*lst)->next;
		ft_lstdelone(tmp);
		return ;
	}
	while (tmp)
	{
		if (tmp->next)
		{
			if (!ft_strcmp(tmp->next->key, key))
			{
				tmp2 = tmp->next;
				tmp->next = tmp2->next;
				ft_lstdelone(tmp2);
			}	
		}
		tmp = tmp->next;
	}
}
