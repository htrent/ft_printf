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

int	manage_width(t_printf *data, int *k)
{
	if (!ft_isdigit(data->format[*k]) && data->format[*k] != '*')
		data->width = 0;
	else
	{
		if (data->format[*k] == '*')
		{
			data->width = va_arg(data->params, int);
			if (data->width < 0)
			{
				data->width *= -1;
				data->flags += F_MINUS;
			}
			(*k)++;
		}
		else
		{
			data->width = ft_atoi(&(data->format[*k]));
			while (ft_isdigit(data->format[*k]))
				(*k)++;
		}
	}
	return (0);
}

int	manage_precision(t_printf *data, int *k)
{
	if (data->format[*k] == '.')
	{
		(*k)++;
		if (data->format[*k] == '*')
		{
			data->precision = va_arg(data->params, int);
			(*k)++;
		}
		else if (ft_isdigit(data->format[*k]))
		{
			data->precision = ft_atoi(&(data->format[*k]));
			while (ft_isdigit(data->format[*k]))
				(*k)++;
		}
		else
			data->precision = 0;
	}
	else
		data->precision = NO_PRECISION;
	return (0);
}

int		manage_size(t_printf *data, int *k)
{
	if (data->format[*k] == 'l' && data->format[*k + 1] && data->format[*k + 1] == 'l' && ((*k)+=2))
		data->size = LL_SIZE;
	else if (data->format[*k] == 'l' && ((*k)++))
		data->size = L_SIZE;
	else if (data->format[*k] == 'h' && data->format[*k + 1] && data->format[*k + 1] == 'h' && ((*k)+=2))
		data->size = HH_SIZE;
	else if (data->format[*k] == 'h' && ((*k)++))
		data->size = H_SIZE;
	else if (ft_strchr("diouxXfcspeg", data->format[*k]) != NULL)
		data->size = NO_SIZE;
	else
		return (1);
	return (0);
}
