/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:01:25 by omanar            #+#    #+#             */
/*   Updated: 2022/04/19 01:50:47 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	push(t_list **from, t_list **to, char c)
{
	t_list	*tmp;

	if (!(*from))
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = NULL;
	ft_lstadd_front(to, tmp);
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
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
