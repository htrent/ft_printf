/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:56:54 by htrent            #+#    #+#             */
/*   Updated: 2020/02/12 20:44:00 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				put_data_b(t_printf *data, int *k, uintmax_t num)
{
	char	*s;
	char	*str;
	int		n;
	int		digits;

	s = ft_utoa_base(num, 2);
	digits = ft_strlen(s);
	n = (data->precision > digits) ? data->precision : digits;
	if ((data->flags >> TO_SHARP == 1) % 2)
		n += 2;
	str = ft_strnew((n > data->width) ? n : data->width);
	data->count_char += (n > data->width) ? n : data->width;
	str = ((data->flags >> TO_MINUS) % 2) ? ft_fillbegin_b(data, str, s)
			: ft_fillend_b(data, str, s);
	if (data->format[*k] == 'B')
		str = ft_str_to_upper(str);
	(*k)++;
	ft_putstr_buf(str, data->buf, data);
	free(s);
	return (0);
}

char			*ft_fillbegin_b(t_printf *data, char *str, char *num)
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
	check_sharp_b(data, str, &i);
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

char			*ft_fillend_b(t_printf *data, char *str, char *num)
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
	check_sharp_b(data, str, &i);
	if ((data->flags >> TO_ZERO) % 2 && data->precision == NO_PRECISION)
		fill_zeros(&width, max, &i, str);
	fill_zeros(&prec, digits, &i, str);
	while (*num)
		str[i++] = *(num++);
	return (str);
}
