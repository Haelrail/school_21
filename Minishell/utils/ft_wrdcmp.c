/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:02:20 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 18:02:21 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_isltr(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

static int	ft_cmpltr(char c1, char c2)
{
	if (c1 == c2)
		return (0);
	if (ft_isltr(c1) && ft_isltr(c2))
	{
		if (c1 == c2)
			return (0);
		if (c1 - c2 == 32)
			return (0);
		if (c2 - c1 == 32)
			return (0);
	}
	return (c1 - c2);
}

int	ft_wrdcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		cmp;

	i = 0;
	while (1)
	{
		cmp = ft_cmpltr(s1[i], s2[i]);
		if (cmp)
			return (cmp);
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
