/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:57:32 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:57:33 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_double_realloc(char **src, int size)
{
	char	**temp;
	int		i;

	temp = src;
	i = 0;
	if (src)
	{
		size += ft_split_len(src);
		src = (char **)malloc(sizeof(char *) * (size + 1));
		while (i < size)
		{
			src[i] = temp[i];
			i++;
		}
		src[i] = NULL;
		free(temp);
	}
	else
	{
		src = (char **)malloc(sizeof(char *) * (size + 1));
		src[size] = NULL;
	}
	return (src);
}
