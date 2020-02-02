/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/02 12:55:44 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t max(intmax_t a, intmax_t b)
{
	if (a > b)
		return (a);
	return (b);
}

intmax_t	ft_pow_10(int n)
{
	int i;
	int64_t num;

	num = 1;
	i = 0;
	while (i < n)
	{
		num *= 10;
		i++;
	}
	return (num);
}

uintmax_t	ft_pow_10_u(int n)
{
	int i;
	int64_t num;

	num = 1;
	i = 0;
	while (i < n)
	{
		num *= 10;
		i++;
	}
	return (num);
}

int 	ft_is_flag(char c)
{
	if (ft_strchr("#0+- ", c) != NULL)
		return (1);
	return (0);
}

int 	ft_is_size(char c)
{
	if ((c == 'l') || (*(&c + 1) && c == 'l' && *(&c + 1) == 'l') || (c == 'h') || (*(&c + 1) && c == 'h' && *(&c + 1) == 'h') || (c == 'L'))
		return (1);
	return (0);
}
