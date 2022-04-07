/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:20:00 by omanar            #+#    #+#             */
/*   Updated: 2022/04/02 17:20:37 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b)
{
	swap(a, 0);
	swap(b, 0);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
