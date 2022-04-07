/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 03:26:45 by omanar            #+#    #+#             */
/*   Updated: 2022/04/07 03:30:59 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_small_number(t_list *s)
{
	int	small;

	small = s->content;
	while (s)
	{
		if (s->content < small)
			small = s->content;
		s = s->next;
	}
	return (small);
}

int	get_big_number(t_list *s)
{
	int	big;

	big = s->content;
	while (s)
	{
		if (s->content > big)
			big = s->content;
		s = s->next;
	}
	return (big);
}

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
