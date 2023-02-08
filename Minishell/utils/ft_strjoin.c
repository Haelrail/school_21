/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:01:33 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 18:01:34 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = malloc(s1_len + s2_len + 1);
	if (strjoin)
	{
		ft_strlcpy(strjoin, s1, s1_len + 1);
		ft_strlcat(strjoin, s2, s1_len + s2_len + 1);
	}
	return (strjoin);
}

char	*ft_strjoin_(char const *s1, char const *s2)
{
	char	*strjoin;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = malloc(s1_len + s2_len + 2);
	if (strjoin)
	{
		ft_strlcpy(strjoin, s1, s1_len + 1);
		ft_strlcat(strjoin, "=", s1_len + 2);
		ft_strlcat(strjoin, s2, s1_len + s2_len + 2);
	}
	return (strjoin);
}
