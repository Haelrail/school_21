/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_findword_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:45:40 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:45:41 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	add_in_argument(char **result, char *temp, int shift)
{
	int		argument_length;

	argument_length = ft_strlen(temp);
	*result = ft_realloc(*result, argument_length + 1);
	ft_strcpy(*result + shift, temp);
	free(temp);
	return (argument_length);
}

static char	*parse_single_quote(char **input)
{
	char		*result;
	char		*temp;
	int			i;

	i = 0;
	temp = ++(*input);
	while (temp[i] && (temp[i] != '\''))
		i++;
	if (i)
		result = ft_strndup(temp, i);
	else
		result = ft_strdup("\0");
	temp += i;
	if (*temp == '\'')
		temp++;
	*input = temp;
	return (result);
}

char	*find_word(char **input, t_info *info)
{
	int		shift;
	char	*result;
	char	*temp;

	shift = 0;
	temp = NULL;
	result = NULL;
	while ((*input) && !ft_strchr("|><", **input))
	{
		if (ft_isspace(**input))
			break ;
		if (**input == '\'')
			temp = parse_single_quote(input);
		else if (**input == '\"')
			temp = parse_double_quote(input, info);
		else
			temp = single_parse(input, info);
		if (temp)
			shift += add_in_argument(&result, temp, shift);
	}
	if (result)
		result[shift] = 0;
	return (result);
}
