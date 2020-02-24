/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:08:55 by ffood             #+#    #+#             */
/*   Updated: 2020/02/24 14:19:56 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	float_fillbegin(t_printf *data, char *big_num1, char *big_num2,
char *s)
{
	int j;
	int i;

	i = 0;
	j = NUM_SIZE - 1;
	if (big_num1[0] == 1)
		s[i] = '-';
	else if ((data->flags >> TO_PLUS) % 2)
		s[i] = '+';
	else if ((data->flags >> TO_SPACE) % 2 && big_num1[0] != 1)
		s[i] = ' ';
	i += data->len_num1;
	while (big_num1[j] != -1 && j >= 0)
		s[--data->len_num1] = big_num1[j--] + '0';
	if (data->precision != 0 || (data->precision == 0 &&
	(data->flags >> TO_SHARP) % 2))
		s[i++] = '.';
	j = -1;
	while (++j < data->precision)
		s[i++] = (big_num2[j] == -1) ? '0' : big_num2[j] + '0';
	while (i < data->width)
		s[i++] = ' ';
	ft_putstr_buf(s, data->buf, data);
}

static void	if_flags(t_printf *data, char *big_num1, char *s, int k)
{
	int i;

	i = k - 1;
	if ((data->flags >> TO_ZERO) % 2)
		while (k >= 0)
			s[--k] = '0';
	else
		while (k >= 0)
			s[--k] = ' ';
	k = ((data->flags >> TO_ZERO) % 2) ? 0 : i;
	if (big_num1[0] == 1)
		s[k] = '-';
	else if ((data->flags >> TO_PLUS) % 2)
		s[k] = '+';
	else if ((data->flags >> TO_SPACE) % 2 && big_num1[0] != 1)
		s[k] = ' ';
}

static void	float_fillend(t_printf *data, char *big_num1, char *big_num2,
char *s)
{
	int j;
	int i;
	int k;

	i = NUM_SIZE - 1;
	j = data->precision - 1;
	k = data->len_num1_2;
	while (j >= 0)
	{
		s[--k] = (big_num2[j] == -1) ? '0' : big_num2[j] + '0';
		j--;
	}
	if (data->precision != 0 || (data->precision == 0 &&
	(data->flags >> TO_SHARP) % 2))
		s[--k] = '.';
	while (big_num1[i] != -1 && i >= 0)
		s[--k] = big_num1[i--] + '0';
	if_flags(data, big_num1, s, k);
	ft_putstr_buf(s, data->buf, data);
}

void		ft_fill(t_printf *data, char *big_num1, char *big_num2, int k)
{
	char	*s;

	s = ft_strnew(k);
	data->len_num1_2 = k;
	if ((data->flags >> TO_MINUS) % 2)
		float_fillbegin(data, big_num1, big_num2, s);
	else
		float_fillend(data, big_num1, big_num2, s);
	data->count_char += k;
}
