/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:57:43 by htrent            #+#    #+#             */
/*   Updated: 2020/02/06 15:19:08 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	put_data_c(t_printf *data, int *k)
{
	intmax_t num;
	char	*s;
	int n;
	int	width;
	int i;

	width = data->width;
	if (data->size == L_SIZE)
		num = (wchar_t)va_arg(data->params, wint_t);
	else
		num = (char)va_arg(data->params, int);
	//if (num == 0)
	//	return (put_data_zero_c(data, k));
	n = (data->width > 0) ? data->width : 1;
	s = ft_strnew(n);
	data->count_char += n;
	i = 0;
	if ((data->flags >> TO_MINUS) % 2 == 0)
	{
		while (width-- > 1)
			s[i++] = ((data->flags >> TO_ZERO) % 2) ? '0' : ' ';
		s[i] = num;
	}
	else
	{
		s[i++] = num;
		while (width-- > 1)
			s[i++] = ' ';
	}
	ft_putstr_buf(s, data->buf);
	free(s);
	(*k)++;
	return (0);
}
/*
int		put_data_zero_c(t_printf *data, int *k)
{
	int n;
	char *s;
	int i;
	int	width;

	width = data->width;
	n = (data->width > 1) ? data->width : 1;
	s = ft_strnew(n);
	data->count_char += n;
	i = 0;
	if ((data->flags >> TO_MINUS) % 2 == 0)
	{
		while (width-- > 1)
			s[i++] = ((data->flags >> TO_ZERO) % 2) ? '0' : ' ';
		s[i++] = '^';
		s[i] = '@';
	}
	else
	{
		s[i++] = '^';
		s[i++] = '@';
		while (width-- > 1)
			s[i++] = ' ';
	}
	ft_putstr_buf(s, data->buf);
	free(s);
	(*k)++;
	return (0);
}*/