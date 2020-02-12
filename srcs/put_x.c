/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:54:22 by htrent            #+#    #+#             */
/*   Updated: 2020/02/12 20:44:00 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		init_size_oux(t_printf *data)
{
	uintmax_t	num;

	if (data->size == L_SIZE)
		num = (unsigned long int)va_arg(data->params, unsigned long int);
	else if (data->size == H_SIZE)
		num = (unsigned short)va_arg(data->params, unsigned int);
	else if (data->size == LL_SIZE)
		num = (unsigned long long)va_arg(data->params, unsigned long long);
	else if (data->size == HH_SIZE)
		num = (unsigned char)va_arg(data->params, unsigned int);
	else if (data->size == J_SIZE)
		num = (uintmax_t)va_arg(data->params, uintmax_t);
	else if (data->size == Z_SIZE)
		num = (size_t)va_arg(data->params, size_t);
	else
		num = (unsigned int)va_arg(data->params, unsigned int);
	return (num);
}

int				put_data_ouxb(t_printf *data, int *k)
{
	uintmax_t	num;
	char		*s;
	char		*str;
	int			n;
	int			digits;

	num = init_size_oux(data);
	if (ft_strchr("ouUbB", data->format[*k]) || num == 0)
		return (parse_args(data, k, num));
	s = ft_utoa_base(num, 16);
	digits = ft_strlen(s);
	n = (data->precision > digits) ? data->precision : digits;
	if ((data->flags >> TO_SHARP == 1) % 2)
		n += 2;
	str = ft_strnew((n > data->width) ? n : data->width);
	data->count_char += (n > data->width) ? n : data->width;
	str = ((data->flags >> TO_MINUS) % 2) ? ft_fillbegin_x(data, str, s)
			: ft_fillend_x(data, str, s);
	if (data->format[*k] == 'X')
		str = ft_str_to_upper(str);
	(*k)++;
	ft_putstr_buf(str, data->buf, data);
	free(s);
	return (0);
}

char			*ft_fillbegin_x(t_printf *data, char *str, char *num)
{
	int	i;
	int prec;
	int width;
	int max;
	int digits;

	digits = ft_strlen(num);
	width = data->width;
	prec = data->precision;
	i = 0;
	check_sharp(data, str, &i);
	fill_zeros(&prec, digits, &i, str);
	while (*num)
		str[i++] = *(num++);
	max = (digits > data->precision) ? digits : data->precision;
	if ((data->flags >> TO_SHARP) % 2)
		max += 2;
	while (width-- > max)
		str[i++] = ' ';
	return (str);
}

char			*ft_fillend_x(t_printf *data, char *str, char *num)
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
	max = (digits > data->precision) ? digits : data->precision;
	if ((data->flags >> TO_SHARP) % 2)
		max += 2;
	if ((data->flags >> TO_ZERO) % 2 == 0 ||
	((data->flags >> TO_ZERO) % 2 && data->precision != NO_PRECISION))
		while (width-- > max)
			str[i++] = ' ';
	check_sharp(data, str, &i);
	if ((data->flags >> TO_ZERO) % 2 && data->precision == NO_PRECISION)
		fill_zeros(&width, max, &i, str);
	fill_zeros(&prec, digits, &i, str);
	while (*num)
		str[i++] = *(num++);
	return (str);
}

int				put_data_zero(t_printf *data, int *k)
{
	int width;
	int prec;
	int max;

	prec = data->precision;
	width = data->width;
	if (data->precision != NO_PRECISION)
	{
		if ((data->flags >> TO_MINUS) % 2)
			action1_x(data, &prec, &width, 1);
		else
			action1_x(data, &prec, &width, 0);
		max = (data->precision > data->width) ? data->precision : data->width;
		data->count_char += max;
	}
	else
		help_x_noprec(data);
	(*k)++;
	return (0);
}
