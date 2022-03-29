/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:11:44 by omanar            #+#    #+#             */
/*   Updated: 2022/03/29 18:07:07 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_loop(const char *str, int i, int count, int is_neg)
{
	long long	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		count++;
	}
	return (res * is_neg);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			is_neg;
	int			count;
	long long	p;

	is_neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	count = 0;
	p = ft_loop(str, i, count, is_neg);
	return (p);
}
