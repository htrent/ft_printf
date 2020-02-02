/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/02 17:13:46 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	put_data_ouxX(t_printf *data, int *k)
{
	uintmax_t num;
	char *s;
	char *str;
	int n;
	int max;
	int digits;

	if (data->size == L_SIZE)
		num = (unsigned long int) va_arg(data->params, unsigned long int);
	else if (data->size == H_SIZE)
		num = (unsigned short) va_arg(data->params, unsigned int);
	else if (data->size == LL_SIZE)
		num = (unsigned long long) va_arg(data->params, unsigned long long);
	else if (data->size == HH_SIZE)
		num = (unsigned char) va_arg(data->params, unsigned int);
	else
		num = (unsigned int) va_arg(data->params, unsigned int);

	if (data->format[*k] == 'u')
		return (put_data_u(data, k, num));
	if (data->format[*k] == 'o')
		return (put_data_o(data, k, num));
	if (num == 0)
		return (put_data_zero(data, k));
	s = ft_utoa_base(num, 16);
	digits = ft_strlen(s);
	n = (data->precision > digits) ? data->precision : digits;
	if ((data->flags >> TO_SHARP == 1) % 2)
		n += 2;
	max = (n > data->width) ? n : data->width;
	str = ft_strnew(max);
	data->count_char += max;
	if ((data->flags >> TO_MINUS) % 2)
		str = ft_fillbegin_xX(data, str, s);
	else
		str = ft_fillend_xX(data, str, s);
	if (data->format[*k] == 'X')
		str = ft_str_to_upper(str);
	(*k)++;
	ft_putstr(str);
	free(str);
	free(s);
	return (0);
}

char 	*ft_fillbegin_xX(t_printf *data, char *str, char *num)
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
	if ((data->flags >> TO_SHARP) % 2)
	{
		str[i++] = '0';
		str[i++] = 'x';
	}
	while (prec-- > digits)
		str[i++] = '0';
	while (*num)
	{
		str[i++] = *num;
		num++;
	}
	max = (digits > data->precision) ? digits : data->precision;
	if ((data->flags >> TO_SHARP) % 2)
		max += 2;
	while (width > max)
	{
		str[i++] = ' ';
		width--;
	}
	return (str);
}

char 	*ft_fillend_xX(t_printf *data, char *str, char *num)
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
	if ((data->flags >> TO_SHARP) % 2)
		max += 2;
	if ((data->flags >> TO_ZERO) % 2 == 0)
		while (width-- > max)
			str[i++] = ' ';
	//2 блок
	if ((data->flags >> TO_SHARP) % 2)
	{
		str[i++] = '0';
		str[i++] = 'x';
	}
	if ((data->flags >> TO_ZERO) % 2)
		while (width-- > max)
			str[i++] = '0';
	while (prec-- > digits)
		str[i++] = '0';
	while (*num)
	{
		str[i++] = *num;
		num++;
	}
	return (str);
}

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
}

//flfjflfa
