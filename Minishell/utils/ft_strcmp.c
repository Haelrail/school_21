/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:01:07 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 18:01:08 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		cmp;

	i = 0;
	cmp = 0;
	while (cmp == 0)
	{
		cmp = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			break ;
	}
	return (cmp);
}
