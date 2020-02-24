/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_exception.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 17:10:34 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_percent(t_printf *data)
{
	ft_putchar_buf('%', data->buf, data);
	data->count_char++;
}

int		put_data_exception(t_printf *data, int *k)
{
	if ((data->flags >> TO_MINUS) % 2)
	{
		ft_putchar_buf(data->format[*k], data->buf, data);
		data->count_char++;
		while (data->width-- > 1)
		{
			ft_putchar_buf(' ', data->buf, data);
			data->count_char++;
		}
	}
	else
	{
		while (data->width-- > 1)
		{
			ft_putchar_buf((data->flags >> TO_ZERO) % 2
			? '0' : ' ', data->buf, data);
			data->count_char++;
		}
		ft_putchar_buf(data->format[*k], data->buf, data);
		data->count_char++;
	}
	(*k)++;
	return (0);
}
