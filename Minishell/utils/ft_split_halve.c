/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_halve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:00:41 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 18:00:43 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_strchr_(const char *s, int c)
{
	while (*s)
	{		
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

char	**ft_split_halve(char const *s, char c)
{
	char	**halve;
	char	*pos;

	pos = ft_strchr_(s, c);
	halve = malloc(sizeof (char **) * 3);
	halve[0] = ft_strndup(s, pos - s);
	pos++;
	if (*pos == '\0')
		halve[1] = ft_strdup("\0");
	else
		halve[1] = ft_strdup(pos);
	halve[2] = NULL;
	return (halve);
}
