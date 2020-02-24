/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:12:21 by ffood             #+#    #+#             */
/*   Updated: 2020/02/24 17:54:58 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				put_data(t_printf *data, int *k)
{
	if (data->format[*k] && ft_strchr("csegfFpdiouUxXbBr",
	data->format[*k]) != NULL)
	{
		if (data->format[*k] == 'd' || data->format[*k] == 'i')
			put_data_di(data, k);
		else if (ft_strchr("ouUxXbB", data->format[*k]) != NULL)
			put_data_ouxb(data, k);
		else if (data->format[*k] == 'p')
			put_data_p(data, k);
		else if (data->format[*k] == 'c')
			put_data_c(data, k);
		else if (data->format[*k] == 's')
			put_data_s(data, k);
		else if (data->format[*k] == 'f')
			put_data_f(data, k);
		else if (data->format[*k] == 'r')
			put_data_r(data, k);
		return (0);
	}
	else if (data->format[*k] && ft_strchr("q \'\"", data->format[*k]) == NULL)
	{
		put_data_exception(data, k);
		return (0);
	}
	return (1);
}

void			help_manage_var(t_printf *data, int *k)
{
	int i;

	while (data->format[*k] && ft_strchr("csegfFpdiouUxXbB%",
	data->format[*k]) == NULL)
	{
		i = 0;
		if (data->format[*k] == '%' && (*k)++)
			return (ft_put_percent(data));
		if (manage_flags(data, k) == 0)
			i = 1;
		if (manage_width(data, k) == 0)
			i = 1;
		if (manage_precision(data, k) == 0)
			i = 1;
		if (manage_size(data, k) == 0)
			i = 1;
		if (!ft_is_flag(data->format[*k])
		&& !ft_is_size(data->format[*k]) && !ft_isdigit(data->format[*k])
		&& ft_strchr("*.%_'", data->format[*k]) == NULL)
			return ;
		if (i == 0 && data->format[*k])
			(*k)++;
	}
}

int				manage_var(t_printf *data, int *k)
{
	if (data->format[*k])
	{
		if (!(!ft_is_flag(data->format[*k]) && !ft_is_size(data->format[*k])
		&& !ft_isdigit(data->format[*k])
		&& ft_strchr("*._'", data->format[*k]) == NULL))
			help_manage_var(data, k);
		if (put_data(data, k))
			return (1);
		return (0);
	}
	return (1);
}
