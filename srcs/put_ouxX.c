/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/02 15:08:32 by htrent           ###   ########.fr       */
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
		num = (unsigned long int)va_arg(data->params, unsigned long int);
	else if (data->size == H_SIZE)
		num = (unsigned short)va_arg(data->params, unsigned int);
	else if (data->size == LL_SIZE)
		num = (unsigned long long)va_arg(data->params, unsigned long long);
	else if (data->size == HH_SIZE)
		num = (unsigned char)va_arg(data->params, unsigned int);
	else
		num = (unsigned int)va_arg(data->params, unsigned int);

	if (data->format[*k] == 'u')
		return (put_data_u(data, k, num));
	if (num == 0)
		return (put_data_zero(data, k));
	if (data->format[*k] == 'o')
		s = ft_utoa_base(num, 8);
	if (data->format[*k] == 'x' || data->format[*k] == 'X')
		s = ft_utoa_base(num, 16);
	digits = ft_strlen(s);
	n = (data->precision > digits) ? data->precision : digits;
	if ((data->flags >> TO_SHARP == 1) % 2 && (data->format[*k] == 'x' || data->format[*k] == 'X'))
		n += 2;
	if ((data->flags >> TO_SHARP == 1) % 2 && data->format[*k] == 'o')
		n += 1;
	max = (n > data->width) ? n : data->width;
	str = ft_strnew(max);
	data->count_char += max;
	if ((data->flags >> TO_MINUS) % 2)
		str = ft_fillbegin_oxX(data, str, s, k);
	else
		str = ft_fillend_oxX(data, str, s, k);
	if (data->format[*k] == 'X')
		str = ft_str_to_upper(str);
	(*k)++;
	ft_putstr(str);
	free(str);
	free(s);
	return (0);
}

int		put_data_u(t_printf *data, int *k, uintmax_t num)
{
	int digits;
	char *s;
	int n;

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
	while (prec > digits)
	{
		s[i++] = '0';
		prec--;
	}
	if (!(data->precision == 0 && num == 0))
		while (dig > 0)
		{
			s[i++] = (dig >= 20) ? (num / ft_pow_10_u(dig - 1) + '0') : ((num % ft_pow_10_u(dig)) / ft_pow_10_u(dig - 1) + '0');
			dig--;
		}
	j = 0;
	while (j < data->width - max)
	{
		s[i++] = ' ';
		j++;
	}
	ft_putstr(s);
	free(s);
}

void	ft_fillend_u(t_printf *data, intmax_t num, char *s, int digits)
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
	i = 0;
	if (data->precision != NO_PRECISION || (data->flags >> TO_ZERO) % 2 == 0)
		while (width > max)
		{
			s[i++] = ' ';
			width--;
		}
	if ((data->flags >> TO_ZERO) % 2)
	{
		while (width > max)
		{
			s[i++] = '0';
			width--;
		}
	}
	while (prec > dig)
	{
		s[i++] = '0';
		prec--;
	}
	j = 0;
	if (!(data->precision == 0 && num == 0))
		while (dig > 0)
		{
			s[i++] = (dig >= 20) ? (num / ft_pow_10_u(dig - 1) + '0') : ((num % ft_pow_10_u(dig)) / ft_pow_10_u(dig - 1) + '0');
			dig--;
		}
	ft_putstr(s);
	free(s);
}

char 	*ft_fillbegin_oxX(t_printf *data, char *str, char *num, int *k)
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
	if ((data->flags >> TO_SHARP) % 2 && *num != '0')
		str[i++] = '0';
	if ((data->flags >> TO_SHARP) % 2 && (data->format[*k] == 'x' || data->format[*k] == 'X'))
		str[i++] = 'x';
	while (prec-- > digits)
		str[i++] = '0';
	while (*num)
	{
		str[i++] = *num;
		num++;
	}
	max = (digits > data->precision) ? digits : data->precision;
	if ((data->flags >> TO_SHARP) % 2 && (data->format[*k] == 'x' || data->format[*k] == 'X'))
		max += 2;
	if ((data->flags >> TO_SHARP) % 2 && data->format[*k] == 'o')
		max += 1;
	while (width > max)
	{
		str[i++] = ' ';
		width--;
	}
	return (str);
}

char 	*ft_fillend_oxX(t_printf *data, char *str, char *num, int *k)
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
	if ((data->flags >> TO_SHARP) % 2 && (data->format[*k] == 'x' || data->format[*k] == 'X'))
		max += 2;
	if ((data->flags >> TO_SHARP) % 2 && data->format[*k] == 'o')
		max += 1;
	if ((data->flags >> TO_ZERO) % 2 == 0)
		while (width-- > max)
			str[i++] = ' ';
	//2 блок
	if ((data->flags >> TO_SHARP) % 2 && *num != '0')
		str[i++] = '0';
	if ((data->flags >> TO_SHARP) % 2 && (data->format[*k] == 'x' || data->format[*k] == 'X'))
		str[i++] = 'x';
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
/*
 * добавь обработку %u!!!!!!!!!!!!!!!!!!!!
 */
