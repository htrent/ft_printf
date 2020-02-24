/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 16:53:00 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				put_data_s(t_printf *data, int *k)
{
	char	*s;
	char	*buf;
	int		n;
	int		i;
	int		prec;

	s = (char *)va_arg(data->params, char *);
	if (s == NULL)
		return (put_data_s_null(data, k));
	if (!(buf = ft_strnew(init_s(data, &prec, &n, s))))
		return (1);
	i = 0;
	((data->flags >> TO_MINUS) % 2) ? help1_s(buf, &prec, &i, s)
	: help3_s(data, n, &i, buf);
	((data->flags >> TO_MINUS) % 2) ? help2_s(data, n, &i, buf)
	: help1_s(buf, &prec, &i, s);
	ft_putstr_buf(buf, data->buf, data);
	(*k)++;
	return (0);
}

int				put_data_s_null(t_printf *data, int *k)
{
	char	*s;
	char	*buf;
	int		n;
	int		i;
	int		prec;

	s = ft_strdup("(null)");
	buf = ft_strnew(init_s(data, &prec, &n, s));
	i = 0;
	if ((data->flags >> TO_MINUS) % 2)
	{
		help1_s(buf, &prec, &i, s);
		while (data->width-- > n)
			buf[i++] = ' ';
	}
	else
	{
		while (data->width-- > n)
			buf[i++] = (data->flags >> TO_ZERO) % 2 ? '0' : ' ';
		help1_s(buf, &prec, &i, s);
	}
	ft_putstr_buf(buf, data->buf, data);
	free(s);
	(*k)++;
	return (0);
}
