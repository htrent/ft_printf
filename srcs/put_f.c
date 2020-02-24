/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:04:21 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 15:26:02 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rounding_off_2(char *big_num1, char *big_num2, t_printf *data)
{
	int j;
	int flag;

	flag = 0;
	j = NUM_SIZE - 1;
	big_num2[0] = big_num2[0] % 10;
	if (big_num1[j] + 1 > 9)
		flag = 1;
	if (!(data->precision == 0 && big_num2[0] == 5 && big_num2[1] == -1
	&& big_num1[NUM_SIZE - 1] % 2 == 0))
		big_num1[j] = (big_num1[j] < 0) ? 1 : big_num1[j] + 1;
	while (flag && j)
	{
		big_num1[j] = big_num1[j] % 10;
		big_num1[j - 1] = (big_num1[j - 1] < 0) ? 1 : big_num1[j - 1] + 1;
		flag = (big_num1[j - 1] > 9) ? 1 : 0;
		j--;
	}
}

static void	rounding_off(char *big_num1, char *big_num2, t_printf *data)
{
	int i;
	int flag;

	flag = 0;
	i = data->precision - 1;
	if (big_num2[i + 1] >= 5 && data->precision > 0)
	{
		if (big_num2[i] + 1 > 9)
			flag = 1;
		if (!(big_num2[i] == 2
		&& big_num2[i + 1] == 5 && big_num2[i + 2] == -1))
			big_num2[i]++;
	}
	while (flag && i)
	{
		big_num2[i] = big_num2[i] % 10;
		big_num2[i - 1]++;
		flag = (big_num2[i - 1] > 9) ? 1 : 0;
		i--;
	}
	if (flag || (data->precision == 0 && big_num2[0] >= 5))
		rounding_off_2(big_num1, big_num2, data);
}

static void	print_f(t_printf *data, char *big_num1, char *big_num2)
{
	int		j;
	int		k;

	k = 0;
	j = NUM_SIZE - 1;
	data->precision = (data->precision == -1) ? 6 : data->precision;
	if (big_num1[NUM_SIZE - 1] == -1)
		big_num1[NUM_SIZE - 1]++;
	rounding_off(big_num1, big_num2, data);
	while (big_num1[j] != -1)
		j--;
	data->len_num1 = NUM_SIZE - 1 - j;
	if ((data->flags >> TO_PLUS) % 2 || (data->flags >> TO_SPACE) % 2
	|| big_num1[0] == 1)
		data->len_num1++;
	if (data->precision + data->len_num1 + 1 > data->width)
		k = data->precision + data->len_num1 + 1;
	else
		k = data->width;
	k = (data->precision == 0 && (data->flags >> TO_SHARP) % 2 == 0
	&& data->width == 0) ? k - 1 : k;
	ft_fill(data, big_num1, big_num2, k);
}

static void	nan_inf(union u_number	number)
{
	if (number.bits.e == 32767)
	{
		if (number.bits.m == 0x8000000000000000 && number.bits.s == 0)
			write(1, "inf", 3);
		else if (number.bits.m == 0x8000000000000000 && number.bits.s == 1)
			write(1, "-inf", 4);
		else
			write(1, "nan", 3);
		exit(0);
	}
}

int			put_data_f(t_printf *data, int *k)
{
	union u_number	number;
	char			big_num1[NUM_SIZE];
	char			big_num2[NUM_SIZE];
	int				i;
	int				e;

	ft_memset(big_num1, -1, NUM_SIZE);
	ft_memset(big_num2, -1, NUM_SIZE);
	number.num = data->size == L_UPPER_SIZE ? (long double)
	va_arg(data->params, long double) : (double)va_arg(data->params, double);
	nan_inf(number);
	if (number.bits.s == 1)
		big_num1[0] = 1;
	i = -1;
	e = number.bits.e - 16383;
	while (++i < 64)
	{
		if (e - i < 0 && ((number.bits.m >> (63 - i)) & 1))
			add_pow_five(big_num2, -(e - i));
		else if (e - i >= 0 && ((number.bits.m >> (63 - i)) & 1))
			add_pow_two(big_num1, e - i);
	}
	print_f(data, big_num1, big_num2);
	(*k)++;
	return (0);
}
