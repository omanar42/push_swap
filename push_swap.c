/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:16:16 by omanar            #+#    #+#             */
/*   Updated: 2022/04/15 08:42:52 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1 || is_integer(av, ac - 1, 1) || is_repeated(av, ac - 1, 1))
		return (0);
	stack_filling(&a, av, ac - 1);
	if (is_stack_sorted(a))
		return (0);
	if (ft_lstsize(a) <= 15)
		small_sorting_process(&a, &b, ft_lstsize(a));
	if (ft_lstsize(a) > 15)
		big_sorting_process(&a, &b, ft_lstsize(a));
	return (0);
}
