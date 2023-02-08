/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:02:42 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 20:04:47 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void	ft_cleaner(t_info *info)
{
	if (info->args)
		ft_cmdclear(&info->args);
	info->p_id = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;
	t_cmd	arg;
	char	**split;

	(void) argc;
	(void) argv;
	ft_initializer(envp, &info);
	while (info->exit_t)
	{
		ft_signal(info, 1);
		ft_cleaner(info);
		if (!ft_readline(info))
			break ;
		ft_parser(info);
		ft_executor(info);
	}
	ft_destructor(info);
	return (0);
}
