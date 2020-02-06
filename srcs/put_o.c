/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:54:14 by htrent            #+#    #+#             */
/*   Updated: 2020/02/06 13:39:51 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int 	put_data_o(t_printf *data, int *k, uintmax_t num)
{
	char *s;
	char *str;
	int n;
	int max;
	int digits;

	s = ft_utoa_base(num, 8);
	digits = ft_strlen(s);
	if ((data->flags >> TO_SHARP) % 2)
		digits++;
	n = (data->precision > digits) ? data->precision : digits;
	//if ((data->flags >> TO_SHARP == 1) % 2 && (data->precision <= digits))
	//	n += 1;
	max = (n > data->width) ? n : data->width;
	str = ft_strnew(max);
	data->count_char += max;
	str = ((data->flags >> TO_MINUS) % 2) ? ft_fillbegin_o(data, str, s) : ft_fillend_o(data, str, s);
	(*k)++;
	ft_putstr_buf(str, data->buf);
	free(str);
	free(s);
	return (0);
}

char 	*ft_fillbegin_o(t_printf *data, char *str, char *num)
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
	if ((data->flags >> TO_SHARP) % 2 && *num != '0' && (data->precision <= digits))
		str[i++] = '0';
	while (prec-- > digits)
		str[i++] = '0';
	while (*num)
	{
		str[i++] = *num;
		num++;
	}
	max = (digits > data->precision) ? digits : data->precision;
	if ((data->flags >> TO_SHARP) % 2 && (data->precision <= digits))
		max += 1;
	while (width > max)
	{
		str[i++] = ' ';
		width--;
	}
	return (str);
}

char 	*ft_fillend_o(t_printf *data, char *str, char *num)
{
	int i;
	int prec;
	int width;
	int max;
	int digits;

	/*
	 * раздели блок 1 и блок 2 на подфункции, в fillbegin они просто поменялись местами!!!!!!!
	 */
	digits = ft_strlen(num);
	width = data->width;
	prec = data->precision;
	i = 0;
	//1 блок
	max = (digits > data->precision) ? digits : data->precision;
	//if ((data->flags >> TO_SHARP) % 2)
	//	max += 1;
	if (((data->flags >> TO_ZERO) % 2) && (data->precision == NO_PRECISION))
		while (width-- > max)
			str[i++] = '0';
	else
		while (width-- > max)
			str[i++] = ' ';
	//2 блок
	if ((data->flags >> TO_SHARP) % 2 && *num != '0' && (data->precision <= digits))
		str[i++] = '0';
	if ((data->flags >> TO_ZERO) % 2 && data->precision == NO_PRECISION)
		while (width-- > max)
			str[i++] = '0';
	else
		while (prec-- > digits)
			str[i++] = '0';
	while (*num)
	{
		str[i++] = *num;
		num++;
	}
	return (str);
}
/*
int 	put_data_zero(t_printf *data, int *k)
{
	int width;
	int prec;
	int max;
	prec = data->precision;
	width = data->width;
	if (data->precision != NO_PRECISION)
	{
		if ((data->flags >> TO_MINUS) % 2)
		{
			while (prec-- > 0)
				ft_putchar('0');
			while (width-- > data->precision)
				ft_putchar(' ');
		}
		else
		{
			while (width-- > data->precision)
				ft_putchar(' ');
			while (prec-- > 0)
				ft_putchar('0');
		}
		max = (data->precision > data->width) ? data->precision : data->width;
		if (data->width != 0)
			data->count_char += max;
		else if (data->format[*k] == 'o' && (data->flags >> TO_SHARP) % 2)
		{
			ft_putchar('0');
			data->count_char++;
		}
	}
	else
	{
		if ((data->flags >> TO_MINUS) % 2)
		{
			ft_putchar('0');
			while (width-- > 1)
				ft_putchar(' ');
		}
		else
		{
			while (width-- > 1)
				ft_putchar(' ');
			ft_putchar('0');
		}
		max = (data->precision > data->width) ? data->precision : data->width;
		if ((data->flags >> TO_SHARP) % 2 && data->precision == NO_PRECISION && data->width == 0)
			max = 1;
		if (data->width != 0)
			data->count_char += max;
		else
			data->count_char++;
	}
	(*k)++;
	return (0);
}*/