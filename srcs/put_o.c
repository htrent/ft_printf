/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:54:14 by htrent            #+#    #+#             */
/*   Updated: 2020/02/12 20:44:00 by htrent           ###   ########.fr       */
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
	if (!(s = ft_utoa_base(num, 8)))
		return (1);
	digits = ft_strlen(s);
	if ((data->flags >> TO_SHARP) % 2)
		digits++;
	n = (data->precision > digits) ? data->precision : digits;
	max = (n > data->width) ? n : data->width;
	if (!(str = ft_strnew(max)) && ft_memdel((void**)&s))
		return (1);
	data->count_char += max;
	str = ((data->flags >> TO_MINUS) % 2) ? ft_fillbegin_o(data, str, s)
			: ft_fillend_o(data, str, s);
	(*k)++;
	ft_putstr_buf(str, data->buf, data);
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
	if ((data->flags >> TO_SHARP) % 2 && *num != '0'
	&& (data->precision <= digits))
		str[i++] = '0';
	fill_zeros(&prec, digits, &i, str);
	while (*num)
		str[i++] = *(num++);
	max = (digits > data->precision) ? digits : data->precision;
	max += ((data->flags >> TO_SHARP) % 2
			&& (data->precision <= digits)) ? 1 : 0;
	fill_spaces(&width, max, &i, str);
	return (str);
}

char		*ft_fillend_o(t_printf *data, char *str, char *num)
{
	int i;
	int prec;
	int width;
	int max;
	int digits;

	if (!(digits = ft_strlen(num)))
		return (NULL);
	width = data->width;
	prec = data->precision;
	if ((data->flags >> TO_SHARP) % 2 && prec < digits)
		digits++;
	i = 0;
	max = (digits > data->precision) ? digits : data->precision;
	(((data->flags >> TO_ZERO) % 2) && (data->precision == NO_PRECISION))
	? fill_zeros(&width, max, &i, str) : fill_spaces(&width, max, &i, str);
	if ((data->flags >> TO_SHARP) % 2 && (data->precision <= digits))
		str[i++] = '0';
	((data->flags >> TO_ZERO) % 2 && data->precision == NO_PRECISION) ?
	fill_zeros(&width, max, &i, str) : fill_zeros(&prec, digits, &i, str);
	while (*num)
		str[i++] = *(num++);
	return (str);
}

int			put_data_zero_o_prec(t_printf *data, int *k)
{
	int width;
	int prec;

	prec = data->precision;
	width = data->width;
	if ((data->flags >> TO_SHARP) % 2 && data->precision == 0
	&& data->width != 0 && (prec = 1))
		data->precision = 1;
	help_o_prec(data, &prec, &width);
	data->count_char += (data->precision > data->width) ?
			data->precision : data->width;
	if (data->format[*k] == 'o' && (data->flags >> TO_SHARP) % 2
	&& data->precision == 0 && data->width == 0)
	{
		ft_putchar_buf('0', data->buf, data);
		data->count_char++;
	}
	(*k)++;
	return (0);
}

int			put_data_zero_o(t_printf *data, int *k)
{
	int width;
	int prec;
	int max;

	prec = data->precision;
	width = data->width;
	if (data->precision != NO_PRECISION)
		return (put_data_zero_o_prec(data, k));
	help_o_no_prec(data, &width);
	max = (data->precision > data->width) ? data->precision : data->width;
	if ((data->flags >> TO_SHARP) % 2 && data->precision == NO_PRECISION
	&& data->width == 0)
		max = 1;
	data->count_char += (data->width != 0) ? max : 1;
	(*k)++;
	return (0);
}
