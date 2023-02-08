/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:39:57 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 20:05:04 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_perror_exit_child(char *str, int error)
{
	if (str != NULL)
		perror(str);
	exit(error);
}

void	ft_search_oldpwd(char **oldpwd, t_info *info)
{
	t_list	*tmp;
	char	*new;
	char	tmp1[1024];

	new = NULL;
	tmp = ft_lstfindkey(info->export_list, "PWD");
	if (tmp != NULL)
		*oldpwd = ft_strdup(tmp->val);
	else if (tmp == NULL)
	{
		getcwd(tmp1, 1024);
		*oldpwd = ft_strdup(tmp1);
	}
	if (*oldpwd == NULL)
		ft_perror_exit_child("", 12);
}

static void	ft_print_shell(char *str, char *shell)
{
	if (str != NULL)
		ft_putstr_fd(str, 2);
	write(2, shell, ft_strlen(shell));
	write(2, "\b\b", 2);
}

void	ft_cd_error(t_info *info, char **arr, int flag, char *oldpwd)
{
	free(oldpwd);
	if (flag == 1)
	{
		ft_print_shell(NULL, SHELL);
		ft_putstr_fd(": cd: HOME not set \n", 2);
	}
	else if (flag == 2)
	{
		ft_print_shell(NULL, SHELL);
		ft_putstr_fd(": cd: ", 2);
		ft_putstr_fd(arr[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	info->status = 1;
}
