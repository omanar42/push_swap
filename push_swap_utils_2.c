/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 03:26:45 by omanar            #+#    #+#             */
/*   Updated: 2022/04/12 02:47:16 by omanar           ###   ########.fr       */
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

int get_big_index(t_list *s)
{
	int	i;
	int	index;
	int	big;

	big = s->content;
	i = 0;
	index = 0;
	while (s)
	{
		if (s->content > big)
		{
			big = s->content;
			index = i;
		}
		i++;
		s = s->next;
	}
	return (index);
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

int get_min_index(t_list *s)
{
	int	i;
	int	index;
	int	small;

	small = s->content;
	i = 0;
	index = 0;
	while (s)
	{
		if (s->content < small)
		{
			small = s->content;
			index = i;
		}
		i++;
		s = s->next;
	}
	return (index);
}

int	*alloc_arr(t_list *a, int ac)
{
	int i;
	int j;
	int tmp;
	int *arr;

	arr = (int *)malloc(sizeof(int) * ac);
	i = 0;
	while (i < ac)
	{
		arr[i] = a->content;
		a = a->next;
		i++;
	}
	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
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
			{
				reverse_rotate(a, 'a');
				index = get_min_index(*a);
			}
			else
			{
				rotate(a, 'a');
				index = get_min_index(*a);
			}
		}
	}
	if (ft_lstsize(*a) == 3)
		sorting_three(a, 'a');
	else if (ft_lstsize(*a) == 2)
		sorting_two(a, 'a');
	while (*b)
		push(a, b, 'a');
}
