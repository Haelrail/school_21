/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:42:49 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 20:03:36 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_destructor(t_info *info)
{
	ft_lstclear(&info->export_list);
	ft_lstclear(&info->envp_list);
	ft_split_free(info->envp);
	if (info->input)
		free(info->input);
	free(info);
	info = NULL;
}
