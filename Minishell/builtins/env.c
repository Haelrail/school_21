/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:40:50 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:40:51 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	env_perror(t_info *info, char *str)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	info->status = 127;
}

void	builtin_env(t_cmd *args, void *data)
{
	t_list	*env;
	t_info	*info;

	(void)args;
	info = (t_info *)data;
	if (args->cmd_argv && *args->cmd_argv)
	{
		env_perror(info, *args->cmd_argv);
		return ;
	}
	env = info->envp_list;
	while (env)
	{
		ft_putstr_fd(env->key, 1);
		ft_putchar_fd('=', 1);
		ft_putstr_fd(env->val, 1);
		ft_putchar_fd('\n', 1);
		env = env->next;
	}
	info->status = 0;
}
