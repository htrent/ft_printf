/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:57:09 by htrent            #+#    #+#             */
/*   Updated: 2020/02/08 15:57:09 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_pow_10(int n)
{
	int		i;
	int64_t	num;

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
	int		i;
	int64_t	num;

	num = 1;
	i = 0;
	while (i < n)
	{
		num *= 10;
		i++;
	}
	return (num);
}
