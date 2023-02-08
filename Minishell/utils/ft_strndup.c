/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:02:09 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 18:02:10 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(n + 1);
	if (dest)
		ft_strlcpy(dest, s, n + 1);
	return (dest);
}
