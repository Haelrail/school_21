/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_func_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:40 by cjoie             #+#    #+#             */
/*   Updated: 2022/03/15 20:14:41 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_arr(char **mas)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mas[i])
	{
		while (mas[i][j])
		{
			free (&mas[i][j]);
			j++;
		}
		i++;
	}
}

static char	**ft_arrayalloc(char *s, char c)
{
	int		i;
	int		j;
	char	**mas;

	i = 0;
	j = 0;
	while (s[j])
	{
		if ((s[j] != c) && ((j == 0) || (s[j - 1] == c)))
			i++;
		j++;
	}
	mas = malloc (sizeof(char *) * (i + 1));
	if (mas == 0)
		return (0);
	return (&mas[0]);
}

static char	**ft_stralloc(char **mas, char *s, char c, int *i)
{
	int		j;
	int		l;

	j = 0;
	l = 0;
	while (s[j])
	{
		if ((s[j] != c) && ((j == 0) || (s[j - 1] == c)))
		{
			l = j;
			while ((s[j] != c) && s[j])
				j++;
			mas[*i] = malloc (sizeof(char) * (j - l + 1));
			if (mas[*i] == 0)
			{
				ft_free_arr(mas);
				return (0);
			}
			ft_strlcpy(mas[*i], &s[l], j - l + 1);
			*i = *i + 1;
		}
		if (s[j])
			j++;
	}
	return (&mas[0]);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		*i1;
	char	*s1;
	char	**mas;

	s1 = (char *)s;
	i1 = &i;
	i = 0;
	if (!(s1))
		return (0);
	mas = ft_arrayalloc(s1, c);
	if (mas == 0)
		return (0);
	if (ft_strlen(s1) == 0)
	{
		mas[i] = 0;
		return (&mas[0]);
	}
	mas = ft_stralloc(mas, s1, c, i1);
	if (mas == 0)
		return (0);
	mas[i] = 0;
	return (&mas[0]);
}

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}
