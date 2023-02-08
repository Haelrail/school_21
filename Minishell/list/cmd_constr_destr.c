/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_constr_destr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:42:14 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:42:16 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*ft_cmdnew(char *cmd_name, char **cmd_argv)
{
	t_cmd	*elem;

	elem = malloc(sizeof(t_cmd));
	if (elem)
	{
		elem->cmd_name = cmd_name;
		elem->cmd_argv = cmd_argv;
		elem->pid = 0;
		elem->infile = 0;
		elem->outfile = 1;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_cmddelone(t_cmd *elem)
{
	if (elem->cmd_name)
		ft_strfree(elem->cmd_name);
	if (elem->cmd_argv)
		ft_split_free(elem->cmd_argv);
	if (elem->infile != 0)
		close(elem->infile);
	if (elem->outfile != 1)
		close(elem->outfile);
	elem->pid = 0;
	elem->infile = 0;
	elem->outfile = 1;
	elem->next = NULL;
	free(elem);
}

void	ft_cmdclear(t_cmd **cmd)
{
	t_cmd	*buf;

	while (*cmd)
	{
		buf = *cmd;
		*cmd = (*cmd)->next;
		ft_cmddelone(buf);
	}
	*cmd = NULL;
}
