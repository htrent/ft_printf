/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/12 20:44:00 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_max_digits(uintmax_t num, int base)
{
	int max_digits;

	max_digits = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		max_digits++;
	}
	return (max_digits);
}

char		*ft_utoa_base(uintmax_t num, int base)
{
	int		max_digits;
	char	*str;
	char	*radix;
	int		i;

	radix = "0123456789abcdef";
	max_digits = ft_max_digits(num, base);
	if (!(str = ft_strnew(max_digits)))
		return (NULL);
	i = max_digits - 1;
	while (i >= 0)
	{
		str[i] = radix[num % base];
		num /= base;
		i--;
	}
	return (str);
}

char		*ft_utoa_base_p(uintmax_t num, int base, t_printf *data)
{
	int		max_digits;
	char	*str;
	char	*radix;
	int		i;

	radix = "0123456789abcdef";
	max_digits = (data->precision == 0 && num == 0)
			? 0 : ft_max_digits(num, base);
	if (!(str = ft_strnew(max_digits)))
		return (NULL);
	i = max_digits - 1;
	while (i >= 0)
	{
		str[i] = radix[num % base];
		num /= base;
		i--;
	}
	return (str);
}
