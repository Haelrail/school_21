/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:45:59 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:46:01 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*find_cmd(char *input, t_info *info, t_cmd *cmnd)
{
	while (ft_isspace(*input))
		input++;
	cmnd->cmd_name = find_word(&input, info);
	return (input);
}

static void	get_redirect_fd(char **input, t_info *info, t_cmd *cmnd)
{
	char	*temp_input;

	temp_input = *input;
	while (*temp_input)
	{
		while (ft_isspace(*temp_input))
			temp_input++;
		if (!ft_strncmp(temp_input, ">>", 2))
			get_double_forward_redirect(&temp_input, info, cmnd);
		else if (!ft_strncmp(temp_input, "<<", 2))
			get_double_back_redirect(&temp_input, info, cmnd);
		else if (!ft_strncmp(temp_input, ">", 1))
			get_forward_redirect(&temp_input, info, cmnd);
		else if (!ft_strncmp(temp_input, "<", 1))
			get_back_redirect(&temp_input, info, cmnd);
		else
			break ;
	}
	*input = temp_input;
}

static void	ft_redirect_fd(char **input, t_info *info, t_cmd *cmnd)
{
	char	*temp_input;

	temp_input = *input;
	if (*temp_input == '|')
		temp_input++;
	else
		get_redirect_fd(&temp_input, info, cmnd);
	*input = temp_input;
}

static char	*find_args(char *input, t_info *info, t_cmd *cmnd)
{
	char	*argument;
	char	**arguments;
	int		i;

	i = 0;
	arguments = NULL;
	while (*input && !ft_strchr("|><\n", input[0]))
	{
		while (ft_isspace(*input))
			input++;
		if (ft_strchr("|><", *input))
		{
			ft_redirect_fd(&input, info, cmnd);
			break ;
		}
		argument = find_word(&input, info);
		if (argument)
		{
			arguments = ft_double_realloc(arguments, 1);
			arguments[i++] = argument;
		}
	}
	cmnd->cmd_argv = arguments;
	return (input);
}

void	ft_parser(t_info *info)
{
	t_cmd	*cmnd;
	char	*input;
	int		i;

	cmnd = ft_cmdnew(NULL, NULL);
	input = info->input;
	info->args = cmnd;
	while (input)
	{
		input = find_cmd(input, info, cmnd);
		if (!*input)
			break ;
		input = find_args(input, info, cmnd);
		if (!*input)
			break ;
		ft_cmdadd_back(&cmnd, ft_cmdnew(NULL, NULL));
		cmnd = cmnd->next;
	}
}
