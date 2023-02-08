/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:45:14 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:45:16 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_executor(t_info *info)
{
	if (info->args == NULL)
		return ;
	info->cmd_num = ft_cmdsize(info->args);
	if (info->cmd_num == 1)
		ft_exec_one_cmd(info->args, info);
	else
		ft_exec_many_cmd(info->args, info);
}
