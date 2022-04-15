/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:42:40 by omanar            #+#    #+#             */
/*   Updated: 2022/04/15 07:17:53 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	is_integer(char **av, int ac, int nb)
{
	int	i;
	int	j;

	i = nb;
	while (av[i])
	{
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			error("Error\n");
		if (ac == 1)
			return (0);
		if (av[i][0] == 0)
			error("Error\n");
		j = 0;
		if ((av[i][0] == '-' || av[i][0] == '+') && av[i][1])
			j++;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9'))
				error("Error\n");
			j++;
		}
		i++;
	}
	return (0);
}

int	is_repeated(char **av, int ac, int nb)
{
	int	i;
	int	j;

	i = nb;
	if (ac == 1)
		return (0);
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				error("Error\n");
			j++;
		}
		i++;
	}
	return (0);
}

void	stack_filling(t_list **a, char **av, int ac)
{
	int		i;
	int		tmp;
	char	**str;

	i = 0;
	if (ac == 1)
	{
		str = ft_split(av[1], ' ');
		arg_check(str);
		while (str[i])
		{
			tmp = ft_atoi(str[i]);
			ft_lstadd_back(a, ft_lstnew(tmp));
			free(str[i++]);
		}
		free(str);
	}
	else
	{
		while (av[++i])
		{
			tmp = ft_atoi(av[i]);
			ft_lstadd_back(a, ft_lstnew(tmp));
		}
	}
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
