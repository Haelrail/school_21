/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sh_lvl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:45:24 by cjoie             #+#    #+#             */
/*   Updated: 2022/11/10 17:45:25 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_shlvl_exp(t_info *info)
{
	int		shlvl;
	t_list	*elem;

	elem = ft_lstfindkey(info->export_list, "SHLVL");
	if (!elem)
	{
		elem = ft_lstnew("SHLVL", "1");
		ft_lstadd_sort(&info->export_list, elem);
		info->envp_f = 1;
	}
	shlvl = (ft_atoi(elem->val));
	shlvl++;
	free(elem->val);
	elem->val = ft_itoa(shlvl);
	info->envp_f = 1;
}

static void	ft_check_shlvl_env(t_info *info)
{
	int		shlvl;
	t_list	*elem;

	elem = ft_lstfindkey(info->envp_list, "SHLVL");
	if (!elem)
	{
		elem = ft_lstnew("SHLVL", "1");
		ft_lstadd_back(&info->envp_list, elem);
		info->envp_f = 1;
	}
	shlvl = (ft_atoi(elem->val));
	shlvl++;
	free(elem->val);
	elem->val = ft_itoa(shlvl);
	info->envp_f = 1;
}

void	init_sh_lvl(t_info *info)
{
	ft_check_shlvl_exp(info);
	ft_check_shlvl_env(info);
}
