/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:42:20 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:42:22 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	if (cmd && cmd->next)
		return (ft_cmdlast(cmd->next));
	else
		return (cmd);
}

void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new)
{
	if (!cmd || !new)
		return ;
	if (!*cmd)
	{
		*cmd = new;
		return ;
	}
	else
		ft_cmdlast(*cmd)->next = new;
}

void	ft_cmdadd_front(t_cmd **cmd, t_cmd *new)
{
	if (new)
	{
		new->next = *cmd;
		*cmd = new;
	}
}

int	ft_cmdsize(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd)
	{
		cmd = cmd->next;
		i++;
	}
	return (i);
}
