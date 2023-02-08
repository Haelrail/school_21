/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:17:21 by cjoie             #+#    #+#             */
/*   Updated: 2022/03/19 17:07:08 by cjoie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				move_amount;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_data
{
	int				max;
	int				min;
	int				len_a;
	int				len_b;
	struct s_list	*a;
	struct s_list	*b;
}	t_data;

int		new_atoi(const char *str);
void	error_message(void);
void	check_duplicates(t_list *a, int i);
int		is_sort(t_list *lst, int len);
int		str_is_numeric(char *str);
void	check_args(int argc, char **argv);
void	find_min(t_list *a, t_data *data);
void	find_max(t_list *a, t_data *data);
int		ft_strlen(const char *c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
t_list	*lstnew(int content);
t_list	*lstlast(t_list *lst, int len);
void	lstadd_back(t_list **lst, t_list *new, int *len);
void	lstadd_front(t_list **lst, t_list *new, int *len);
void	init_list(t_list **a, int argc, char **argv, int *len);
int		final_rotates(t_list *a, t_data data);
void	last_steps(t_data data, t_list **a, int n);
int		push_swap(t_list **a, t_list **b, t_data data, int n);
void	move_amount(t_list *a, t_list *b, t_data data);
void	transpher_all(t_list **a, t_list **b, t_data *data);
void	push_a(t_list **a, t_list **b, int	*a_len, int *b_len);
void	push_b(t_list **a, t_list **b, int	*a_len, int *b_len);
int		*lst_get_content(t_list *lst, int index);
void	b_index_trans(t_list **a, t_list **b, t_data *data);
void	rev_rotate_a(t_list **a);
void	rev_rotate_b(t_list **b);
void	rev_rotate_r(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_r(t_list **a, t_list **b);
void	sort_three_a(t_list **lst, int *len);
void	sort_three_b(t_list **lst, int *len);
void	sort_six(t_list **a, t_list **b, t_data *data);
void	swap_a(t_list *a);
void	swap_b(t_list *b);
void	swap_ss(t_list *a, t_list *b);
void	lst_clear(t_list **lst, int i);

#endif