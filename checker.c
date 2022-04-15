/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:59:26 by omanar            #+#    #+#             */
/*   Updated: 2022/04/15 02:31:32 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap(a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap(b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		push(a, b, 'a', 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		push(a, b, 'b', 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate(a, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(b, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(str, "rra\n", 4))
		reverse_rotate(a, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		reverse_rotate(b, 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(a, b, 0);
	else
		error("Error\n");
}

void	checker(t_list **a, t_list **b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		check_if(a, b, str);
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1 || is_integer(av, ac - 1) || is_repeated(av, ac - 1))
		return (0);
	stack_filling(&a, &b, av);
	checker(&a, &b);
	if (is_stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
