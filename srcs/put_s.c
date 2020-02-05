/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/03 14:35:13 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	put_data_s(t_printf *data, int *k) //wchar_t * ????????????????????????
{
	char *s;
	int	flag;
	char *buf;
	int n;
	int max;
	int	width;
	int prec;
	int i;
	int len;

	flag = 0;
	s = (char *)va_arg(data->params, char *);
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		flag = 1;
	}
	width = data->width;
	len = ft_strlen(s);
	prec = (data->precision == NO_PRECISION) ? len : data->precision;
	n = (prec < len) ? prec : len;
	prec = (prec < len) ? prec : len;
	max = (n > data->width) ? n : data->width;
	data->count_char += max;
	buf = ft_strnew(max);
	i = 0;
	if ((data->flags >> TO_MINUS) % 2)
	{
		while (prec--)
			buf[i++] = *(s++);
		while (width-- > n)
			buf[i++] = ' ';
	}
	else
	{
		while (width-- > n)
			buf[i++] = (data->flags >> TO_ZERO) % 2 ? '0' : ' ';
		while (prec--)
			buf[i++] = *(s++);
	}
	ft_putstr_buf(buf, data->buf);
	free(buf);
	//if (flag)
	//	free(s);
	(*k)++;
	return (0);
}
