/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:40:37 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:40:40 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtin_echo(t_cmd *args, void *data)
{
	int		i;
	int		flag;
	char	**cmd_argv;
	t_info	*info;

	info = (t_info *)data;
	i = 0;
	flag = 0;
	cmd_argv = args->cmd_argv;
	if (cmd_argv && *cmd_argv)
	{
		if (*cmd_argv)
			flag = ft_strncmp(*cmd_argv, "-n", 3);
		if (!flag)
			i = 1;
		while (*(cmd_argv + i))
		{
			ft_putstr_fd(*(cmd_argv + i), 1);
			if (*(cmd_argv + ++i))
				ft_putstr_fd(" ", 1);
		}
		if (flag)
			ft_putstr_fd("\n", 1);
	}
	info->status = 0;
}
