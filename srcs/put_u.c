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

int		put_data_u(t_printf *data, int *k, uintmax_t num)
{
	int		digits;
	char	*s;
	int		n;

	digits = ft_count_of_digits_u(num);
	if (data->precision == 0 && num == 0)
		digits = 0;
	n = (digits > data->precision) ? digits : data->precision;
	n = (n > data->width) ? n : data->width;
	data->count_char += n;
	s = ft_strnew(n);
	if ((data->flags >> TO_MINUS) % 2)
		ft_fillbegin_u(data, num, s, digits);
	else
		ft_fillend_u(data, num, s, digits);
	(*k)++;
	return (0);
}

void	ft_fillbegin_u(t_printf *data, uintmax_t num, char *s, int digits)
{
	int i;
	int j;
	int dig;
	int prec;
	int max;

	prec = data->precision;
	dig = digits;
	max = (digits > data->precision) ? digits : data->precision;
	i = 0;
	fill_zeros(&prec, digits, &i, s);
	if (!(data->precision == 0 && num == 0))
		while (dig > 0)
		{
			s[i++] = (dig >= 20) ? (num / ft_pow_10_u(dig - 1) + '0')
					: ((num % ft_pow_10_u(dig)) / ft_pow_10_u(dig - 1) + '0');
			dig--;
		}
	j = 0;
	while (j++ < data->width - max)
		s[i++] = ' ';
	ft_putstr_buf(s, data->buf, data);
}

void	ft_fillend_u(t_printf *data, intmax_t num, char *s, int dig)
{
	int i;
	int prec;
	int max;
	int width;

	width = data->width;
	prec = data->precision;
	max = (dig > data->precision) ? dig : data->precision;
	i = 0;
	if (data->precision != NO_PRECISION || (data->flags >> TO_ZERO) % 2 == 0)
		while (width-- > max)
			s[i++] = ' ';
	if ((data->flags >> TO_ZERO) % 2)
		fill_zeros(&width, max, &i, s);
	fill_zeros(&prec, dig, &i, s);
	if (!(data->precision == 0 && num == 0))
		while (dig > 0)
		{
			s[i++] = (dig >= 20) ? (num / ft_pow_10_u(dig - 1) + '0')
					: ((num % ft_pow_10_u(dig)) / ft_pow_10_u(dig - 1) + '0');
			dig--;
		}
	ft_putstr_buf(s, data->buf, data);
}
