/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/02 14:49:25 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_data_p(t_printf *data, int *k)
{
	uintmax_t num;
	char *s;
	char *str;
	int max;
	int digits;
	int i;
	int prec;
	int width;
	int n;

	num = (unsigned long long)va_arg(data->params, unsigned long long);
	prec = data->precision;
	width = data->width;
	s = ft_utoa_base_p(num, 16, data);
	digits = ft_strlen(s);
	n = (digits > data->precision) ? digits : data->precision;
	n += 2;
	max = (n > data->width) ? n : data->width;
	str = ft_strnew(max);
	data->count_char += max;
	i = 0;
	if ((data->flags >> TO_MINUS) % 2)
	{
		str[i++] = '0';
		str[i++] = 'x';
		while (*s)
		{
			str[i++] = *s;
			s++;
		}
		while (prec > digits)
		{
			str[i++] = '0';
			prec--;
		}
		while (width > n)
		{
			str[i++] = ' ';
			width--;
		}

	}
	else
	{
		while (width > n)
		{
			str[i++] = ' ';
			width--;
		}
		str[i++] = '0';
		str[i++] = 'x';
		while (prec > digits)
		{
			str[i++] = '0';
			prec--;
		}
		while (*s)
		{
			str[i++] = *s;
			s++;
		}
	}
	(*k)++;
	ft_putstr(str);
	free(str);
	//free(s);
	return (0);
}

