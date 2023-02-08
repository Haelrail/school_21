/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:43:11 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:43:13 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_perror(char *str)
{
	if (str != NULL)
		perror(str);
}

void	ft_perror_cmd(t_info *info, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(" : No such file or directory", 2);
	info->status = CMD_NOT_FOUND;
}

int	ft_perror_symbols(t_info *info, char *symbol)
{
	char	*s1;
	char	*s2;

	s1 = ft_strjoin(SHELL, "\b\b: ");
	s2 = ft_strjoin(s1, symbol);
	free(s1);
	ft_putstr_fd(s2, 2);
	free(s2);
	info->status = SYMBOLS_ERROR;
	return (info->status);
}

int	ft_perror_file(t_info *info, char *infile)
{
	char	*s1;
	char	*s2;

	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(infile, 2);
	info->status = errno;
	return (info->status);
}

int	ft_perror_eof(t_info *info)
{
	char	*s;
	char	*tmp;

	tmp = ft_strjoin("\x1b[F> ", SHELL);
	s = ft_strjoin(tmp, "\b\b: syntax error: unexpected end of file\n");
	free(tmp);
	ft_putstr_fd(s, 2);
	free(s);
	info->status = TOKEN_ERROR;
	return (info->status);
}
