/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:53:39 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 17:19:12 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*init_data(const char *format, int *a)
{
	t_printf	*data;
	int			i;

	i = 0;
	*a = 0;
	if (!(data = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	data->format = (char *)format;
	data->count_char = 0;
	data->flags = 32;
	data->size = 0;
	data->precision = -1;
	data->width = 0;
	data->count_buf = 0;
	ft_bzero(data->buf, BUFF_SIZE);
	return (data);
}

static void		reinit_data(t_printf *data)
{
	data->flags = 32;
	data->size = 0;
	data->precision = -1;
	data->width = 0;
}

static int		ret_value(t_printf *data)
{
	int i;

	ft_putstr_pft(data->buf, data);
	i = data->count_char;
	free(data);
	return (i);
}

int				ft_printf(const char *format, ...)
{
	t_printf	*data;
	int			i;

	if (!(data = init_data(format, &i)))
		return (0);
	va_start(data->params, format);
	while (data->format[i])
	{
		if (data->format[i] == '%')
		{
			i++;
			reinit_data(data);
			if (data->format[i] == '\0' || manage_var(data, &i))
				break ;
		}
		else if (data->format[i] == '{' && manage_color(data, &i))
			continue ;
		else
		{
			data->count_char++;
			ft_putchar_buf(format[i++], data->buf, data);
		}
	}
	va_end(data->params);
	return (ret_value(data));
}
