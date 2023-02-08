/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:46:06 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:48:22 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_readline(t_info *info)
{
	if (info->input)
		ft_strfree(info->input);
	info->input = readline(SHELL);
	if (info->input)
		add_history(info->input);
	if (!info->input)
	{
		ft_putstr_fd(SHELL, 2);
		ft_putstr_fd("exit\n", 2);
	}
	else if (!info->input)
		ft_perror_eof(info);
	return (info->input);
}
