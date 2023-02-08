/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:45:52 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:45:53 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_forward_redirect(char **input, t_info *info, t_cmd *cmnd)
{
	char		*file_name;
	char		*temp_input;
	static int	fd;

	if (fd != 0)
		close(fd);
	temp_input = *input;
	temp_input++;
	while (ft_isspace(*temp_input))
		temp_input++;
	file_name = find_word(&temp_input, info);
	fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	free(file_name);
	*input = temp_input;
	if (cmnd->outfile >= 0)
		cmnd->outfile = fd;
}

void	get_double_forward_redirect(char **input, t_info *info, t_cmd *cmnd)
{
	char		*file_name;
	char		*temp_input;
	static int	fd;

	if (fd != 0)
		close(fd);
	temp_input = *input;
	temp_input += 2;
	while (ft_isspace(*temp_input))
		temp_input++;
	file_name = find_word(&temp_input, info);
	if (file_name == NULL)
		cmnd->outfile = -2;
	fd = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0664);
	free(file_name);
	*input = temp_input;
	if (cmnd->outfile >= 0)
		cmnd->outfile = fd;
}

void	get_back_redirect(char **input, t_info *info, t_cmd *cmnd)
{
	char		*file_name;
	char		*temp_input;
	static int	fd;

	if (fd != 0)
		close(fd);
	temp_input = *input;
	temp_input++;
	while (ft_isspace(*temp_input))
		temp_input++;
	file_name = find_word(&temp_input, info);
	if (file_name == NULL)
		cmnd->infile = -2;
	fd = open(file_name, O_RDONLY, 0644);
	free(file_name);
	if (cmnd->infile >= 0)
		cmnd->infile = fd;
	*input = temp_input;
}

static int	ft_fill_heredoc(t_info *info, char *delimiter)
{
	int		fd;
	char	*buff;
	char	*temp;

	buff = NULL;
	temp = NULL;
	fd = open(HEREDOC, O_CREAT | O_WRONLY | O_TRUNC, 000777);
	if (fd < 0)
		return (ft_perror_file(info, HEREDOC));
	temp = readline("> ");
	while (temp && ft_strncmp(temp, delimiter, ft_strlen(delimiter) + 1))
	{
		buff = ft_strjoin(temp, "\n\0");
		free(temp);
		write(fd, buff, ft_strlen(buff));
		free(buff);
		temp = readline("> ");
	}
	free(temp);
	close(fd);
	return (0);
}

void	get_double_back_redirect(char **input, t_info *info, t_cmd *cmnd)
{
	char	*temp_input;
	char	*delim;

	delim = NULL;
	temp_input = *input;
	temp_input += 2;
	while (ft_isspace(*temp_input))
		temp_input++;
	delim = find_word(&temp_input, info);
	if (ft_fill_heredoc(info, delim))
	{
		ft_perror_file(info, HEREDOC);
		return ;
	}
	if (cmnd->infile != 0)
		close (cmnd->infile);
	cmnd->infile = open(HEREDOC, O_RDONLY);
	*input = temp_input;
	free (delim);
}
