/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:28:38 by omanar            #+#    #+#             */
/*   Updated: 2022/03/31 23:03:50 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*temp;

	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				temp = *lst;
				*lst = (*lst)->next;
				del(temp->content);
				free(temp);
			}
		}
	}
}
