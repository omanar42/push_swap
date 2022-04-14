/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:48:09 by omanar            #+#    #+#             */
/*   Updated: 2022/04/14 01:56:33 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_two(t_list **s, char c)
{
	if (is_stack_sorted(*s))
		return ;
	else
		swap(s, c);
}

void	sorting_three(t_list **s, char c)
{
	if (is_stack_sorted(*s))
		return ;
	if ((*s)->content > (*s)->next->content
		&& (*s)->content > (*s)->next->next->content)
		rotate(s, c);
	else if ((*s)->next->content > (*s)->content
		&& (*s)->next->content > (*s)->next->next->content)
		reverse_rotate(s, c);
	if ((*s)->content > (*s)->next->content)
		swap(s, c);
}

void	sorting_process(t_list **a, t_list **b, int ac)
{
	int	index;

	while (ac > 3)
	{
		index = get_min_index(*a);
		if (index == 0)
		{
			push(a, b, 'b');
			ac--;
		}
		else
		{
			if (index > ac / 2)
				reverse_rotate(a, 'a');
			else
				rotate(a, 'a');
		}
	}
	if (ft_lstsize(*a) == 3)
		sorting_three(a, 'a');
	else if (ft_lstsize(*a) == 2)
		sorting_two(a, 'a');
	while (*b)
		push(a, b, 'a');
}

void	big_sorting_process(t_list **a, t_list **b, int ac)
{
	int	*arr;

	arr = alloc_arr(*a, ac);
	while (*a)
		push_chunk(a, b, ac, arr);
	while (*b)
		finish_them(a, b, arr, ac);
	while (!is_stack_sorted(*a))
		reverse_rotate(a, 'a');
	free(arr);
}
