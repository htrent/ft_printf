/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils_xX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:07:28 by htrent            #+#    #+#             */
/*   Updated: 2020/02/08 16:59:29 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	action2_x(t_printf *data, int *width, int key)
{
	if (key)
		ft_putchar_buf('0', data->buf, data);
	else
	{
		if ((data->flags >> TO_ZERO) % 2)
			while ((*width)-- > 1)
				ft_putchar_buf('0', data->buf, data);
		else
			while ((*width)-- > 1)
				ft_putchar_buf(' ', data->buf, data);
	}
	if (key)
		while ((*width)-- > 1)
			ft_putchar_buf(' ', data->buf, data);
	else
		ft_putchar_buf('0', data->buf, data);
}

void	help_x_noprec(t_printf *data)
{
	int max;
	int width;

	width = data->width;
	if ((data->flags >> TO_MINUS) % 2)
		action2_x(data, &width, 1);
	else
		action2_x(data, &width, 0);
	max = (data->precision > data->width) ? data->precision : data->width;
	if ((data->flags >> TO_SHARP) % 2 &&
	data->precision == NO_PRECISION && data->width == 0)
		max = 1;
	data->count_char += (data->width != 0) ? max : 1;
}

void	action1_x(t_printf *data, int *prec, int *width, int key)
{
	if (key)
		while ((*prec)-- > 0)
			ft_putchar_buf('0', data->buf, data);
	else
		while ((*width)-- > data->precision)
			ft_putchar_buf(' ', data->buf, data);
	if (key)
		while ((*width)-- > data->precision)
			ft_putchar_buf(' ', data->buf, data);
	else
		while ((*prec)-- > 0)
			ft_putchar_buf('0', data->buf, data);
}

void	check_sharp(t_printf *data, char *str, int *i)
{
	if ((data->flags >> TO_SHARP) % 2)
	{
		str[(*i)++] = '0';
		str[(*i)++] = 'x';
	}
}

int		parse_args(t_printf *data, int *k, uintmax_t num)
{
	if (data->format[*k] == 'u' || data->format[*k] == 'U')
		return (put_data_u(data, k, num));
	if (data->format[*k] == 'o')
		return (put_data_o(data, k, num));
	if (data->format[*k] == 'b' || data->format[*k] == 'B')
		return (put_data_b(data, k, num));
	return (put_data_zero(data, k));
}
