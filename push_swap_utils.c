/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:42:40 by omanar            #+#    #+#             */
/*   Updated: 2022/04/14 00:51:52 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

int	is_integer(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i <= ac)
	{
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			error("Error\nNot an integer\n");
		if (av[i][0] == 0)
			error("Error\nEmpty string\n");
		j = 0;
		if ((av[i][0] == '-' || av[i][0] == '+') && av[i][1])
			j++;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9'))
				error("Error\nNot a number\n");
			j++;
		}
		i++;
	}
	return (0);
}

int	is_repeated(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i <= ac)
	{
		j = i + 1;
		while (j <= ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				error("Error Double\n");
			j++;
		}
		i++;
	}
	return (0);
}

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

int	is_stack_sorted(t_list *s)
{
	int	tmp;

	if (s)
	{
		while (s->next)
		{
			tmp = s->content;
			s = s->next;
			if (tmp > s->content)
				return (0);
		}
		return (1);
	}
	return (0);
}
