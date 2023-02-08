/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:43:37 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:43:39 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exec_one_cmd(t_cmd *cmd, t_info *info)
{
	if (!ft_exec_builtin(cmd, info))
		ft_exec_bin(cmd, info);
	return ;
}

static void	ft_exec_first(t_cmd *cmds, t_info *info)
{
	ft_signal(info, 3);
	close(info->pipe[0][0]);
	ft_close_pipe_exception(info);
	if (cmds->infile != 0)
		ft_dup_zero(cmds->infile);
	if (cmds->outfile != 1)
		ft_dup_one(cmds->infile);
	else if (cmds->outfile == 1)
	{
		if (dup2(info->pipe[0][1], 1) == -1)
			exit(EXIT_DUP);
	}
	close(info->pipe[0][1]);
	ft_exec_one_cmd(cmds, info);
}

static void	ft_exec_last(t_cmd *cmds, t_info *info)
{
	ft_signal(info, 3);
	close(info->pipe[info->p_id - 1][1]);
	ft_close_pipe_exception(info);
	if (cmds->infile != 0)
		ft_dup_zero(cmds->infile);
	else if (cmds->infile == 0)
		ft_dup_zero(info->pipe[info->p_id - 1][0]);
	if (cmds->outfile != 1)
		ft_dup_one(cmds->outfile);
	close(info->pipe[info->p_id - 1][0]);
	ft_exec_one_cmd(cmds, info);
}

static void	ft_exec_inter(t_cmd *cmds, t_info *info)
{
	ft_signal(info, 3);
	close(info->pipe[info->p_id - 1][1]);
	close(info->pipe[info->p_id][0]);
	ft_close_pipe_exception(info);
	if (cmds->infile != 0)
		ft_dup_zero(cmds->infile);
	else if (cmds->infile == 0)
		ft_dup_zero(info->pipe[info->p_id - 1][0]);
	if (cmds->outfile != 1)
		ft_dup_one(cmds->outfile);
	else if (cmds->outfile == 1)
		ft_dup_one(info->pipe[info->p_id][1]);
	close(info->pipe[info->p_id - 1][0]);
	close(info->pipe[info->p_id][1]);
	ft_exec_one_cmd(cmds, info);
}

void	ft_exec_many_cmd(t_cmd *cmds, t_info *info)
{
	ft_pipes_init(info);
	while (cmds)
	{
		ft_fork(info, cmds, cmds->cmd_name);
		if (cmds->pid == 0 && info->p_id == 0)
			ft_exec_first(cmds, info);
		else if (cmds->pid == 0 && info->p_id == (info->cmd_num - 1))
			ft_exec_last(cmds, info);
		else if (cmds->pid == 0 && cmds->cmd_name != NULL)
			ft_exec_inter(cmds, info);
		info->p_id++;
		cmds = cmds->next;
	}
	ft_close_all_pipes(info);
	ft_free_all_pipes(info);
	while (--info->p_id >= 0)
		ft_waitpid(info, -1);
}
