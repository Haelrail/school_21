/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:19:18 by cjoie             #+#    #+#             */
/*   Updated: 2022/01/09 20:28:36 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print	ft_init_list(t_print *lst)
{
	lst->str_length = 0;
	return (*lst);
}

static int	ft_format_identification(const char *str, t_print *lst, int i)
{
	if (str[i + 1] == 'c')
		ft_print_char(lst);
	if (str[i + 1] == 's')
		ft_print_string(lst);
	if (str[i + 1] == 'p')
		if (ft_print_point(lst) == (-1))
			return (-1);
	if ((str[i + 1] == 'd') || (str[i + 1] == 'i'))
		if (ft_print_int(lst) == (-1))
			return (-1);
	if (str[i + 1] == 'u')
		if (ft_print_dec(lst) == (-1))
			return (-1);
	if (str[i + 1] == 'x')
		if (ft_print_hex(lst, 1) == (-1))
			return (-1);
	if (str[i + 1] == 'X')
		if (ft_print_hex(lst, 2) == (-1))
			return (-1);
	if (str[i + 1] == '%')
	{
		write(1, "%", 1);
		lst->str_length += 1;
	}
	return (1);
}

static int	ft_check_str(const char *str, t_print *lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_format_identification(str, lst, i) == (-1))
				return (-1);
			else
				i++;
		}
		else
		{
			write(1, &str[i], 1);
			j++;
		}
		i++;
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		j;
	t_print	*lst;

	lst = malloc(sizeof(t_print));
	if (lst == 0)
		return (-1);
	ft_init_list(lst);
	va_start (lst->args, str);
	j = 0;
	j = ft_check_str(str, lst);
	if (j < 0)
		return (-1);
	va_end(lst->args);
	j += lst->str_length;
	free (lst);
	return (j);
}
