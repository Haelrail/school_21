/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haelrail <haelrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:30:30 by cjoie             #+#    #+#             */
/*   Updated: 2022/05/27 23:06:54 by haelrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*d;

	i = 0;
	d = (char *)s;
	if (c > 127)
		c = c % 128;
	while (d[i])
	{
		if (d[i] == c)
			return (d + i);
		else
			i++;
	}
	if (c == '\0')
		return (&d[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*sum;
	char	*s_1;
	char	*s_2;

	s_1 = (char *)s1;
	s_2 = (char *)s2;
	if ((!(s_1)) || (!(s_2)))
		return (0);
	sum = malloc (sizeof(char) * (ft_strlen(s_1) + ft_strlen(s_2) + 1));
	if (sum == 0)
		return (0);
	i = 0;
	while (*s_1)
	{
		sum[i] = *s_1++;
		i++;
	}
	while (*s_2)
	{
		sum[i] = *s_2++;
		i++;
	}
	sum[i] = '\0';
	return (sum);
}

static int	ft_find_i(char *sub, size_t l, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (sub[l + i] && (i < len))
	{
		i++;
	}
	if ((start + 1) > (unsigned int)ft_strlen(sub))
		i = 0;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	l;

	l = (size_t)start;
	i = 0;
	sub = (char *)s;
	if (sub == 0)
		return (0);
	i = ft_find_i(sub, l, start, len);
	sub = malloc (sizeof(char) * (i + 1));
	if (sub == 0)
		return (0);
	len = i;
	i = 0;
	while (s[l + i] && (i < len))
	{
		sub[i] = s[l + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
