/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:54:14 by htrent            #+#    #+#             */
/*   Updated: 2020/02/07 20:18:54 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_data_o(t_printf *data, int *k, uintmax_t num)
{
	char	*s;
	char	*str;
	int		n;
	int		max;
	int		digits;

	if (num == 0)
		return (put_data_zero_o(data, k));
	s = ft_utoa_base(num, 8);
	digits = ft_strlen(s);
	if ((data->flags >> TO_SHARP) % 2)
		digits++;
	n = (data->precision > digits) ? data->precision : digits;
	max = (n > data->width) ? n : data->width;
	str = ft_strnew(max);
	data->count_char += max;
	str = ((data->flags >> TO_MINUS) % 2) ? ft_fillbegin_o(data, str, s)
			: ft_fillend_o(data, str, s);
	(*k)++;
	ft_putstr_buf(str, data->buf);
	free(str);
	free(s);
	return (0);
}

char		*ft_fillbegin_o(t_printf *data, char *str, char *num)
{
	int i;
	int prec;
	int width;
	int max;
	int digits;

	digits = ft_strlen(num);
	width = data->width;
	prec = data->precision;
	i = 0;
	if ((data->flags >> TO_SHARP) % 2
	&& *num != '0' && (data->precision <= digits))
		str[i++] = '0';
	fill_zeros(&prec, digits, &i, str);
	while (*num)
		str[i++] = *(num++);
	max = (digits > data->precision) ? digits : data->precision;
	if ((data->flags >> TO_SHARP) % 2 && (data->precision <= digits))
		max += 1;
	while (width-- > max)
		str[i++] = ' ';
	return (str);
}

char		*ft_fillend_o(t_printf *data, char *str, char *num)
{
	int i;
	int prec;
	int width;
	int max;
	int digits;

	digits = ft_strlen(num);
	width = data->width;
	prec = data->precision;
	if ((data->flags >> TO_SHARP) % 2 && prec < digits)
		digits++;
	i = 0;
	max = (digits > data->precision) ? digits : data->precision;
	if (((data->flags >> TO_ZERO) % 2) && (data->precision == NO_PRECISION))
		fill_zeros(&width, max, &i, str);
	else
		while (width-- > max)
			str[i++] = ' ';
	if ((data->flags >> TO_SHARP) % 2 && (data->precision <= digits))
		str[i++] = '0';
	((data->flags >> TO_ZERO) % 2 && data->precision == NO_PRECISION)
	? fill_zeros(&width, max, &i, str) : fill_zeros(&prec, digits, &i, str);
	while (*num)
		str[i++] = *(num++);
	return (str);
}

int			put_data_zero_o(t_printf *data, int *k)
{
	int width;
	int prec;

	prec = data->precision;
	width = data->width;
	if (data->precision != NO_PRECISION)
	{
		if ((data->flags >> TO_SHARP) % 2 && data->precision == 0
		&& data->width != 0 && (prec = 1))
			data->precision = 1;
		((data->flags >> TO_MINUS) % 2) ? action1_x(data, &prec, &width, 1)
		: action1_x(data, &prec, &width, 0);
		data->count_char += (data->precision > data->width)
				? data->precision : data->width;
		if ((data->flags >> TO_SHARP) % 2 && data->precision == 0
		&& data->width == 0 && (data->count_char++))
			ft_putchar_buf('0', data->buf);
	}
	else
		help_x_noprec(data);
	(*k)++;
	return (0);
}
