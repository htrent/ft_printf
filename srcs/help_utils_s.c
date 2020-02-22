/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:59:34 by htrent            #+#    #+#             */
/*   Updated: 2020/02/12 20:44:42 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			help1_s(char *buf, int *prec, int *i, char *s)
{
	int j;

	j = 0;
	while ((*prec)--)
	{
		buf[(*i)++] = s[j];
		j++;
	}
}

int				init_s(t_printf *data, int *prec, int *n, char *s)
{
	int len;
	int max;

	len = ft_strlen(s);
	*prec = (data->precision == NO_PRECISION) ? len : data->precision;
	*n = (*prec < len) ? *prec : len;
	*prec = (*prec < len) ? *prec : len;
	max = (*n > data->width) ? *n : data->width;
	data->count_char += max;
	return (max);
}

void			help2_s(t_printf *data, int n, int *i, char *buf)
{
	while (data->width-- > n)
		buf[(*i)++] = ' ';
}

void			help3_s(t_printf *data, int n, int *i, char *buf)
{
	while (data->width-- > n)
		buf[(*i)++] = (data->flags >> TO_ZERO) % 2 ? '0' : ' ';
}
