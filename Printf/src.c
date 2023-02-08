/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:49:17 by cjoie             #+#    #+#             */
/*   Updated: 2022/01/08 13:11:50 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

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

static char	*ft_arfilling(char *ar, int n, int i)
{
	unsigned int	n1;
	int				j;

	j = 0;
	if (n < 0)
	{
		ar[j] = '-';
		j++;
		n1 = n * (-1);
	}
	else
		n1 = n;
	while (i)
	{
		ar[j] = ((n1 / i) + 48);
		n1 = n1 % i;
		i = i / 10;
		j++;
	}
	ar[j] = '\0';
	return (ar);
}

char	*ft_itoa(int n)
{
	int				i;
	int				j;
	char			*ar;

	i = n;
	j = 0;
	while (i)
	{
		i = i / 10;
		j++;
	}
	i = 1;
	if (n <= 0)
		j++;
	ar = malloc (sizeof(char) * (j + 1));
	if (ar == 0)
		return (0);
	if (n <= 0)
		j--;
	while (j > 1)
	{
		i = i * 10;
		j--;
	}
	return (ar = ft_arfilling(ar, n, i));
}
