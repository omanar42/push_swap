/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:16:16 by omanar            #+#    #+#             */
/*   Updated: 2022/04/12 03:50:07 by omanar           ###   ########.fr       */
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

void	finish_them(t_list **a, t_list **b)
{
	int	index;

	while (*b)
	{
		index = get_big_index(*b);
		if (index == 0)
			push(a, b, 'a');
		else
		{
			if (index > ft_lstsize(*b) / 2)
			{
				reverse_rotate(b, 'b');
				index = get_big_index(*b);
			}
			else
			{
				rotate(b, 'b');
				index = get_big_index(*b);
			}
		}
	}
}

void	sorting_process_2(t_list **a, t_list **b, int ac)
{
	int	*arr;

	arr = alloc_arr(*a, ac);
	while (*a)
		push_chunk(a, b, ac, arr);
	free(arr);
	finish_them(a, b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1 || is_integer(av, ac - 1) || is_repeated(av, ac - 1))
		return (0);
	stack_filling(&a, &b, av);
	if (is_stack_sorted(a))
		return (0);
	if (ft_lstsize(a) <= 15)
		sorting_process(&a, &b, ac - 1);
	if (ft_lstsize(a) > 15)
		sorting_process_2(&a, &b, ac - 1);
	return (0);
}
