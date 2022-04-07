/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:16:16 by omanar            #+#    #+#             */
/*   Updated: 2022/04/07 03:30:22 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_process(t_list **a, t_list **b, int ac)
{
	while (ac > 3)
	{
		if (ac && (*a)->content == get_small_number(*a))
		{
			push(a, b, 'b');
			ac--;
		}
		else
			rotate(a, 'a');
	}
	if (ft_lstsize(*a) == 3)
		sorting_three(a, 'a');
	else if (ft_lstsize(*a) == 2)
		sorting_two(a, 'a');
	while (*b)
		push(a, b, 'a');
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
	sorting_process(&a, &b, ac - 1);
	return (1);
}
