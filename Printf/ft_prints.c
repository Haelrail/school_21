/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:35:41 by cjoie             #+#    #+#             */
/*   Updated: 2022/01/08 13:12:33 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_char(t_print *lst)
{
	unsigned char	c;

	c = va_arg(lst->args, int);
	lst->str_length++;
	write(1, &c, 1);
}

void	ft_print_string(t_print *lst)
{
	char	*s;

	s = va_arg(lst->args, char *);
	if (s == 0)
	{
		write(1, "(null)", 6);
		lst->str_length += 6;
	}
	else
	{
		lst->str_length += ft_strlen(s);
		write(1, s, ft_strlen(s));
	}
}

int	ft_print_int(t_print *lst)
{
	int		i;
	char	*s;

	i = va_arg(lst->args, int);
	s = ft_itoa(i);
	if (s == 0)
		return (-1);
	lst->str_length += ft_strlen(s);
	write(1, s, ft_strlen(s));
	free (s);
	return (0);
}

static int	ft_print_uint(t_print *lst, unsigned int i, int n)
{
	char	*s;

	s = malloc(sizeof(char) * n + 1);
	if (s == 0)
		return (-1);
	s[n] = 0;
	if (i == 0)
		s[0] = '0';
	lst->str_length += n;
	n--;
	while (i)
	{
		s[n] = i % 10 + '0';
		i /= 10;
		n--;
	}
	write(1, s, ft_strlen(s));
	free (s);
	return (0);
}

int	ft_print_dec(t_print *lst)
{
	unsigned int	i;
	unsigned int	j;
	int				n;

	i = va_arg(lst->args, unsigned int);
	j = i;
	n = 0;
	while (j)
	{
		j /= 10;
		n++;
	}
	if (n == 0)
		n = 1;
	j = ft_print_uint(lst, i, n);
	if (n == (-1))
		return (-1);
	return (0);
}
