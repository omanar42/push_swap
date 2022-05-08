/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_process_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:51:26 by omanar            #+#    #+#             */
/*   Updated: 2022/04/19 01:50:55 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_range(int *range1, int *range2, int ac, int *count)
{
	int			x;
	static int	i = 1;

	x = ((ac <= 150) * 5) + ((ac > 150) * 11);
	if ((ac / 2) - ((ac / x) * i) < 0)
		*range1 = 0;
	else
		*range1 = (ac / 2) - ((ac / x) * i);
	if ((ac / 2) + ((ac / x) * i) > ac)
		*range2 = ac;
	else
		*range2 = (ac / 2) + ((ac / x) * i);
	i++;
	*count = *range2 - *range1;
}

void	push_chunk(t_list **a, t_list **b, int ac, int *arr)
{
	int	count;
	int	range1;
	int	range2;

	get_range(&range1, &range2, ac, &count);
	while (ft_lstsize(*b) != count && *a)
	{
		if (is_head_exist((*a)->content, arr, range1, range2))
		{
			push(a, b, 'b');
			if ((*b)->content < arr[ac / 2])
				rotate(b, 'b');
		}
		else
			rotate(a, 'a');
	}
}

int	get_last(t_list *s)
{
	while (s->next)
		s = s->next;
	return (s->content);
}

void	do_that(t_list **a, t_list **b, int *down)
{
	int			index;

	if (*down == 0 || (*b)->content > get_last(*a))
	{
		push(b, a, 'a');
		rotate(a, 'a');
		(*down)++;
	}
	else
	{
		index = get_big_index(*b);
		if (index < ft_lstsize(*b) / 2)
			rotate(b, 'b');
		else
			reverse_rotate(b, 'b');
	}
}

void	finish_them(t_list **a, t_list **b, int *arr, int ac)
{
	static int	i = 1;
	static int	down = 0;

	if (is_biggest_exist(arr[ac - i], *b))
	{
		if ((*b)->content == arr[ac - i])
		{
			push(b, a, 'a');
			i++;
		}
		else
			do_that(a, b, &down);
	}
	else
	{
		reverse_rotate(a, 'a');
		i++;
		down--;
	}
}
