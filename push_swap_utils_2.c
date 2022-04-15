/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 03:26:45 by omanar            #+#    #+#             */
/*   Updated: 2022/04/15 06:22:41 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_check(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	is_integer(str, i, 0);
	is_repeated(str, i, 0);
}

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
