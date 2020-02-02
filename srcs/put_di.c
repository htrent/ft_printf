/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/02 12:44:26 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	put_data_di(t_printf *data, int *k)
{
	int64_t num;
	char *s;
	int n;
	int digits;

	if (data->size == L_SIZE)
		num = (long int)va_arg(data->params, long int);
	else if (data->size == H_SIZE)
		num = (short)va_arg(data->params, int);
	else if (data->size == LL_SIZE)
		num = (long long)va_arg(data->params, long long);
	else if (data->size == HH_SIZE)
		num = (char)va_arg(data->params, int);
	else
	num = (int)va_arg(data->params, int);
	digits = ft_count_of_digits(num);
	n = (digits > data->precision) ? digits : data->precision;
	if ((data->flags >> TO_SPACE) % 2 || (data->flags >> TO_PLUS) % 2 || num < 0)
		n++;
	n = (n > data->width) ? n : data->width;
	data->count_char += n;
	s = ft_strnew(n);
	if ((data->flags >> TO_MINUS) % 2)
		ft_fillbegin(data, num, s, digits);
	else
		ft_fillend(data, num, s, digits);
	(*k)++;
	return (0);
}

void	ft_fillbegin(t_printf *data, int64_t num, char *s, int digits)
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
	if ((data->flags >> TO_SPACE) % 2 && num >= 0 && (i = 1))
		s[0] = ' ';
	if ((data->flags >> TO_PLUS) % 2 && num >= 0 && (i = 1))
		s[0] = '+';
	if (num < 0 && (i = 1) && (num *= -1) && (max++))
		s[0] = '-';
	while (prec > digits)
	{
		s[i++] = '0';
		prec--;
	}
	while (dig > 0)
	{
		s[i++] = (num % ft_pow_10(dig)) / ft_pow_10(dig - 1) + '0';
		dig--;
	}
	j = ((data->flags >> TO_PLUS) % 2 == 1 || (data->flags >> TO_SPACE) % 2 == 1 || num < 0) ? 1 : 0;
	while (j < data->width - max)
	{
		s[i++] = ' ';
		j++;
	}
	ft_putstr(s);
	free(s);
}

void	ft_fillend(t_printf *data, int64_t num, char *s, int digits)
{
	int i;
	int j;
	int dig;
	int prec;
	int max;
	int width;

	width = data->width;
	prec = data->precision;
	dig = digits;
	max = (digits > data->precision) ? digits : data->precision;
	max += ((data->flags >> TO_SPACE) % 2 || (data->flags >> TO_PLUS) % 2 || num < 0) ? 1 : 0;
	i = 0;
	if (data->precision != NO_PRECISION || (data->flags >> TO_ZERO) % 2 == 0)
		while (width > max)
		{
			s[i++] = ' ';
			width--;
		}
	if ((data->flags >> TO_ZERO) % 2 == 0)
	{
		//while (width > max)
		//{
		//	s[i++] = ' ';
		//	width--;
		//}
		if ((data->flags >> TO_SPACE) % 2 && num >= 0)
			s[i] = ' ';
		if ((data->flags >> TO_PLUS) % 2 && num >= 0)
			s[i] = '+';
		if (num < 0)
			s[i] = '-';
		if ((data->flags >> TO_PLUS) % 2 || (data->flags >> TO_SPACE) % 2 || (num < 0))
			i++;
	}
	else
	{
		if ((data->flags >> TO_SPACE) % 2 && num >= 0)
			s[i] = ' ';
		if ((data->flags >> TO_PLUS) % 2 && num >= 0)
			s[i] = '+';
		if (num < 0)
			s[i] = '-';
		if ((((data->flags >> TO_PLUS) % 2 ||(data->flags >> TO_SPACE) % 2) && num >= 0) || (num < 0))
			i++;
		while (width > max)
		{
			s[i++] = '0';
			width--;
		}
	}
	if (num < 0)
		num *= -1;
	while (prec > dig)
	{
		s[i++] = '0';
		prec--;
	}
	j = ((data->flags >> TO_PLUS) % 2 || (data->flags >> TO_SPACE) % 2 || num < 0) ? 1 : 0;
	while (dig > 0)
	{
		s[i++] = (dig == 19) ? (num / ft_pow_10(dig - 1) + '0') : ((num % ft_pow_10(dig)) / ft_pow_10(dig - 1) + '0');
		dig--;
	}
	ft_putstr(s);
	free(s);
}
