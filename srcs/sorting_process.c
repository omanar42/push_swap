/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:48:09 by omanar            #+#    #+#             */
/*   Updated: 2022/04/19 01:50:57 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_list **s, char c)
{
	if (is_stack_sorted(*s))
		return ;
	else
		swap(s, c);
}

void	sort_three(t_list **s, char c)
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

void	small_sorting_process(t_list **a, t_list **b, int ac)
{
	int	index;

	while (ac > 3)
	{
		index = get_small_index(*a);
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
		sort_three(a, 'a');
	else if (ft_lstsize(*a) == 2)
		sort_two(a, 'a');
	while (*b)
		push(b, a, 'a');
}

int	*create_array(t_list *a, int ac)
{
	int	tmps[3];
	int	*arr;

	arr = (int *)malloc(sizeof(int) * ac);
	tmps[0] = 0;
	while (tmps[0] < ac)
	{
		arr[tmps[0]++] = a->content;
		a = a->next;
	}
	tmps[0] = -1;
	while (++tmps[0] < ac)
	{
		tmps[1] = 0;
		while (++tmps[1] + tmps[0] < ac)
		{
			if (arr[tmps[0]] > arr[tmps[1] + tmps[0]])
			{
				tmps[2] = arr[tmps[0]];
				arr[tmps[0]] = arr[tmps[1] + tmps[0]];
				arr[tmps[1] + tmps[0]] = tmps[2];
			}
		}
	}
	return (arr);
}

void	big_sorting_process(t_list **a, t_list **b, int ac)
{
	int	*arr;

	arr = create_array(*a, ac);
	while (*a)
		push_chunk(a, b, ac, arr);
	while (*b)
		finish_them(a, b, arr, ac);
	while (!is_stack_sorted(*a))
		reverse_rotate(a, 'a');
	free(arr);
}
