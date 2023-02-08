/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:44:49 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:44:51 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_dup_zero(int infile)
{
	if (dup2(infile, 0) == -1)
		exit(EXIT_DUP);
	close(infile);
}

void	ft_dup_one(int outfile)
{
	if (dup2(outfile, 1) == -1)
		exit(EXIT_DUP);
	close(outfile);
}

void	ft_pipe_one_cmd(t_cmd *cmd)
{
	if (cmd->infile != 0)
		ft_dup_zero(cmd->infile);
	if (cmd->outfile != 1)
		ft_dup_one(cmd->outfile);
}
