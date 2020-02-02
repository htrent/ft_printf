/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/02 17:31:49 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int 	put_data(t_printf *data, int *k)
{
	if (ft_strchr("cspdiouxX%", data->format[*k]) != NULL)
	{
		if (data->format[*k] == 'd' || data->format[*k] == 'i')
			put_data_di(data, k);
		else if (ft_strchr("ouxX", data->format[*k]) != NULL)
			put_data_ouxX(data, k);
		else if (data->format[*k] == 'p')
			put_data_p(data, k);
		else if (data->format[*k] == 'c')
			put_data_c(data, k);
		else if (data->format[*k] == 's')
			put_data_s(data, k);
		else if (data->format[*k] == '%')
				put_data_percent(data, k);
	}
	return (0);
}

int 	manage_var(t_printf *data, int *k) ///add errors if return 1!!!
{
	if (data->format[*k] == '%' && (*k)++)
		return (ft_put_percent(data));
	manage_flags(data, k);
	manage_width(data, k);
	if (manage_precision(data, k))
		return (1);
	manage_size(data, k);
	if (!put_data(data, k))
		return (0);
	//printf("\nflags:%d width:%d precision:%d size:%d \nformat:\"%s\"\n", data->flags, data->width, data->precision, data->size, &data->format[*k]);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_printf	data;
	int i;

	data = *(t_printf *)malloc(sizeof(t_printf));
	data.format = (char *)format;
	data.count_char = 0;
	i = 0;
	va_start(data.params, format);
	while (data.format[i])
	{
		if (data.format[i] == '%')
		{
			i++;
			manage_var(&data, &i);
		}
		else
		{
			data.count_char++;
			ft_putchar(format[i]);
			i++;
		}
//		i++;
	}
	va_end(data.params);
	return (data.count_char);
}