/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:45:31 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:45:32 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	init_copy_envp(t_info *info, char **envp)
{
	int		i;
	char	**envp_copy;

	i = 0;
	while (envp[i])
		i++;
	envp_copy = malloc(sizeof(char **) * (i + 1));
	i = 0;
	while (envp[i])
	{
		envp_copy[i] = ft_strdup(envp[i]);
		i++;
	}
	envp_copy[i] = NULL;
	info->envp = envp_copy;
	return ;
}

static void	init_reserved_words(t_info *info)
{
	info->reserved_words[0] = "echo";
	info->reserved_words[1] = "cd";
	info->reserved_words[2] = "pwd";
	info->reserved_words[3] = "export";
	info->reserved_words[4] = "unset";
	info->reserved_words[5] = "env";
	info->reserved_words[6] = "exit";
	return ;
}

static void	init_builtin_ptr(t_info *info)
{
	info->builtin[0] = builtin_echo;
	info->builtin[1] = builtin_cd;
	info->builtin[2] = builtin_pwd;
	info->builtin[3] = builtin_export;
	info->builtin[4] = builtin_unset;
	info->builtin[5] = builtin_env;
	info->builtin[6] = builtin_exit;
	return ;
}

static void	init_envp_list(t_info *info)
{
	int		i;
	t_list	*envp_l;
	t_list	*export_l;
	char	**split;
	char	**envp;

	i = 0;
	envp_l = NULL;
	export_l = NULL;
	envp = info->envp;
	while (envp[i])
	{
		split = ft_split_halve(envp[i], '=');
		ft_lstadd_back(&envp_l, ft_lstnew(split[0], split[1]));
		ft_lstadd_sort(&export_l, ft_lstnew(split[0], split[1]));
		ft_split_free(split);
		i++;
	}
	info->envp_list = envp_l;
	info->export_list = export_l;
	return ;
}

void	ft_initializer(char **envp, t_info **info)
{
	*info = malloc(sizeof(t_info));
	init_builtin_ptr(*info);
	init_reserved_words(*info);
	init_copy_envp(*info, envp);
	init_envp_list(*info);
	(*info)->envp_f = 0;
	init_sh_lvl(*info);
	(*info)->input = NULL;
	(*info)->args = NULL;
	(*info)->cmd_num = 0;
	(*info)->pipe = NULL;
	(*info)->exit_t = 1;
	(*info)->status = 0;
	(*info)->p_id = 0;
	return ;
}
