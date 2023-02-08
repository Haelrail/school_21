/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:25:14 by cjoie             #+#    #+#             */
/*   Updated: 2022/01/08 13:12:21 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_print_pointer(t_print *lst, unsigned long l, int n)
{
	char	*string;

	string = malloc(sizeof(char) * n + 1);
	if (string == 0)
		return (-1);
	string[n] = 0;
	lst->str_length += n + 2;
	n--;
	if (l == 0)
		string[0] = '0';
	while (l)
	{
		if (l % 16 < 10)
			string[n] = l % 16 + '0';
		else
			string[n] = l % 16 + 'a' - 10;
		l = l / 16;
		n--;
	}
	write(1, "0x", 2);
	write(1, string, ft_strlen(string));
	free(string);
	return (1);
}

static int	ft_print_low_hex(t_print *lst, unsigned int i, int n)
{
	char			*string;

	string = malloc(sizeof(char) * n + 1);
	if (string == 0)
		return (-1);
	string[n] = 0;
	lst->str_length += n;
	n--;
	if (i == 0)
		string[0] = '0';
	while (i)
	{
		if (i % 16 < 10)
			string[n] = i % 16 + '0';
		else
			string[n] = i % 16 + 'a' - 10;
		i = i / 16;
		n--;
	}
	write(1, string, ft_strlen(string));
	free(string);
	return (1);
}

static int	ft_print_up_hex(t_print *lst, unsigned int i, int n)
{
	char			*string;

	string = malloc(sizeof(char) * n + 1);
	if (string == 0)
		return (-1);
	string[n] = 0;
	lst->str_length += n;
	n--;
	if (i == 0)
		string[0] = '0';
	while (i)
	{
		if (i % 16 < 10)
			string[n] = i % 16 + '0';
		else
			string[n] = i % 16 + 'A' - 10;
		i = i / 16;
		n--;
	}
	write(1, string, ft_strlen(string));
	free(string);
	return (1);
}

int	ft_print_hex(t_print *lst, int code)
{
	unsigned int	i;
	unsigned int	j;
	int				n;

	i = va_arg(lst->args, unsigned int);
	j = i;
	n = 0;
	while (j)
	{
		j /= 16;
		n++;
	}
	if (n == 0)
		n = 1;
	if (code == 1)
		j = ft_print_low_hex(lst, i, n);
	if (code == 2)
		n = ft_print_up_hex(lst, i, n);
	return (n);
}

int	ft_print_point(t_print *lst)
{
	unsigned long	l;
	unsigned long	j;
	int				n;

	l = (unsigned long)va_arg(lst->args, void *);
	j = l;
	n = 0;
	while (j)
	{
		j /= 16;
		n++;
	}
	if (n == 0)
		n = 1;
	n = ft_print_pointer(lst, l, n);
	return (1);
}
