/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_process_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:51:26 by omanar            #+#    #+#             */
/*   Updated: 2022/04/14 01:48:36 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_head_exist(int nb, int *arr, int i, int range)
{
	if (nb >= arr[i] && nb <= arr[range - 1])
		return (1);
	else
		return (0);
}

void	get_range(int *range1, int *range2, int ac, int *count)
{
	int			i;
	int			o1;
	int			o2;
	static int	x = 1;

	o1 = *range1;
	o2 = *range2;
	i = ((ac <= 150) * 8) + ((ac > 150) * 18);
	if ((ac / 2) - ((ac / i) * x) < 0)
		*range1 = 0;
	else
		*range1 = (ac / 2) - ((ac / i) * x);
	if ((ac / 2) + ((ac / i) * x) > ac)
		*range2 = ac;
	else
		*range2 = (ac / 2) + ((ac / i) * x);
	x++;
	*count = *range2 - *range1;
}

void	push_chunk(t_list **a, t_list **b, int ac, int *arr)
{
	static int	range1 = 0;
	static int	range2 = 0;
	int			count;

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

int	is_biggest_exist(int nb, t_list *s)
{
	while (s)
	{
		if (s->content == nb)
			return (1);
		s = s->next;
	}
	return (0);
}

int	get_tail(t_list *s)
{
	while (s->next)
		s = s->next;
	return (s->content);
}

void	do_that(t_list **a, t_list **b, int *down)
{
	int			index;

	if (*down == 0 || (*b)->content > get_tail(*a))
	{
		push(a, b, 'a');
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
			push(a, b, 'a');
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
