/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:00:55 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 18:00:56 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_wordnum(char const *s, char c)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	while (*(s + 1) && *s == c)
		s ++;
	while (*(s + 1))
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			i++;
		s ++;
	}
	return (i + 1);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_freetab(char **s, int i)
{
	while (i)
	{
		free(s[i]);
		i --;
	}
	free (s);
}

static char	**ft_maltab(char **split, const char *s, char c, int j)
{
	int	i;

	i = 0;
	while (j)
	{
		split[i] = ft_substr(s, 0, j);
		if (!split[i])
		{
			ft_freetab(split, i);
			return (NULL);
		}
		i++;
		s += j;
		while (*s && *s == c)
			s++;
		j = ft_wordlen(s, c);
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int			wordnum;
	char		**split;

	if (!s)
		return (NULL);
	wordnum = ft_wordnum(s, c);
	if (!wordnum)
		return (ft_calloc(1, sizeof(char *)));
	split = malloc(sizeof(char **) * (wordnum + 1));
	if (!split)
		return (ft_calloc(1, sizeof(char *)));
	while (*s == c)
		s++;
	return (ft_maltab(split, s, c, ft_wordlen(s, c)));
}
