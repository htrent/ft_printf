/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:53:46 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 16:53:14 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		init_size_di(t_printf *data)
{
	intmax_t	num;

	if (data->size == L_SIZE)
		num = (long int)va_arg(data->params, long int);
	else if (data->size == H_SIZE)
		num = (short)va_arg(data->params, int);
	else if (data->size == LL_SIZE)
		num = (long long)va_arg(data->params, long long);
	else if (data->size == HH_SIZE)
		num = (char)va_arg(data->params, int);
	else if (data->size == J_SIZE)
		num = (intmax_t)va_arg(data->params, intmax_t);
	else if (data->size == Z_SIZE)
		num = (size_t)va_arg(data->params, size_t);
	else
		num = (int)va_arg(data->params, int);
	return (num);
}

int				put_data_di(t_printf *data, int *k)
{
	intmax_t	num;
	char		*s;
	int			n;
	int			digits;

	num = init_size_di(data);
	if (num == LONG_MIN || num == LLONG_MIN)
		return (edge_di(data, k));
	digits = ft_count_of_digits(num);
	if (data->precision == 0 && num == 0)
		digits = 0;
	n = (digits > data->precision) ? digits : data->precision;
	if ((((data->flags >> TO_SPACE) % 2 || (data->flags >> TO_PLUS) % 2)
		&& num >= 0) || num < 0)
		n++;
	n = (n > data->width) ? n : data->width;
	data->count_char += n;
	if (!(s = ft_strnew(n)))
		return (1);
	((data->flags >> TO_MINUS) % 2) ? ft_fillbegin(data, num, s, digits)
	: ft_fillend(data, num, s, digits);
	(*k)++;
	return (0);
}

void			ft_fillbegin(t_printf *data, intmax_t num, char *s, int digits)
{
	int i;
	int j;
	int prec;
	int max;
	int	sign;

	prec = data->precision;
	max = (digits > data->precision) ? digits : data->precision;
	i = 0;
	sign = first_init_begin(data, &num, &i, s);
	fill_zeros(&prec, digits, &i, s);
	if (!(data->precision == 0 && num == 0))
		ft_itoa_di(s, digits, num, &i);
	j = ((((data->flags >> TO_PLUS) % 2 || (data->flags >> TO_SPACE) % 2)
			&& (sign == 1)) || (sign == -1)) ? 1 : 0;
	while (j++ < data->width - max)
		s[i++] = ' ';
	ft_putstr_buf(s, data->buf, data);
}

void			ft_fillend(t_printf *data, intmax_t num, char *s, int digits)
{
	int i;
	int j;
	int prec;
	int max;
	int width;

	width = data->width;
	prec = data->precision;
	max = (digits > data->precision) ? digits : data->precision;
	max += ((data->flags >> TO_SPACE) % 2 ||
			(data->flags >> TO_PLUS) % 2 || num < 0) ? 1 : 0;
	i = 0;
	if (data->precision != NO_PRECISION || (data->flags >> TO_ZERO) % 2 == 0)
		while (width-- > max)
			s[i++] = ' ';
	first_init_end(data, &num, &i, s);
	if ((data->flags >> TO_ZERO) % 2)
		fill_zeros(&width, max, &i, s);
	fill_zeros(&prec, digits, &i, s);
	j = ((data->flags >> TO_PLUS) % 2 ||
			(data->flags >> TO_SPACE) % 2 || num < 0) ? 1 : 0;
	if (!(data->precision == 0 && num == 0))
		ft_itoa_di(s, digits, num, &i);
	ft_putstr_buf(s, data->buf, data);
}
