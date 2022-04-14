/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 03:26:45 by omanar            #+#    #+#             */
/*   Updated: 2022/04/14 05:38:41 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_small_index(t_list *s)
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

int	get_big_index(t_list *s)
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

int	is_head_exist(int nb, int *arr, int i, int range)
{
	if (nb >= arr[i] && nb <= arr[range - 1])
		return (1);
	else
		return (0);
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
