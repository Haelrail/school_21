/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:45:07 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:45:09 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_fork(t_info *info, t_cmd *cmd, const char *str)
{
	ft_signal(info, 2);
	cmd->pid = fork();
	if (cmd->pid == -1)
		exit(1);
	else if (cmd->pid == 0 && str == NULL)
		exit(1);
}

void	ft_waitpid(t_info *info, int pid)
{
	int	status;

	if (waitpid(pid, &status, WUNTRACED) == -1)
		exit(1);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 3)
		{
			info->status = 131;
			ft_putstr_fd("Quit: 3\n", 1);
		}
		else if (WTERMSIG(status) == 2)
		{
			info->status = 132;
			ft_putstr_fd("\n", 1);
		}
	}
}
