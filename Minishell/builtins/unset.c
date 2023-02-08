/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:41:20 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:41:21 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	unset_perror(t_info *info, char *str)
{
	ft_putstr_fd(SHELL, 2);
	ft_putstr_fd(": unset: \'", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
	info->status = 1;
	return (0);
}

static int	unset_check_arg(t_info *info, char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	if (ft_isdigit(arg[0]))
		return (unset_perror(info, arg));
	while (arg[i])
	{
		if (ft_issymbol(arg[i]))
			return (unset_perror(info, arg));
		i++;
	}
	return (1);
}

void	unset_var(char *arg, t_info *info)
{
	ft_lstkick_key(&info->envp_list, arg);
	ft_lstkick_key(&info->export_list, arg);
	info->envp_f = 1;
}

void	builtin_unset(t_cmd *args, void *data)
{
	int		unset;
	char	**argv;
	t_info	*info;

	info = (t_info *)data;
	argv = args->cmd_argv;
	while (*argv)
	{
		unset = unset_check_arg(info, *argv);
		if (unset > 0)
			unset_var(*argv, info);
		argv++;
	}
}
