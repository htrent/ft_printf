/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:54:03 by htrent            #+#    #+#             */
/*   Updated: 2020/02/07 13:43:30 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_flags(t_printf *data, int *k)
{
	if (data->flags == 32)
		data->flags = NO_FLAGS;
	if (ft_strchr("#0+- ", data->format[*k]) != NULL)
	{
		while (ft_is_flag(data->format[*k]))
		{
			if (data->format[*k] == ' ' && (data->flags >> TO_SPACE) % 2 == 0)
				data->flags += F_SPACE;
			if (data->format[*k] == '#' && (data->flags >> TO_SHARP) % 2 == 0)
				data->flags += F_SHARP;
			if (data->format[*k] == '+' && (data->flags >> TO_PLUS) % 2 == 0)
				data->flags += F_PLUS;
			if (data->format[*k] == '-' && (data->flags >> TO_MINUS) % 2 == 0)
				data->flags += F_MINUS;
			if (data->format[*k] == '0' && (data->flags >> TO_ZERO) % 2 == 0)
				data->flags += F_ZERO;
			(*k)++;
		}
		return (0);
	}
	return (1);
}
