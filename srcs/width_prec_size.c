/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_prec_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:53:58 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 16:52:41 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			manage_width(t_printf *data, int *k)
{
	if ((ft_isdigit(data->format[*k])
	|| data->format[*k] == '*') && data->format[*k] != '\0')
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
		return (0);
	}
	return (1);
}

int			manage_precision(t_printf *data, int *k)
{
	if (data->format[*k] == '.')
	{
		(*k)++;
		if (data->format[*k] == '*')
		{
			data->precision = va_arg(data->params, int);
			if (data->precision < 0)
				data->precision = -1;
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
		return (0);
	}
	else if (data->precision == NO_PRECISION)
		data->precision = NO_PRECISION;
	return (1);
}

static int	help_manage_size(t_printf *data, int *k)
{
	if (data->format[*k] == 'h' && ((*k)++) && data->size <= H_SIZE)
		data->size = H_SIZE;
	else if (data->format[*k] == 'L' && ((*k)++) && data->size <= L_UPPER_SIZE)
		data->size = L_UPPER_SIZE;
	else if (data->format[*k] == 'j' && ((*k)++) && data->size <= J_SIZE)
		data->size = J_SIZE;
	else if (data->format[*k] == 'z' && ((*k)++) && data->size <= Z_SIZE)
		data->size = Z_SIZE;
	else if (ft_strchr("hLjz", data->format[*k]) == NULL)
		return (0);
	return (1);
}

int			manage_size(t_printf *data, int *k)
{
	if (data->format[*k])
	{
		if (data->format[*k] == 'l' && data->format[*k + 1]
		&& data->format[*k + 1] == 'l' && ((*k) += 2) && data->size <= LL_SIZE)
			data->size = LL_SIZE;
		else if (data->format[*k] == 'l' && ((*k)++) && data->size <= L_SIZE)
			data->size = L_SIZE;
		else if (data->format[*k] == 'h' && data->format[*k + 1]
		&& data->format[*k + 1] == 'h' && ((*k) += 2) && data->size <= HH_SIZE)
			data->size = HH_SIZE;
		else if (help_manage_size(data, k))
			return (0);
		else if (ft_strchr("diouxXfcspeg", data->format[*k]) != NULL
		&& data->size == 0)
			data->size = NO_SIZE;
		else if (ft_strchr("lhLjz", data->format[*k]) == NULL)
			return (1);
		return (0);
	}
	return (1);
}
