/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:57:42 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:57:43 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_realloc(char *src, int size)
{
	char	*temp;

	temp = src;
	if (src != NULL)
	{
		size += ft_strlen(src);
		src = (char *)ft_calloc(1, (size_t)size);
		ft_strcpy(src, temp);
		free(temp);
	}
	else
		src = (char *)ft_calloc(1, (size_t)size);
	return (src);
}
