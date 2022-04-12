/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:02:38 by omanar            #+#    #+#             */
/*   Updated: 2022/04/12 02:47:24 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

void	error(char *str);
int		is_integer(char **av, int ac);
int		is_repeated(char **av, int ac);
void	stack_filling(t_list **a, t_list **b, char **av);
int		is_stack_sorted(t_list *s);
void	swap(t_list **s, char c);
void	push(t_list **a, t_list **b, char c);
void	rotate(t_list **s, char c);
void	reverse_rotate(t_list **s, char c);
void	ss(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
void	sorting_process(t_list **a, t_list **b, int ac);
void	sorting_two(t_list **s, char c);
void	sorting_three(t_list **s, char c);
int		get_big_number(t_list *s);
int		get_small_number(t_list *s);
int		get_min_index(t_list *s);
int		get_big_index(t_list *s);
int		*alloc_arr(t_list *a, int ac);

#endif