/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:01:56 by htrent            #+#    #+#             */
/*   Updated: 2020/02/12 20:44:00 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_c_zero(t_printf *data, int *i, int *width)
{
	int		n;

	*width = data->width;
	n = (data->width > 1) ? data->width : 1;
	data->count_char += n;
	*i = 0;
	return (n);
}

int		put_data_zero_c(t_printf *data, int *k)
{
	char	*s;
	int		i;
	int		width;

	if (!(s = ft_strnew(init_c_zero(data, &i, &width))))
		return (1);
	if ((data->flags >> TO_MINUS) % 2 == 0)
	{
		while (width-- > 1)
			s[i++] = ((data->flags >> TO_ZERO) % 2) ? '0' : ' ';
		ft_putstr_buf(s, data->buf, data);
		ft_putchar_buf('\0', data->buf, data);
	}
	else
	{
		ft_putchar_buf('\0', data->buf, data);
		while (width-- > 1)
			s[i++] = ' ';
		ft_putstr_buf(s, data->buf, data);
	}
	(*k)++;
	return (0);
}
