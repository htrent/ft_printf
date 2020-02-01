/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/01 13:18:25 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_max_digits(uint64_t num, int base)
{
	int max_digits;

	max_digits = 0;
	while (num)
	{
		num /= base;
		max_digits++;
	}
	return (max_digits);
}

char *ft_utoa_base(uint64_t num, int base)
{
	int max_digits;
	char *str;
	char *radix;
	int i;

	radix = "0123456789abcdef";
	max_digits = ft_max_digits(num, base);
	str = ft_strnew(max_digits);
	i = max_digits - 1;
	while (i >= 0)
	{
		str[i] = radix[num % base];
		num /= base;
		i--;
	}
	return (str);
}

