/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:16:16 by omanar            #+#    #+#             */
/*   Updated: 2022/04/02 18:03:37 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_filling(t_list **a, t_list **b, char **av)
{
	int	i;
	int	tmp;

	i = 1;
	while (av[i])
	{
		tmp = ft_atoi(av[i]);
		ft_lstadd_back(a, ft_lstnew(tmp));
		i++;
	}
	ft_lstadd_back(b, NULL);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1 || is_integer(av, ac - 1) || is_repeated(av, ac - 1)
		|| is_sorting(av, ac - 1))
		return (0);
	stack_filling(&a, &b, av);
	return (1);
}
