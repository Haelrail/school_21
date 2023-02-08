/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:51:00 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:51:02 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*buf;

	buf = (unsigned char *) b;
	while (n)
	{
		*buf = 0;
		buf++;
		n--;
	}
	return ;
}
