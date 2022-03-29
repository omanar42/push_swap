/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:16:16 by omanar            #+#    #+#             */
/*   Updated: 2022/03/29 18:06:27 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac == 1 || is_integer(av, ac - 1) || is_repeated(av, ac - 1))
		return (0);
	printf("all good\n");
	return (1);
}
