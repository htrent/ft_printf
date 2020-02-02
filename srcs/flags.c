/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/02 12:21:46 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	solve_flags(t_printf *data, int *k)
{
	if (ft_strchr("#0+- ", data->format[*k]) != NULL)
	{
		while (ft_is_flag(data->format[*k]))
		{
			if (data->format[*k] == ' ' && data->flags >> TO_SPACE == 0)
				data->flags += F_SPACE;
			if (data->format[*k] == '#' && data->flags >> TO_SHARP == 0)
				data->flags += F_SHARP;
			if (data->format[*k] == '+' && data->flags >> TO_PLUS == 0)
				data->flags += F_PLUS;
			if (data->format[*k] == '-' && data->flags >> TO_MINUS == 0)
				data->flags += F_MINUS;
			if (data->format[*k] == '0' && data->flags >> TO_ZERO == 0)
				data->flags += F_ZERO;
			(*k)++;
		}
	}
}

void	manage_flags(t_printf *data, int *k)
{

	data->flags = NO_FLAGS;
	solve_flags(data, k);
}

