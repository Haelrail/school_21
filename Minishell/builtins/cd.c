/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:40:25 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:40:30 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_without_argument(t_info *info, char *path)
{
	t_list	*tmp;

	tmp = ft_lstfindkey(info->export_list, "HOME");
	if (tmp != NULL && ft_strncmp("HOME", tmp->key, 5) == 0)
	{
		path = tmp->val;
		chdir(path);
	}
	else
		return (1);
	return (0);
}

static int	ft_cd_pwd(t_list *tmp, int flag, t_list *envp)
{
	char	*key;
	char	*val;
	char	tmp1[1024];
	t_list	*new;

	getcwd(tmp1, 1024);
	if (flag == 1)
	{
		free(tmp->val);
		tmp->val = ft_strdup(tmp1);
		if (tmp->val == NULL)
			exit(12);
	}
	else if (flag == 2)
	{
		key = ft_strdup("PWD");
		val = ft_strdup(tmp1);
		if (key == NULL || val == NULL)
			exit(12);
		new = ft_lstnew(key, val);
		if (!new)
			exit(12);
		ft_lstadd_back(&envp, new);
	}
	return (0);
}

static int	ft_cd_oldpwd(t_list *tmp, int flag, t_list *envp_l, char *oldpwd)
{
	char	*key;
	char	*val;
	t_list	*new;

	if (flag == 1)
	{
		free(tmp->val);
		tmp->val = oldpwd;
	}
	else if (flag == 2)
	{
		key = ft_strdup("OLDPWD");
		val = ft_strdup(oldpwd);
		free(oldpwd);
		if (key == NULL || val == NULL)
			exit(12);
		new = ft_lstnew(key, val);
		if (!new)
			exit(12);
		ft_lstadd_back(&envp_l, new);
	}
	return (0);
}

static void	ft_added_pwd_oldpwd(t_info *info, char *oldpwd, t_list *envp)
{
	int		pwd_f;
	int		oldpwd_f;
	t_list	*tmp;

	tmp = envp;
	pwd_f = 1;
	oldpwd_f = 1;
	info->envp_f = 1;
	while (tmp)
	{
		if (!ft_strncmp("PWD", tmp->key, 4))
			pwd_f = ft_cd_pwd(tmp, 1, NULL);
		else if (!ft_strncmp("OLDPWD", tmp->key, 7))
			oldpwd_f = ft_cd_oldpwd(tmp, 1, NULL, oldpwd);
		tmp = tmp->next;
	}
	if (pwd_f == 1)
		ft_cd_pwd(NULL, 2, envp);
	if (oldpwd_f == 1)
		ft_cd_oldpwd(NULL, 2, envp, oldpwd);
}

void	builtin_cd(t_cmd *args, void *data)
{
	t_info	*info;
	int		mistake;
	char	*oldpwd;
	char	*path;
	char	**cmd_argv;

	info = (t_info *)data;
	oldpwd = NULL;
	path = NULL;
	cmd_argv = args->cmd_argv;
	ft_search_oldpwd(&oldpwd, info);
	if (cmd_argv == NULL)
	{
		mistake = ft_without_argument(info, path);
		if (mistake == 1)
			ft_cd_error(info, cmd_argv, 1, oldpwd);
	}
	else
	{
		mistake = chdir(cmd_argv[0]);
		if (mistake == -1)
			ft_cd_error(info, cmd_argv, 2, oldpwd);
	}
	if (mistake == 0)
		ft_added_pwd_oldpwd(info, oldpwd, info->envp_list);
}
