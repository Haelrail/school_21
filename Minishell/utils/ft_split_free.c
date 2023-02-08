/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:57:49 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:57:50 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_split_free(char **split)
{
	char	**pos;

	if (!split)
		return ;
	pos = split;
	while (*pos)
		free(*pos++);
	free(split);
	return ;
}
