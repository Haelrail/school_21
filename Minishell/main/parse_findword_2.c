/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_findword_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:45:46 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:45:47 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*check_result(char *result, int index)
{
	if (result)
		result[index] = 0;
	else
		result = ft_strdup("\0");
	return (result);
}

static int	add_in_result(char *result, char *temp, int i, int index)
{
	ft_strcpy(result + index, temp);
	free(temp);
	return (i);
}

static char	*use_variable(char **input, t_info *info)
{
	char	*result;
	char	*temp_input;
	char	c;
	int		i;

	i = 0;
	(*input)++;
	temp_input = *input;
	while (temp_input[i] && !ft_isspace(temp_input[i])
		&& !ft_strchr("$\'\"|><", temp_input[i]))
		i++;
	c = temp_input[i];
	temp_input[i] = 0;
	if (!ft_strcmp(temp_input, "?"))
		result = ft_itoa(info->status);
	else if (!i)
		result = ft_strdup("$");
	else
		result = (char *)(ft_lstfindkey(info->export_list, temp_input)->val);
	temp_input[i] = c;
	temp_input += i;
	*input = temp_input;
	return (result);
}

char	*single_parse(char **input, t_info *info)
{
	char	*temp;
	char	*result;
	int		i;
	int		index;

	index = 0;
	result = NULL;
	while (**input && !ft_strchr(" |><\n\t\v\f\r\'\"", **input))
	{
		temp = NULL;
		if (**input == '$')
			temp = use_variable(input, info);
		if (temp)
			i = ft_strlen(temp);
		else
			i = 1;
		result = ft_realloc(result, i + 1);
		if (temp)
			index += add_in_result(result, temp, i, index);
		else
			result[index++] = *(*input)++;
	}
	result = check_result(result, index);
	return (result);
}

char	*parse_double_quote(char **input, t_info *info)
{
	char	*temp;
	char	*result;
	int		i;
	int		index;

	index = 0;
	i = 1;
	result = NULL;
	(*input)++;
	while (**input && **input != '\"')
	{
		temp = NULL;
		if (**input == '$')
			temp = use_variable(input, info);
		if (temp)
			i = ft_strlen(temp);
		result = ft_realloc(result, i + 1);
		if (temp)
			index += add_in_result(result, temp, i, index);
		else
			result[index++] = *(*input)++;
	}
	if (**input == '\"')
		(*input)++;
	return (check_result(result, index));
}
