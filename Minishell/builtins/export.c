/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:41:07 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:41:08 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	export_putlist(t_info *info)
{
	t_list	*env;

	env = info->export_list;
	while (env)
	{
		if (env->key)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(env->key, 1);
			if (env->val)
			{
				ft_putstr_fd("=\"", 1);
				ft_putstr_fd(env->val, 1);
				ft_putstr_fd("\"", 1);
			}
			ft_putchar_fd('\n', 1);
		}
		env = env->next;
	}
	info->status = 0;
}

static int	export_perror(t_info *info, char *str)
{
	ft_putstr_fd(SHELL, 2);
	ft_putstr_fd(": export: \'", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
	info->status = 1;
	return (0);
}

static int	export_check_arg(t_info *info, char *arg)
{
	int	i;
	int	set;

	i = 0;
	set = 1;
	if (ft_isdigit(arg[0]))
		return (export_perror(info, arg));
	while (arg[i])
	{
		if (ft_issymbol(arg[i]))
			return (export_perror(info, arg));
		if (arg[i] == '=')
			set = 2;
		i++;
	}
	return (set);
}

static void	export_set_var(char *arg, int set, t_info *info)
{
	char	**key_val;
	t_list	*lst;

	key_val = ft_split_halve(arg, '=');
	lst = ft_lstfindkey(info->export_list, key_val[0]);
	if (lst && key_val[1])
	{
		if (lst->val)
			free(lst->val);
		lst->val = ft_strdup(key_val[1]);
	}
	else
	{
		lst = ft_lstnew(key_val[0], key_val[1]);
		ft_lstadd_sort(&info->export_list, lst);
		if (set == 2)
		{
			lst = ft_lstnew(key_val[0], key_val[1]);
			ft_lstadd_back(&info->envp_list, lst);
		}
	}
	ft_split_free(key_val);
	info->envp_f = 1;
}

void	builtin_export(t_cmd *args, void *data)
{
	int		set;
	int		line;
	char	**argv;
	t_info	*info;

	info = (t_info *)data;
	if (!args->cmd_argv)
		export_putlist(info);
	else
	{
		argv = args->cmd_argv;
		while (*argv)
		{
			set = export_check_arg(info, *argv);
			if (set > 0)
				export_set_var(*argv, set, info);
			argv++;
		}
	}
}
