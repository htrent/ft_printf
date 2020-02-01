/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/01 14:07:01 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <limits.h>
#include <stdio.h>

typedef	struct		s_printf
{
	va_list			params;
	char			*format;
	int 			flags;
	int		 		width;
	int				precision;
	int 			size;
	int 			count_char;
}					t_printf;

# define NO_PRECISION 0

# define NO_FLAGS	0  //00000
# define F_SHARP	1  //00001
# define F_ZERO		2  //00010
# define F_MINUS	4  //00100
# define F_PLUS		8  //01000
# define F_SPACE	16 //10000

# define TO_SHARP	0
# define TO_ZERO	1
# define TO_MINUS	2
# define TO_PLUS	3
# define TO_SPACE	4

# define NO_SIZE		0
# define L_SIZE			1
# define H_SIZE			2
# define LL_SIZE		3
# define HH_SIZE		4
# define L_UPPER_SIZE	5

# define MAX(a, b) (a > b) ? a : b

/*
 * SCHAR_MIN	SHRT_MIN	INT_MIN		LONG_MIN	LLONG_MIN
 * SCHAR_MAX	SHRT_MAX	INT_MAX		LONG_MAX	LLONG_MAX
 * UCHAR_MAX	USHRT_NAX	UINT_MAX	ULONG_MAX	ULLONG_MAX
 * CHAR_MIN		CHAR_MAX
 *
 *
 */

int 	ft_is_flag(char c)
{
	if (ft_strchr("#0+- ", c) != NULL)
		return (1);
	return (0);
}

int 	ft_is_size(char c)
{
	if ((c == 'l') || (*(&c + 1) && c == 'l' && *(&c + 1) == 'l') || (c == 'h') || (*(&c + 1) && c == 'h' && *(&c + 1) == 'h') || (c == 'L'))
		return (1);
	return (0);
}

void	solve_flags(t_printf *data, int *k) //to english
{
	if (ft_strchr("#0+- ", data->format[*k]) != NULL)
	{
		while (ft_is_flag(data->format[*k]))
		{
			if (data->format[*k] == ' ' && data->flags >> TO_SPACE == 0)
				data->flags += F_SPACE;
			if (data->format[*k] == '#' && data->flags >> TO_SHARP == 0)
				data->flags += F_SHARP;
			if (data->format[*k] == '+' && data->flags >> TO_PLUS == 0)
				data->flags += F_PLUS;
			if (data->format[*k] == '-' && data->flags >> TO_MINUS == 0)
				data->flags += F_MINUS;
			if (data->format[*k] == '0' && data->flags >> TO_ZERO == 0)
				data->flags += F_ZERO;
			(*k)++;
		}
	}
}

void	manage_flags(t_printf *data, int *k)
{

	data->flags = NO_FLAGS;
	solve_flags(data, k);
}

int	manage_width(t_printf *data, int *k)
{
	if (!ft_isdigit(data->format[*k]) && data->format[*k] != '*')
		data->width = 0;
	else
	{
		if (data->format[*k] == '*')
		{
			data->width = va_arg(data->params, int);
			(*k)++;
		}
		else
		{
			data->width = ft_atoi(&(data->format[*k]));
			while (ft_isdigit(data->format[*k]))
				(*k)++;
		}
	}
	return (0);
}

int	manage_precision(t_printf *data, int *k)
{
	if (data->format[*k] == '.')
	{
		(*k)++;
		if (data->format[*k] == '*')
		{
			data->precision = va_arg(data->params, int);
			(*k)++;
		}
		else if (ft_isdigit(data->format[*k]))
		{
			data->precision = ft_atoi(&(data->format[*k]));
			while (ft_isdigit(data->format[*k]))
				(*k)++;
		}
		else
			data->precision = 0;
	}
	else
		data->precision = NO_PRECISION;
	return (0);
}

int		manage_size(t_printf *data, int *k)
{
	if (data->format[*k] == 'l' && data->format[*k + 1] && data->format[*k + 1] == 'l' && ((*k)+=2))
		data->size = LL_SIZE;
	else if (data->format[*k] == 'l' && ((*k)++))
		data->size = L_SIZE;
	else if (data->format[*k] == 'h' && data->format[*k + 1] && data->format[*k + 1] == 'h' && ((*k)+=2))
		data->size = HH_SIZE;
	else if (data->format[*k] == 'h' && ((*k)++))
		data->size = H_SIZE;
	else if (ft_strchr("diouxXfcspeg", data->format[*k]) != NULL)
		data->size = NO_SIZE;
	else
		return (1);
	return (0);
}

int64_t	ft_pow_10(int n)
{
	int i;
	int64_t num;

	num = 1;
	i = 0;
	while (i < n)
	{
		num *= 10;
		i++;
	}
	return (num);
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
	i = 0;
	if (data->flags >> TO_SPACE == 1 && num >= 0 && (i = 1))
		s[0] = ' ';
	if (data->flags >> TO_PLUS == 1 && num >= 0 && (i = 1))
		s[0] = '+';
	if (num < 0 && (i = 1))
		s[0] = '-';
	while (prec > digits)
	{
		s[i++] = '0';
		prec--;
	}
	max = (digits > data->precision) ? digits : data->precision;
	while (dig > 0)
	{
		s[i++] = (num % ft_pow_10(dig)) / ft_pow_10(dig - 1) + '0';
		dig--;
	}
	j = (data->flags >> TO_PLUS == 1 || data->flags >> TO_SPACE == 1 || num < 0) ? 1 : 0;
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
	max += (data->flags >> TO_SPACE == 1 || data->flags >> TO_PLUS == 1 || num < 0) ? 1 : 0;
	i = 0;
	while (width > max)
	{
		s[i++] = ' ';
		width--;
	}
	if (data->flags >> TO_SPACE == 1 && num >= 0)
		s[i++] = ' ';
	if (data->flags >> TO_PLUS == 1 && num >= 0)
		s[i++] = '+';
	if (num < 0)
		s[i++] = '-';
	while (prec > dig)
	{
		s[i++] = '0';
		prec--;
	}
	j = (data->flags >> TO_PLUS == 1 || data->flags >> TO_SPACE == 1 || num < 0) ? 1 : 0;
	while (dig > 0)
	{
		s[i++] = (num % ft_pow_10(dig)) / ft_pow_10(dig - 1) + '0';
		dig--;
	}
	ft_putstr(s);
	free(s);
}

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
	if (data->flags >> TO_SPACE == 1 || data->flags >> TO_PLUS == 1)
		n++;
	n = (n > data->width) ? n : data->width;
	data->count_char += n;
	s = ft_strnew(n);
	if (data->flags >> TO_MINUS == 1)
		ft_fillbegin(data, num, s, digits);
	else
		ft_fillend(data, num, s, digits);
	(*k)++;
	return (0);
}

int 	put_data_percent(t_printf *data, int *k)
{
	if (data->flags >> TO_MINUS)
	{
		ft_putchar('%');
		data->count_char++;
		while (data->width-- > 1)
		{
			ft_putchar(' ');
			data->count_char++;
		}
	}
	else
	{
		while (data->width-- > 1)
		{
			ft_putchar(' ');
			data->count_char++;
		}
		ft_putchar('%');
		data->count_char++;
	}
	(*k)++;
	return (0);
}

int 	put_data_ouxX(t_printf *data, int *k)
{
	uint64_t num;
	char *s;
	int n;
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


	if (data->format[*k] == 'o')
		s = ft_utoa_base(num, 8);
	if (data->format[*k] == 'x' || data->format[*k] == 'X')
		s = ft_utoa_base(num, 16);
	digits = ft_strlen(s);
	if (data->format[*k] == 'X')
		s = ft_str_to_upper(s);
	n = (data->precision > )
	printf("\"%s\"", s);
	/*digits = ft_count_of_digits(num);
	n = (digits > data->precision) ? digits : data->precision;
	if (data->flags >> TO_SPACE == 1 || data->flags >> TO_PLUS == 1)
		n++;
	n = (n > data->width) ? n : data->width;
	data->count_char += n;
	s = ft_strnew(n);
	if (data->flags >> TO_MINUS == 1)
		ft_fillbegin(data, num, s, digits);
	else
		ft_fillend(data, num, s, digits);
	(*k)++;*/
	return (0);
}

int 	put_data(t_printf *data, int *k)
{
	if (ft_strchr("diouxX", data->format[*k]) != NULL)
	{
		if (data->format[*k] == 'd' || data->format[*k] == 'i')
			put_data_di(data, k);
		if (ft_strchr("ouxX", data->format[*k]) != NULL)
			put_data_ouxX(data, k);
	}
	if (data->format[*k] == '%')
		put_data_percent(data, k);
	return (0);
}

int ft_put_percent(t_printf *data)
{
	ft_putchar('%');
	data->count_char++;
	return (0);
}

int 	manage_var(t_printf *data, int *k) ///add errors if return 1!!!
{
	if (data->format[*k] == '%' && (*k)++)
		return (ft_put_percent(data));
	manage_flags(data, k);
	manage_width(data, k);
	if (manage_precision(data, k))
		return (1);
	manage_size(data, k);
	put_data(data, k);
	//printf("\nflags:%d width:%d precision:%d size:%d \nformat:\"%s\"\n", data->flags, data->width, data->precision, data->size, &data->format[*k]);
	return (0);
}

int	ft_printf(const char * restrict format, ...)
{
	t_printf	data;
	int i;

	data = *(t_printf *)malloc(sizeof(t_printf));
	data.format = (char *)format;
	data.count_char = 0;
	i = 0;
	va_start(data.params, format);
	while (data.format[i])
	{
		if (data.format[i] == '%')
		{
			i++;
			manage_var(&data, &i);
		}
		else
		{
			data.count_char++;
			ft_putchar(format[i++]);
		}
	}
	va_end(data.params);
	return (data.count_char);
}