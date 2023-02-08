/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:35:31 by cjoie             #+#    #+#             */
/*   Updated: 2022/01/08 13:13:04 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_print {
	va_list	args;
	int		str_length;
}	t_print;

int		ft_printf(const char *str, ...);
void	ft_print_char(t_print *lst);
void	ft_print_string(t_print *lst);
int		ft_print_point(t_print *lst);
int		ft_print_int(t_print *lst);
int		ft_print_dec(t_print *lst);
int		ft_print_hex(t_print *lst, int code);
char	*ft_itoa(int n);
int		ft_strlen(char *c);

#endif