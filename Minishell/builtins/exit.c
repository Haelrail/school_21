/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:41:00 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:41:01 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	put_error(char *str, int error)
{
	if (error == EXIT_TOO_MANY_ARG)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	else if (error == EXIT_WRONG_ARG)
	{
		ft_putendl_fd("exit", 1);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (255);
	}
	return (0);
}

static void	one_arg_get_status(t_cmd *args, t_info *info)
{
	char			*arg;
	long long int	num;

	arg = args->cmd_argv[0];
	if (ft_isnumber(arg))
	{
		num = ft_atoll(arg);
		if (ft_mod(num) > LONG_INT_MAX)
			info->status = put_error(arg, EXIT_WRONG_ARG);
		else
			info->status = (char)num;
	}
	else
		info->status = put_error(arg, EXIT_WRONG_ARG);
}

void	builtin_exit(t_cmd *args, void *data)
{
	const int	argc = ft_split_len(args->cmd_argv);
	t_info		*info;

	info = (t_info *)data;
	ft_putendl_fd("exit", 2);
	if (argc == 1)
		one_arg_get_status(args, info);
	else if (argc > 1)
	{
		info->status = put_error(NULL, EXIT_TOO_MANY_ARG);
		return ;
	}
	if (argc == 0)
		info->status = 0;
	exit(0);
}
