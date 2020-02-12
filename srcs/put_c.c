/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:57:43 by htrent            #+#    #+#             */
/*   Updated: 2020/02/12 20:44:00 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	action_c(int *width, char *s, int *i, intmax_t num)
{
	s[(*i)++] = num;
	while ((*width)-- > 1)
		s[(*i)++] = ' ';
}

int				init_c(t_printf *data, int *i)
{
	int			n;

	n = (data->width > 0) ? data->width : 1;
	data->count_char += n;
	*i = 0;
	return (n);
}

int				put_data_c(t_printf *data, int *k)
{
	intmax_t	num;
	char		*s;
	int			width;
	int			i;

	width = data->width;
	num = (data->size == L_SIZE) ? (wchar_t)va_arg(data->params, wint_t)
			: (char)va_arg(data->params, int);
	if (num == 0)
		return (put_data_zero_c(data, k));
	if (!(s = ft_strnew(init_c(data, &i))))
		return (1);
	if ((data->flags >> TO_MINUS) % 2 == 0)
	{
		while (width-- > 1)
			s[i++] = ((data->flags >> TO_ZERO) % 2) ? '0' : ' ';
		s[i] = num;
	}
	else
		action_c(&width, s, &i, num);
	ft_putstr_buf(s, data->buf, data);
	(*k)++;
	return (0);
}
