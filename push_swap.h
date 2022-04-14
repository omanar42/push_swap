/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:02:38 by omanar            #+#    #+#             */
/*   Updated: 2022/04/14 05:39:28 by omanar           ###   ########.fr       */
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
void	sort_two(t_list **s, char c);
void	sort_three(t_list **s, char c);
void	small_sorting_process(t_list **a, t_list **b, int ac);
void	big_sorting_process(t_list **a, t_list **b, int ac);
int		get_small_index(t_list *s);
int		get_big_index(t_list *s);
int		is_head_exist(int nb, int *arr, int i, int range);
int		is_biggest_exist(int nb, t_list *s);
int		*create_array(t_list *a, int ac);
void	push_chunk(t_list **a, t_list **b, int ac, int *arr);
void	get_range(int *range1, int *range2, int ac, int *count);
void	finish_them(t_list **a, t_list **b, int *arr, int ac);
void	do_that(t_list **a, t_list **b, int *down);
int		get_last(t_list *s);

#endif