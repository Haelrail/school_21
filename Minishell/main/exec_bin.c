/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:43:23 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/13 20:01:11 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_getbin(char **path, char *name, t_info *info)
{
	char		*tmp;
	char		*pathname;

	if ((name && name[0] == '/' && access(name, X_OK)) || path == NULL)
		return (NULL);
	else if (access(name, X_OK) == 0)
		return (ft_strdup(name));
	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		pathname = ft_strjoin(tmp, name);
		free(tmp);
		if (access(pathname, X_OK) == 0)
			return (pathname);
		free((char *)pathname);
		path++;
	}
	return (NULL);
}

static void	ft_rmkenvp(t_info *info, t_list *envp_list)
{
	int		i;
	int		envp_size;
	char	**envp_copy;

	if (info->envp_f == 0)
		return ;
	envp_size = ft_lstsize(envp_list);
	envp_copy = malloc(sizeof(char **) * (envp_size + 1));
	i = 0;
	while (envp_list)
	{
		envp_copy[i] = ft_strjoin_(envp_list->key, envp_list->val);
		i++;
		envp_list = envp_list->next;
	}
	envp_copy[i] = NULL;
	ft_split_free(info->envp);
	info->envp = envp_copy;
	info->envp_f = 0;
	return ;
}

static char	**ft_getargv(t_cmd *cmd)
{
	int		i;
	int		size;
	char	**argv;

	size = ft_split_len(cmd->cmd_argv);
	argv = malloc(sizeof(char **) * (size + 2));
	argv[0] = ft_strdup(cmd->cmd_name);
	i = 0;
	while (i < size)
	{
		argv[i + 1] = ft_strdup(cmd->cmd_argv[i]);
		i++;
	}
	argv[i + 1] = NULL;
	ft_split_free(cmd->cmd_argv);
	cmd->cmd_argv = argv;
	return (argv);
}

void	ft_exec_bin(t_cmd *cmd, t_info *info)
{
	t_list		*var_path;
	char		**paths;
	char		*pathname;
	int			a;

	var_path = ft_lstfindkey(info->envp_list, "PATH");
	if (var_path == NULL || cmd->cmd_name == NULL)
		return ;
	paths = ft_split(var_path->val, ':');
	pathname = ft_getbin(paths, cmd->cmd_name, info);
	if (!pathname)
		ft_perror_cmd(info, cmd->cmd_name);
	ft_split_free(paths);
	ft_rmkenvp(info, info->envp_list);
	ft_getargv(cmd);
	ft_fork(info, cmd, pathname);
	if (cmd->pid == 0)
	{
		ft_signal(info, 3);
		ft_pipe_one_cmd(cmd);
		info->status = execve(pathname, cmd->cmd_argv, info->envp);
	}
	free(pathname);
	ft_waitpid(info, -1);
}

int	ft_exec_builtin(t_cmd *cmd, t_info *info)
{
	int	i;

	i = 0;
	if (cmd->cmd_name == NULL)
		return (0);
	while (i < BUILTIN_NUM)
	{
		if (!ft_wrdcmp(cmd->cmd_name, info->reserved_words[i]))
		{
			info->builtin[i](cmd, info);
			return (1);
		}
		i++;
	}
	return (0);
}
