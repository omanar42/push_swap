/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:01:25 by omanar            #+#    #+#             */
/*   Updated: 2022/04/02 17:25:31 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **s, char c)
{
	int	tmp;

	if (!(*s) || !(*s)->next)
		return ;
	tmp = (*s)->content;
	(*s)->content = (*s)->next->content;
	(*s)->next->content = tmp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	push(t_list **a, t_list **b, char c)
{
	t_list	*tmp;

	if (c == 'a')
	{
		if (!(*b))
			return ;
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		ft_lstadd_front(a, tmp);
		ft_putstr_fd("pa\n", 1);
	}
	else if (c == 'b')
	{
		if (!(*a))
			return ;
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		ft_lstadd_front(b, tmp);
		ft_putstr_fd("pb\n", 1);
	}
}

void	rotate(t_list **s, char c)
{
	t_list	*tmp;

	if (!(*s) || !(*s)->next)
		return ;
	tmp = *s;
	*s = (*s)->next;
	tmp->next = NULL;
	ft_lstadd_back(s, tmp);
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	reverse_rotate(t_list **s, char c)
{
	t_list	*tmp;

	if (!*s || !(*s)->next)
		return ;
	tmp = *s;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(s, tmp->next);
	tmp->next = NULL;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}
