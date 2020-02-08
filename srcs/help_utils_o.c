/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:45:44 by htrent            #+#    #+#             */
/*   Updated: 2020/02/08 19:45:44 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	help_o_prec(t_printf *data, int *prec, int *width)
{
	if ((data->flags >> TO_MINUS) % 2)
	{
		while ((*prec)-- > 0)
			ft_putchar_buf('0', data->buf, data);
		while ((*width)-- > data->precision)
			ft_putchar_buf(' ', data->buf, data);
	}
	else
	{
		while ((*width)-- > data->precision)
			ft_putchar_buf(' ', data->buf, data);
		while ((*prec)-- > 0)
			ft_putchar_buf('0', data->buf, data);
	}
}

void	help_o_no_prec(t_printf *data, int *width)
{
	if ((data->flags >> TO_MINUS) % 2)
	{
		ft_putchar_buf('0', data->buf, data);
		while ((*width)-- > 1)
			ft_putchar_buf(' ', data->buf, data);
	}
	else
	{
		if ((data->flags >> TO_ZERO) % 2)
			while ((*width)-- > 1)
				ft_putchar_buf('0', data->buf, data);
		else
			while ((*width)-- > 1)
				ft_putchar_buf(' ', data->buf, data);
		ft_putchar_buf('0', data->buf, data);
	}
}
