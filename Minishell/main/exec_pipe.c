/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:44:58 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:45:00 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pipes_init(t_info *info)
{
	int	i;

	i = 0;
	info->pipe = malloc(sizeof(int *) * (info->cmd_num - 1));
	if (info->pipe == NULL)
		exit(12);
	while (i < (info->cmd_num - 1))
	{
		info->pipe[i] = malloc(sizeof(int) * 2);
		if (info->pipe[i] == NULL)
			exit(12);
		if (pipe(info->pipe[i]))
			exit(1);
		i++;
	}
}

void	ft_close_pipe_exception(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i != (info->cmd_num - 1))
	{
		j = 0;
		while (j != 2)
		{
			if (info->p_id != i && info->p_id - 1 != i)
				close(info->pipe[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_close_all_pipes(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < (info->cmd_num - 1))
	{
		j = 0;
		while (j != 2)
		{
			close(info->pipe[i][j++]);
		}
		i++;
	}
}

void	ft_free_all_pipes(t_info *info)
{
	int	i;

	i = 0;
	if (info->pipe == NULL)
		exit(12);
	while (i < (info->cmd_num - 1))
		free(info->pipe[i++]);
	free(info->pipe);
}
